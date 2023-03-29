#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

bool write( QString filename )
{
  QFile file(filename);
  if( !file.open(QIODevice::WriteOnly) )
  {
    qInfo() << file.errorString();
    return false;
  }

  QDataStream stream(&file);
  stream.setVersion(QDataStream::Qt_DefaultCompiledVersion);

  int age=45;
  QString name = "Bryan";
  double weight = 185.06;

  stream << age << name << weight;

  if( !file.flush() )
  {
    qInfo() << file.errorString();
    file.close();
    return false;
  }

  qInfo() << "Files Written";

  file.close();
  return true;
}

bool read( QString filename )
{
  QFile file(filename);
  if( !file.open(QIODevice::ReadOnly) )
  {
    qInfo() << file.errorString();
    return false;
  }

  QDataStream stream(&file);
  if( stream.version() != QDataStream::Qt_DefaultCompiledVersion )
  {
    qInfo() << "Wrong file Version";
    file.close();
    return false;
  }

  int age;
  QString name;
  double weight;

  qInfo() << "Reading File";
  stream >> age >> name >> weight;
  file.close();

  qInfo() << "Name" << name;
  qInfo() << "Age:" << age;
  qInfo() << "Weight:" << weight;

  // file.close();  // file close can be done here but it's better to do it above
  // as file is a resource and it is not a good thing to block a resource when
  // not needed
  return true;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString filename = "test.txt";
  if( write(filename) )
  {
    read(filename);
  }

  return a.exec();
}
