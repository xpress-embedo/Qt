
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

  /*
  // METHOD-1: SHOW THE DIALOG MODEL
  // show this using execute method
  // NOTE: This exec method shows the dialog as model dialog, blocking it until
  // the user closes it.
  int response = dialog->exec();
  // Response is used to check if the Dialog is Accepted or Rejected
  if( response == QDialog::Accepted )
  {
    qDebug() << "Dialog Accepted";
    qDebug() << "Position: " << dialog->getPosition();
    qDebug() << "Favorite OS: " << dialog->getFavoriteOS();
  }
  else
  {
    qDebug() << "Dialog Rejected";
  }
  */

  // METHOD-2: SHOW THE DIALOG NON MODEL
  connect( dialog, &InfoDialog::accepted, [=](){
    qDebug() << "Dialog Accepted";
    qDebug() << "Position: " << dialog->getPosition();
    qDebug() << "Favorite OS: " << dialog->getFavoriteOS();
  });

  connect( dialog, &InfoDialog::rejected, [=](){
    qDebug() << "Dialog Rejected";
  });
  dialog->show();
  dialog->raise();
  dialog->activateWindow();
}

