#include "infodialog.h"
#include "ui_infodialog.h"

InfoDialog::InfoDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::InfoDialog)
{
  ui->setupUi(this);
}

InfoDialog::~InfoDialog()
{
  delete ui;
}

void InfoDialog::on_btnCancel_clicked()
{
  // Cancel is pressed, the dialog is rejected
  reject();
}


void InfoDialog::on_btnOK_clicked()
{
  QString userPosition = ui->lineEditPosition->text();
  // Get the Data from the Line Edit widget and copy it into the private string
  if( !userPosition.isEmpty() )
  {
    position = userPosition;
    // Also collect the favorite OS selected
    if( ui->rbWindows->isChecked() )
    {
      favoriteOS = "Windows";
    }
    if( ui->rbMacOs->isChecked() )
    {
      favoriteOS = "MAC";
    }
    if( ui->rbLinux->isChecked() )
    {
      favoriteOS = "Linux";
    }
  }

  // This is OK button and the intention is to close the dialog and come back to
  // the previous main screen, this is done by calling accept()
  accept();
}

QString InfoDialog::getFavoriteOS() const
{
  return favoriteOS;
}

QString InfoDialog::getPosition() const
{
  return position;
}

