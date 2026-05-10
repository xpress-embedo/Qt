#pragma once

#include <QAbstractItemModel>
#include <QString>

#include <memory>
#include <vector>

class FileTreeModel : public QAbstractItemModel
{
  Q_OBJECT
  Q_PROPERTY(QString sourcePath READ sourcePath WRITE setSourcePath NOTIFY sourcePathChanged)

public:
  enum Roles {
    FileNameRole = Qt::UserRole + 1,
    FilePathRole,
    IsDirectoryRole
  };

  explicit FileTreeModel(QObject *parent = nullptr);
  ~FileTreeModel() override;

  QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
  QModelIndex parent(const QModelIndex &child) const override;
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
  QHash<int, QByteArray> roleNames() const override;

  QString sourcePath() const;
  void setSourcePath(const QString &path);

signals:
  void sourcePathChanged();

private:
  // One node represents either one directory or one file.
  // children owns child nodes using unique_ptr (single-owner tree).
  struct Node {
    QString name;
    QString path;
    bool isDir = false;
    Node *parent = nullptr;
    std::vector<std::unique_ptr<Node>> children;
  };

  void reload();
  std::unique_ptr<Node> buildTree(const QString &path, Node *parent) const;
  Node *nodeFromIndex(const QModelIndex &index) const;

  std::unique_ptr<Node> m_root;
  QString m_sourcePath;
};
