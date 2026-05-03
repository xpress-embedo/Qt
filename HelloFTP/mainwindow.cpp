#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProcess>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_btnDownload_clicked()
{
  this->downloadFromFTP();
}

void MainWindow::downloadFromFTP()
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
  {
    qDebug() << "Download successful";
  }
  else
  {
    qDebug() << "Download failed";
  }
}

