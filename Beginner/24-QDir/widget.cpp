
#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
}

Widget::~Widget()
{
  delete ui;
}


//This Slot get name of the selected directory and display it on the line edit widget
void Widget::on_btnChooseDir_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, "Choose Folder");
  if( dir.isEmpty() )
  {
    return;
  }

  ui->lineEdit->setText( dir );
}


void Widget::on_btnCreateDir_clicked()
{
  // Create a directory if it doesn't exist already
  QString dirPath = ui->lineEdit->text();
  if( dirPath.isEmpty() )
  {
    return;
  }
  QDir dir(dirPath);
  // Check if directory exists
  if( !dir.exists() )
  {
    // Directory doesn't exist create one
    if( dir.mkpath(dirPath) )
    {
      QMessageBox::information( this, "Message", "Directory Created");
    }
  }
  else
  {
    // Directory doesn't exist, infor user using message box
    QMessageBox::information( this, "Message", "Directory already Exists");
  }
}


void Widget::on_btnDirExist_clicked()
{
  // Check if Directory Exists
  QString dirPath = ui->lineEdit->text();
  if( dirPath.isEmpty() )
  {
    return;
  }
  QDir dir(dirPath);
  // Check if directory exists
  if( dir.exists() )
  {
    QMessageBox::information( this, "Message", "Directory Exist");
  }
  else
  {
    // Directory doesn't exist, inform user using message box
    QMessageBox::information( this, "Message", "Directory Doesn't Exists");
  }
}


void Widget::on_btnDirOrFile_clicked()
{
  QFileInfo fileInfo( ui->listWidget->currentItem()->text() );
  if( fileInfo.isDir() )
  {
    QMessageBox::information( this, "Message", "This is a directory." );
  }
  else if( fileInfo.isFile() )
  {
    QMessageBox::information( this, "Message", "This is a file." );
  }
  else
  {
    QMessageBox::information( this, "Message", "This is something else." );
  }
}


void Widget::on_btnFolderContent_clicked()
{
  ui->listWidget->clear();
  // Check if this is a directory or a file
  QString dirPath = ui->lineEdit->text();
  if( dirPath.isEmpty() )
  {
    return;
  }

  QDir dir(dirPath);
  // Get the list of files and directories in the folder
  QList<QFileInfo> fileList = dir.entryInfoList();
  for( int idx=0; idx<fileList.size(); idx++ )
  {
    /* // This code is for debugging to append the file and dir as prefix
    QString prefix;
    if( fileList.at(idx).isFile() )
    {
      prefix = "FILE : ";
    }
    if( fileList.at(idx).isDir() )
    {
      prefix = "DIR : ";
    }
    ui->listWidget->addItem( prefix+fileList.at(idx).absoluteFilePath() );
    */
    ui->listWidget->addItem( fileList.at(idx).absoluteFilePath() );
  }
}

