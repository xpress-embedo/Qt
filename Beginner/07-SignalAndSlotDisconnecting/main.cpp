#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>

#include "radio.h"
#include "station.h"

using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Radio boombox;
  Station * channels[3];

  // Create Some Stations
  channels[0] = new Station(&boombox, 94, "Rock and Roll");
  channels[1] = new Station(&boombox, 87, "Hip Hop");
  channels[2] = new Station(&boombox, 104, "News");

  boombox.connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit, Qt::QueuedConnection );

//  for( int idx=0; idx<3; idx++ )
//  {
//    Station * channel = channels[idx];
//    boombox.connect(channel, &Station::send, &boombox, &Radio::listen );
//  }

  do
  {
    qInfo() << "Enter on, off, test or quit";
    QTextStream qtin(stdin);
    QString line = qtin.readLine().trimmed().toUpper();

    if( line == "ON" )
    {
      qInfo() << "Turning the Radio On";
      for( int idx=0; idx<3; idx++ )
      {
        Station * channel = channels[idx];
        boombox.connect(channel, &Station::send, &boombox, &Radio::listen );
      }
      qInfo() << "Radio is On";
    }

    if( line == "OFF" )
    {
      qInfo() << "Turning the Radio Off";
      for( int idx=0; idx<3; idx++ )
      {
        Station * channel = channels[idx];
        // this is how we disconnect
        boombox.disconnect(channel, &Station::send, &boombox, &Radio::listen );
      }
      qInfo() << "Radio is Off";
    }

    if( line == "TEST" )
    {
      qInfo() << "Testing";
      for( int idx=0; idx<3; idx++ )
      {
        Station * channel = channels[idx];
        channel->broadcast("Broadcasting Live!");
      }
      qInfo() << "Test is Finished";
    }

    if( line == "QUIT" )
    {
      qInfo() << "Quitting";
      emit boombox.quit();
      break;
    }

  } while(true);

  return a.exec();
}
