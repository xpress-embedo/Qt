#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

void list( QDir &root )
{
  qInfo() << "-----Listing-----";
  foreach( QFileInfo file, root.entryInfoList(QDir::Filter::Dirs, QDir::Name) )
  {
    if( file.isDir() )
    {
      qInfo() << file.absoluteFilePath();
    }
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QDir dir(QCoreApplication::applicationDirPath());
  qInfo() << dir.dirName();       // Relative Path
  qInfo() << dir.absolutePath();  // Absolute Path/ Complete Path

  dir.cdUp();   // one directory up
  qInfo() << dir.absolutePath();

  list(dir);

  // Make a folder
  dir.mkdir("test_folder");
  list(dir);

  // Delete the folder (directory must be empty), use dir.rmpath
  dir.rmdir("test_folder");
  list(dir);

  return a.exec();
}
