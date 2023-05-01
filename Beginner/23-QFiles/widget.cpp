
#include "widget.h"
#include "./ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
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



void Widget::on_btnWrite_clicked()
{
  // Save the file to disk
  QString filename = QFileDialog::getSaveFileName( this, "Save As");
  if( filename.isEmpty() )
  {
    return;
  }

  QFile file( filename );
  // Open the file
  if( !file.open(QIODevice::WriteOnly | QIODevice::Text| QIODevice::Append) )
  {
    return;
  }

  QTextStream out(&file);
  // Write the content
  out << ui->textEdit->toPlainText() << "\n";
  // Close the file
  file.close();
}


void Widget::on_btnRead_clicked()
{
  // Open the file
  QString filename = QFileDialog::getOpenFileName( this, "Open File");
  if( filename.isEmpty() )
  {
    return;
  }

  QFile file( filename );
  // Open the file
  if( !file.open(QIODevice::ReadOnly | QIODevice::Text) )
  {
    return;
  }

  QTextStream in(&file);
  // First Clear the content and then Read the content and update on the TextEdit
  ui->textEdit->clear();
  ui->textEdit->setPlainText( in.readAll() );
  // Close the file
  file.close();
}

/*
 * The purpose of these two slots is to get the filename or let's say select the
 * file and when copy button is pressed, the content of the file is copied to the
 * another file specified in the line edit widget */
void Widget::on_btnSelectFile_clicked()
{
  QString filename = QFileDialog::getOpenFileName(this, "Choose File");
  if( filename.isEmpty() )
  {
    // Nothing is selected
    return;
  }
  ui->lineEditSelectFile->setText( filename );
}

void Widget::on_btnCopy_clicked()
{
  // get the name of both the files
  QString sourceFileName = ui->lineEditSelectFile->text();
  QString destinationFileName = ui->lineEditCopy->text();

  // check both shouldn't be empty
  if( sourceFileName.isEmpty() || destinationFileName.isEmpty() )
  {
    // one or both filename is empty, exit from here
    return;
  }

  QFile file( sourceFileName );
  if( file.copy( destinationFileName) )
  {
    QMessageBox::information( this, "Success", "Copy Successful");
  }
  else
  {
    QMessageBox::information( this, "Failed", "Copy Failed");
  }
}

