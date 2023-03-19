#include "dirhelper.h"

DirHelper::DirHelper(QObject *parent)
  : QObject{parent}
{

}

QString DirHelper::path()
{
  return dir.path();
}

void DirHelper::setPath(QString value)
{
  dir.setPath(value);
}

QStringList DirHelper::files()
{
  QFileInfoList list = dir.entryInfoList( QDir::AllEntries | QDir::NoDotAndDotDot | QDir::Files );
  QStringList filelist;

  foreach (QFileInfo info, list)
  {
    filelist.append( info.filePath() );
  }
  return filelist;
}
