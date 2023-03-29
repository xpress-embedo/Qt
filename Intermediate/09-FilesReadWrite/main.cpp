#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  const QString filename = "test.txt";

  QFile file(filename);
  // if( file.open(QIODevice::WriteOnly) )    // this will always overwrite the file
  if( file.open(QIODevice::Append) )          // this will append the file
  {
    QString now = QDateTime::currentDateTime().toString();
    QByteArray data;
    data.append( now.toLocal8Bit() );
    data.append("-");
    data.append("Hello World");

    file.write(data);
    file.write("\r\n");
    // file.flush()   // no need to do this as file.close will automatically do this

    // close the final
    file.close();

    qInfo() << "Wrote to the file";
  }
  else
  {
    // Unable to open the file in writing mode, print the error
    qInfo() << file.errorString();
  }

  return a.exec();
}
