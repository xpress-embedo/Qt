#include "ftpmanager.h"
#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTime>

FTPManager::FTPManager(QObject *parent)
  : QObject{parent}
{

}

void FTPManager::downloadFTPData()
{
  // Always use fresh series for this run
  // Donot delete the old ones here; old/chart widget cleanup handles previous ownership
  m_data1 = new QLineSeries(this);
  m_data2 = new QLineSeries(this);

  // Download the data from the FTP server
  QString program = "C:/Windows/System32/curl.exe";
  QStringList arguments =
  {
    "--ftp-ssl",
    "--insecure",
    "ftp://xpress:embedo@localhost/ftpserver/logs.txt",
    "-o",
    "logs.txt"
  };

  QProcess process;
  process.start(program, arguments);
  process.waitForFinished();

  qDebug() << "STDOUT:" << process.readAllStandardOutput();
  qDebug() << "STDERR:" << process.readAllStandardError();
  qDebug() << "Exit code:" << process.exitCode();

  if (process.exitCode() == 0)
  {
    qDebug() << "Download successful";
  }
  else
  {
    qDebug() << "Download failed";
  }

  // Save the data received from the FTP Server into a file
  QFile file("logs.txt");
  if( !file.open(QIODevice::ReadOnly) )
  {
    qDebug() << "Not able to open the files";
  }
  else
  {
    // Safety Guard: Ensure data series are initialized before appending data points.
    if ( m_data1 == nullptr || m_data2 == nullptr )
    {
      qDebug() << "Series not initialized";
      return;
    }

    // We are here because file is present
    QTextStream stream(&file);
    QDateTime datetime = QDateTime::currentDateTime();

    // Lets read from the file
    while( !stream.atEnd() )
    {
      QString line = stream.readLine();
      QStringList values = line.split(',');
      qDebug() << values;
      QDateTime parsed = QDateTime::fromString(values[0], "yyyy-MM-dd HH:mm:ss");
      datetime = parsed;
      // add time and data1 to the series
      m_data1->append( datetime.toMSecsSinceEpoch(), values[1].toUInt() );
      // add time and data2 to the series
      m_data2->append( datetime.toMSecsSinceEpoch(), values[2].toUInt() );
    }
    // now we can close the file as the file end has reached
    file.close();

    // now we have to update the data to chart
  }
}
