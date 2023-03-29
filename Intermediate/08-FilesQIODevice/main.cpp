#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

/*
 * QIODevice is the base "interface" class of all I/O Devices.
 * (Here Interface signifies that this class can't be instantiated)
 * QBuffer class provided a QIODevice interface for a QByteArray
*/

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QBuffer buffer;

  if( buffer.open(QIODevice::OpenModeFlag::ReadWrite) )
  {
    QByteArray data("Hello World");
    qInfo() << "Device is Open";
    // Write the data 5 times
    for( int idx=0; idx<5; idx++ )
    {
      buffer.write(data);
      buffer.write("\r\n");   // New Line CRLF (Windows) and is acceptable in other OS
    }
    // buffer.flush();
    qInfo() << "Device Writing is Complete";

    // Now let's read
    buffer.seek(0);   // this set's the reading pointer to initial state
    qInfo() << buffer.readAll();


    qInfo() << "Closing the Device";
    // Once we open, we should close also
    buffer.close();
  }
  else
  {
    qInfo() << "Couldn't open the device";
  }

  return a.exec();
}
