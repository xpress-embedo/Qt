#ifndef INFODIALOG_H
#define INFODIALOG_H

#include <QDialog>

namespace Ui {
class InfoDialog;
}

class InfoDialog : public QDialog
{
  Q_OBJECT

public:
  explicit InfoDialog(QWidget *parent = nullptr);
  ~InfoDialog();

private slots:
  void on_btnCancel_clicked();

  void on_btnOK_clicked();

private:
  Ui::InfoDialog *ui;
  QString position;
  QString favoriteOS;
};

#endif // INFODIALOG_H
