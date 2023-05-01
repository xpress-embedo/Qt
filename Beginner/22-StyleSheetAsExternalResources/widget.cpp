
#include "widget.h"
#include "./ui_widget.h"
#include "suredialog.h"

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



void Widget::on_btnSubmit_clicked()
{
  SureDialog *dialog = new SureDialog(this);
  dialog->exec();
}

