#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QBuffer>
#include <QTextStream>

bool makeFile( QString path )
{
  QFile file(path);
  if( file.open(QIODevice::WriteOnly) )
  {
    QByteArray data;
    for( int idx=0; idx<1000; idx++ )
    {
      data.append(QString::number(idx).toUtf8() + "\r\n" );
    }
    file.write(data);
    file.close();
    return true;
  }
  else
  {
    return false;
  }
}

QByteArray getHeader( void )
{
  QByteArray header;
  header.append("@!~!@");
  return header;
}

bool compressFile(QString originalFile, QString newFile )
{
  QFile ofile(originalFile);
  QFile nfile(newFile);

  QByteArray header = getHeader();
  if( !ofile.open(QIODevice::ReadOnly) )  return false;
  if( !nfile.open(QIODevice::WriteOnly) ) return false;
  int size = 1024;

  while( !ofile.atEnd() )
  {
    QByteArray buffer = ofile.read(size);
    QByteArray compressed = qCompress( buffer, 9);
    nfile.write(header);
    nfile.write(compressed);
  }
  ofile.close();
  nfile.close();
  qInfo() << "Finished Compressing";
  return true;
}

bool decompressFile(QString originalFile, QString newFile )
{
  QFile ofile(originalFile);
  QFile nfile(newFile);

  QByteArray header = getHeader();
  if( !ofile.open(QIODevice::ReadOnly) )  return false;
  if( !nfile.open(QIODevice::WriteOnly) ) return false;
  int size = 1024;

  // Make sure we created this file
  QByteArray buffer = ofile.peek(size);
  if( !buffer.startsWith(header) )
  {
    qCritical() << "We didn't create this file.";
    ofile.close();
    nfile.close();
    return false;
  }

  // Find the header position
  ofile.seek( header.length() );

  while( !ofile.atEnd() )
  {
    buffer = ofile.peek(size);
    qint64 index = buffer.indexOf(header);
    qDebug() << "Head Found at: " << index;
    if( index > -1 )
    {
      // We found a header
      qint64 maxbytes = index;
      qInfo() << "Reading :" << maxbytes;
      buffer = ofile.read(maxbytes);
      ofile.read(header.length());
    }
    else
    {
      // Don't have the header
      qInfo() << "Read all no Header";
      buffer = ofile.readAll();
    }

    QByteArray decompress = qUncompress(buffer);
    nfile.write(decompress);
    nfile.flush();
  }
  ofile.close();
  nfile.close();
  qInfo() << "Finished Decompressing";
  return true;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString originalFile = "original.txt";
  QString compressedFile = "compressed.txt";
  QString decompressedFile = "decompressed.txt";

  if( makeFile(originalFile) )
  {
    qInfo() << "Original Created";
    if( compressFile( originalFile, compressedFile) )
    {
      qInfo() << "File Compressed";
      if( decompressFile(compressedFile, decompressedFile) )
      {
        qInfo() << "File Decompressed";
      }
      else
      {
        qInfo() << "File Couldn't Decompressed";
      }
    }
    else
    {
      qInfo() << "File Couldn't Compressed";
    }
  }

  return a.exec();
}
