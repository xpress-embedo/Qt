
#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  // Retrieve the Palette for the Label
  QPalette palette = ui->label->palette();
  ui->label->setAutoFillBackground( true );   // can also be set from UI

  // Modify the Palette with our changes
  palette.setColor(QPalette::Window, Qt::red );     // Make Sure setAutoFillBackground is set to true
  palette.setColor(QPalette::WindowText, Qt::blue );

  // Reset the Palette to the widget
  ui->label->setPalette(palette);
}

Widget::~Widget()
{
  delete ui;
}



void Widget::on_btnActive_clicked()
{
  QPalette::ColorGroup activeButtonColorGroup = ui->btnActive->palette().currentColorGroup();
  QPalette::ColorGroup disabledButtonColorGroup = ui->btbDisabled->palette().currentColorGroup();

  qDebug() << "Active Button Color Group: " << activeButtonColorGroup;
  qDebug() << "Disable Button Color Group: " << disabledButtonColorGroup;
}

