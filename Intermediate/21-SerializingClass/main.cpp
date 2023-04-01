#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include "test.h"

bool saveFile( Test *t, QString path )
{
  QFile file(path);
  if( !file.open(QIODevice::WriteOnly) )  return false;

  QDataStream ds(&file);
  ds.setVersion( QDataStream::Qt_DefaultCompiledVersion );

  // IMPORTANT: This will call the operator in the test class
  ds << *t;

  file.close();
  return true;
}

bool loadFile( QString path )
{
  QFile file(path);
  if( !file.open(QIODevice::ReadOnly) )  return false;

  QDataStream ds(&file);
  if( ds.version() != QDataStream::Qt_DefaultCompiledVersion )
  {
    qCritical() << "Bad Version";
    file.close();
    return false;
  }

  Test t;
  ds >> t;

  file.close();
  qInfo() << "Name: " << t.name();
  foreach (QString key, t.map().keys() )
  {
    qInfo() << key << ":" << t.map().value(key);
  }
  return true;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString path = "test.txt";

  Test t;
  t.fill();
  if( saveFile( &t, path) )
  {
    loadFile( path );
  }

  return a.exec();
}
