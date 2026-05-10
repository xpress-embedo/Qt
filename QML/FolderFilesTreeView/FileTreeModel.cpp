#include "FileTreeModel.h"

#include <QDir>
#include <QFileInfo>

FileTreeModel::FileTreeModel(QObject *parent)
  : QAbstractItemModel(parent),
    m_root(std::make_unique<Node>())
{
  // This is an internal invisible root (not shown in TreeView).
  // Top-level folders/files under sourcePath become its children.
  m_root->name = QStringLiteral("root");
  m_root->isDir = true;
}

FileTreeModel::~FileTreeModel() = default;

QModelIndex FileTreeModel::index(int row, int column, const QModelIndex &parentIndex) const
{
  // Qt calls this to ask: "Give me an index for (row, column) under parentIndex".
  if (!hasIndex(row, column, parentIndex)) {
    return QModelIndex();
  }

  Node *parentNode = nodeFromIndex(parentIndex);
  if (!parentNode) {
    return QModelIndex();
  }

  if (row < 0 || row >= static_cast<int>(parentNode->children.size())) {
    return QModelIndex();
  }

  // We store a raw Node* in QModelIndex.internalPointer().
  // Ownership stays with unique_ptr inside the tree.
  return createIndex(row, column, parentNode->children.at(static_cast<size_t>(row)).get());
}

QModelIndex FileTreeModel::parent(const QModelIndex &child) const
{
  // Qt calls this to navigate upward in the tree.
  if (!child.isValid()) {
    return QModelIndex();
  }

  auto *childNode = static_cast<Node *>(child.internalPointer());
  if (!childNode || !childNode->parent || childNode->parent == m_root.get()) {
    return QModelIndex();
  }

  Node *parentNode = childNode->parent;
  Node *grandParent = parentNode->parent;
  if (!grandParent) {
    return QModelIndex();
  }

  int row = 0;
  const auto &siblings = grandParent->children;
  for (size_t i = 0; i < siblings.size(); ++i) {
    if (siblings.at(i).get() == parentNode) {
      row = static_cast<int>(i);
      break;
    }
  }

  return createIndex(row, 0, parentNode);
}

int FileTreeModel::rowCount(const QModelIndex &parentIndex) const
{
  // Tree has only one column. Children are listed by rows.
  if (parentIndex.column() > 0) {
    return 0;
  }

  Node *parentNode = nodeFromIndex(parentIndex);
  if (!parentNode) {
    return 0;
  }

  return static_cast<int>(parentNode->children.size());
}

int FileTreeModel::columnCount(const QModelIndex &) const
{
  return 1;
}

QVariant FileTreeModel::data(const QModelIndex &index, int role) const
{
  // Returns data for a given row/column and role requested by QML/Qt.
  if (!index.isValid()) {
    return QVariant();
  }

  auto *node = static_cast<Node *>(index.internalPointer());
  if (!node) {
    return QVariant();
  }

  switch (role) {
    case Qt::DisplayRole:
    case FileNameRole:
      return node->name;
    case FilePathRole:
      return node->path;
    case IsDirectoryRole:
      return node->isDir;
    default:
      return QVariant();
  }
}

QHash<int, QByteArray> FileTreeModel::roleNames() const
{
  // Custom role names that QML can access as model.fileName / model.isDirectory etc.
  auto roles = QAbstractItemModel::roleNames();
  roles[FileNameRole] = "fileName";
  roles[FilePathRole] = "filePath";
  roles[IsDirectoryRole] = "isDirectory";
  return roles;
}

QString FileTreeModel::sourcePath() const
{
  return m_sourcePath;
}

void FileTreeModel::setSourcePath(const QString &path)
{
  if (m_sourcePath == path) {
    return;
  }

  m_sourcePath = path;
  emit sourcePathChanged();
  reload();
}

void FileTreeModel::reload()
{
  // Model reset tells Qt views that complete tree content is about to change.
  beginResetModel();

  m_root->children.clear();

  if (!m_sourcePath.isEmpty()) {
    // Read only top-level entries here; each entry is then expanded recursively by buildTree().
    QDir sourceDir(m_sourcePath);
    const QFileInfoList entries = sourceDir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot,
                                                           QDir::DirsFirst | QDir::Name);

    for (const QFileInfo &entry : entries) {
      // buildTree() returns unique_ptr; we transfer ownership into children with std::move.
      auto child = buildTree(entry.absoluteFilePath(), m_root.get());
      if (child) {
        m_root->children.push_back(std::move(child));
      }
    }
  }

  endResetModel();
}

std::unique_ptr<FileTreeModel::Node> FileTreeModel::buildTree(const QString &path, Node *parent) const
{
  // Recursive directory traversal:
  // 1) create node for current path
  // 2) if node is directory, recurse into each child entry
  const QFileInfo info(path);
  if (!info.exists()) {
    return nullptr;
  }

  auto node = std::make_unique<Node>();
  node->name = info.fileName().isEmpty() ? info.absoluteFilePath() : info.fileName();
  node->path = info.absoluteFilePath();
  node->isDir = info.isDir();
  node->parent = parent;

  if (!node->isDir) {
    return node;
  }

  QDir dir(path);
  const QFileInfoList entries = dir.entryInfoList(QDir::AllEntries | QDir::NoDotAndDotDot,
                                                  QDir::DirsFirst | QDir::Name);

  for (const QFileInfo &entry : entries) {
    auto child = buildTree(entry.absoluteFilePath(), node.get());
    if (child) {
      node->children.push_back(std::move(child));
    }
  }

  return node;
}

FileTreeModel::Node *FileTreeModel::nodeFromIndex(const QModelIndex &index) const
{
  // Invalid index means caller is asking about the invisible root.
  if (!index.isValid()) {
    return m_root.get();
  }

  return static_cast<Node *>(index.internalPointer());
}
