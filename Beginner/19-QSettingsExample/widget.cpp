/* NOTE: This is an another example of QSettings, two are available in
 * intermediate folder.*/
#include "widget.h"
#include "./ui_widget.h"
#include <QColorDialog>
#include <QSettings>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  for( int idx; idx<9; idx++ )
  {
    colorList.append(Qt::black);
  }
}

Widget::~Widget()
{
  delete ui;
}



void Widget::on_pushButton_1_clicked()
{
  QColor color = QColorDialog::getColor( colorList[0], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[0] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_1->setStyleSheet(css);
  }
}


void Widget::on_pushButton_2_clicked()
{
  QColor color = QColorDialog::getColor( colorList[1], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[1] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_2->setStyleSheet(css);
  }
}


void Widget::on_pushButton_3_clicked()
{
  QColor color = QColorDialog::getColor( colorList[2], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[2] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_3->setStyleSheet(css);
  }
}

void Widget::on_pushButton_4_clicked()
{
  QColor color = QColorDialog::getColor( colorList[3], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[3] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_4->setStyleSheet(css);
  }
}

void Widget::on_pushButton_5_clicked()
{
  QColor color = QColorDialog::getColor( colorList[4], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[4] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_5->setStyleSheet(css);
  }
}

void Widget::on_pushButton_6_clicked()
{
  QColor color = QColorDialog::getColor( colorList[5], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[5] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_6->setStyleSheet(css);
  }
}

void Widget::on_pushButton_7_clicked()
{
  QColor color = QColorDialog::getColor( colorList[6], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[6] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_7->setStyleSheet(css);
  }
}

void Widget::on_pushButton_8_clicked()
{
  QColor color = QColorDialog::getColor( colorList[7], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[7] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_8->setStyleSheet(css);
  }
}

void Widget::on_pushButton_9_clicked()
{
  QColor color = QColorDialog::getColor( colorList[8], this, "Choose the background color" );
  if( color.isValid() )
  {
    // Save the color in the list in memory
    colorList[8] = color;

    // Set the background color
    QString css = QString("background-color : %1").arg(color.name());
    ui->pushButton_9->setStyleSheet(css);
  }
}


void Widget::on_btnSaveColors_clicked()
{
  saveColor( "Button1", colorList[0] );
  saveColor( "Button2", colorList[1] );
  saveColor( "Button3", colorList[2] );
  saveColor( "Button4", colorList[3] );
  saveColor( "Button5", colorList[4] );
  saveColor( "Button6", colorList[5] );
  saveColor( "Button7", colorList[6] );
  saveColor( "Button8", colorList[7] );
  saveColor( "Button9", colorList[8] );
}


void Widget::on_btnLoadColors_clicked()
{
  setLoadedColor("Button1", 0, ui->pushButton_1 );
  setLoadedColor("Button2", 1, ui->pushButton_2 );
  setLoadedColor("Button3", 2, ui->pushButton_3 );
  setLoadedColor("Button4", 3, ui->pushButton_4 );
  setLoadedColor("Button5", 4, ui->pushButton_5 );
  setLoadedColor("Button6", 5, ui->pushButton_6 );
  setLoadedColor("Button7", 6, ui->pushButton_7 );
  setLoadedColor("Button8", 7, ui->pushButton_8 );
  setLoadedColor("Button9", 8, ui->pushButton_9 );
}

void Widget::saveColor(QString key, QColor color)
{
  int red = color.red();
  int green = color.green();
  int blue = color.blue();

  QSettings settings("Embedded", "Settings Demo");
  settings.beginGroup("Button Color");
  settings.setValue( key + "r", red );
  settings.setValue( key + "g", green );
  settings.setValue( key + "b", blue );
  settings.endGroup();
}

QColor Widget::loadColor(QString key)
{
  int red, green, blue;
  QSettings settings("Embedded", "Settings Demo");
  settings.beginGroup("Button Color");
  red = settings.value( key + "r", QVariant(0) ).toInt();
  green = settings.value( key + "g", QVariant(0) ).toInt();
  blue = settings.value( key + "b", QVariant(0) ).toInt();
  settings.endGroup();
  return QColor(red, green, blue);
}

void Widget::setLoadedColor(QString key, int index, QPushButton *button)
{
  QColor color = loadColor(key);
  colorList[index] = color;
  // Set the background color
  QString css = QString("background-color : %1").arg(color.name());
  button->setStyleSheet(css);
}

