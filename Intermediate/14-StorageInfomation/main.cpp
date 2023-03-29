#include <QCoreApplication>
#include <QStorageInfo>
#include <QFileInfo>
#include <QDir>
#include <QDebug>

/*QStorageClass provides information about currently mounted storage & drive*/

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QStorageInfo root = QStorageInfo::root();
  qInfo() << "Root:" << root.rootPath();

  QDir dir(root.rootPath());

  foreach( QFileInfo fi, dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot) )
  {
    qInfo() << fi.filePath();
  }

  foreach( QStorageInfo storage, QStorageInfo::mountedVolumes() )
  {
    qInfo() << "-------------";
    qInfo() << "Name:     " << storage.displayName();
    qInfo() << "Type:     " << storage.fileSystemType();
    qInfo() << "Total:    " << storage.bytesTotal()/1000/1000 << "MB";
    qInfo() << "Available:" << storage.bytesAvailable()/1000/1000 << "MB";
    qInfo() << "Device:   " << storage.device();
    qInfo() << "Root:     " << storage.isRoot();
  }

  return a.exec();
}
