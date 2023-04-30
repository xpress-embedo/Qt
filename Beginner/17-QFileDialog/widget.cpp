
#include "widget.h"
#include "./ui_widget.h"
#include <QFileDialog>

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



void Widget::on_pushButton_clicked()
{
  /* // Open a Directory Dialog
  QString dir = QFileDialog::getExistingDirectory( this, tr("Open Directory"), \
                                                   "/home", \
                                                   QFileDialog::ShowDirsOnly|QFileDialog::DontResolveSymlinks );
  qDebug() << "Directory Selected is: " << dir;
  */

  /* // Open a File Dialog
  QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"), \
                                                   "/home",\
                                                   tr("Image (*.png *.xpm *.jpg") );
  qDebug() << "File Selected is: " << fileName;
  */

  // Select Multiple Files
  QStringList files = QFileDialog::getOpenFileNames( this, \
                                                     "Select one or more files to open", \
                                                     "/home", \
                                                     "Images (*.png *.xpm *.jpg);;Text files (*.txt);;XML files (*.xml)");
  qDebug() << "Files Selected are: " << files;

}

