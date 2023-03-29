#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include <QDebug>

void list( QString path )
{
  qInfo() << "List:" << path;

  QDir dir(path);
  QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot );
  QFileInfoList files = dir.entryInfoList(QDir::Files);

  foreach(QFileInfo file, dirs )
  {
    qInfo() << file.fileName();
  }

  foreach(QFileInfo file, files )
  {
    qInfo() << "..Name:         " << file.fileName();
    qInfo() << "...Size:        " << file.size();
    qInfo() << "....Created:    " << file.birthTime();
    qInfo() << ".....Modfied:   " << file.lastModified();
  }

  foreach(QFileInfo file, dirs )
  {
    list( file.absoluteFilePath() );
  }

}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  list(QDir::tempPath()); // temp path is temporary directory

  return a.exec();
}
