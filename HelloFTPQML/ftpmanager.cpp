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
  m_series1.clear();
  m_series2.clear();

  // Download Command Line
  // curl --ftp-ssl --insecure ftp://abc:abc@localhost/ftp/logs.txt

  // Download the data from the FTP server
  QString program = "C:/Windows/System32/curl.exe";
  QStringList arguments =
  {
    "--ftp-ssl",
    "--insecure",
    "ftp://abc:abc@localhost/ftp/logs.txt",
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
    // Save the data received from the FTP Server into a file
    QFile file("logs.txt");
    if( !file.open(QIODevice::ReadOnly) )
    {
      qDebug() << "Not able to open the files";
    }
    else
    {
      // We are here because file is present
      QTextStream stream(&file);
      QDateTime datetime = QDateTime::currentDateTime();

      // Lets read from the file
      while( !stream.atEnd() )
      {
        QVariantMap point1;
        QVariantMap point2;

        QString line = stream.readLine();
        QStringList values = line.split(',');
        qDebug() << values;
        QDateTime parsed = QDateTime::fromString(values[0], "yyyy-MM-dd HH:mm:ss");
        datetime = parsed;
        // build point maps
        point1["x"] = datetime.toMSecsSinceEpoch();
        point1["y"] = (double)values[1].toUInt();
        m_series1.append(point1);

        // build point map for series2
        point2["x"] = datetime.toMSecsSinceEpoch();
        point2["y"] = (double)values[2].toUInt();
        m_series2.append(point2);
      }
      // now we can close the file as the file end has reached
      file.close();

      // now we have to update the data to chart
      emit dataReady();
    }
  }
  else
  {
    qDebug() << "Download failed";
  }
}
