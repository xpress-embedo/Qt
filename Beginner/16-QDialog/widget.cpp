
#include "widget.h"
#include "./ui_widget.h"
#include "infodialog.h"

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



void Widget::on_btnProvideInfo_clicked()
{
  // Create an Object of the dialog
  InfoDialog *dialog = new InfoDialog(this);
  // show this using execute method
  /* NOTE: This exec method shows the dialog as model dialog, blocking it until
  the user closes it. */
  dialog->exec();
}

