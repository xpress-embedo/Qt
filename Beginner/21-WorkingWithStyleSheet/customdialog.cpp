#include "customdialog.h"
#include "ui_customdialog.h"

CustomDialog::CustomDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::CustomDialog)
{
  ui->setupUi(this);
  // Set Style Sheet on specific widget
  ui->pushButton_2->setStyleSheet("background-color: indianred; color: white");
}

CustomDialog::~CustomDialog()
{
  delete ui;
}
