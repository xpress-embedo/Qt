#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QDebug>

// file.readAll is not a great option, as bigger files can create a problem
// hence break the problem into smaller parts QFile:readline & QFile::read
void readLines( QFile &file )
{
  // if file is not readable, exit the function
  if( !file.isReadable() )
  {
    return;
  }
  // start from the start of the file
  file.seek(0);

  while( !file.atEnd() )
  {
    qInfo() << file.readLine();   // this keeps looking for \n
  }
}

void readChunks( QFile &file )
{
  // if file is not readable, exit the function
  if( !file.isReadable() )
  {
    return;
  }
  // start from the start of the file
  file.seek(0);
  while( !file.atEnd() )
  {
    qInfo() << file.read(38);   // reading x bytes at a time
  }
}

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

  qInfo() << "Reading the file";
  qInfo() << "Exists:" << file.exists();

  // Reading File Content all at once
  if( file.open(QIODevice::ReadOnly) )
  {
    // Read the entire file (use cautiously, big files takes time, & can crash)
    qInfo() << file.readAll();
    file.close();
  }
  else
  {
    // Unable to open the file in reading mode, print the error
    qInfo() << file.errorString();
  }

  // Reading (large) files line by line
  qInfo() << "Reading File Line by Line";
  if( file.open(QIODevice::ReadOnly) )
  {
    // read line by line
    readLines(file);
    file.close();
  }
  else
  {
    // Unable to open the file in reading mode, print the error
    qInfo() << file.errorString();
  }

  // Reading (large) files chunks by chunks
  qInfo() << "Reading File Chunks by Chunks";
  if( file.open(QIODevice::ReadOnly) )
  {
    // Read file chunks by chunks
    readChunks(file);
    file.close();
  }
  else
  {
    // Unable to open the file in reading mode, print the error
    qInfo() << file.errorString();
  }

  return a.exec();
}
