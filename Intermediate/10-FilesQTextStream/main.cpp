#include <QCoreApplication>
#include <QFile>
#include <QTextStream>

void write( QFile &file )
{
  if( !file.isWritable() )
  {
    qInfo() << "Unable to Write to File!";
    return;
  }
  QTextStream stream(&file);
  // Set Encoding
  stream.setEncoding(QStringConverter::LastEncoding);
  // moving to the end of the file, this is similar to the appending of the file
  stream.seek(file.size());
  for( int idx=0; idx<5; idx++ )
  {
    stream << QString::number(idx) << "-Item\r\n";
  }
  // Push the Stream
  stream.flush();
  qInfo() << "File Written";
}

void read( QFile &file )
{
  if( !file.isReadable() )
  {
    qInfo() << "Unable to Read from File!";
    return;
  }

  QTextStream stream(&file);
  stream.seek(0);
  while( !stream.atEnd() )
  {
    qInfo() << stream.readLine();
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString filename = "test.txt";

  QFile file(filename);
  if( file.open(QIODevice::ReadWrite) )
  {
    QTextStream stream(&file);
    // get the encoding of the file
    qInfo() << "Encoding:" << stream.encoding();
    write( file );
    read( file );
    file.close();
  }
  else
  {
    qInfo() << file.errorString();
  }

  return a.exec();
}
