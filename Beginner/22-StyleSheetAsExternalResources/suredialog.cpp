#include "suredialog.h"
#include "ui_suredialog.h"

SureDialog::SureDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::SureDialog)
{
  ui->setupUi(this);
}

SureDialog::~SureDialog()
{
  delete ui;
}

void SureDialog::on_btnOK_clicked()
{
  accept();
}


void SureDialog::on_btnCancel_clicked()
{
  reject();
}

