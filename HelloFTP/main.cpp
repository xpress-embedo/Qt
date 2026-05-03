
/* Reference Videos
 * https://www.youtube.com/watch?v=KX1v05HsoAo&list=PLh0cogPqXcJMwB5xyLE2cpp39DcSQ1lY6&index=6
 * TODO
 */
#include "mainwindow.h"

#include <QApplication>
#include <QProcess>
#include <QDebug>

void downloadFromFTP()
{
  QString program = "C:/Windows/System32/curl.exe";
  QStringList arguments = {
      "--ftp-ssl",
      "--insecure",
      "ftp://xpress:embedo@localhost/ftpserver/hello.txt",
      "-o",
      "downloaded.txt"
  };

  QProcess process;
  process.start(program, arguments);
  process.waitForFinished();

  qDebug() << "STDOUT:" << process.readAllStandardOutput();
  qDebug() << "STDERR:" << process.readAllStandardError();
  qDebug() << "Exit code:" << process.exitCode();

  if (process.exitCode() == 0)
      qDebug() << "Download successful";
  else
      qDebug() << "Download failed";
}


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MainWindow w;

  downloadFromFTP();

  w.show();
  return a.exec();
}
