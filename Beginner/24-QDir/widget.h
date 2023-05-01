
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

private slots:
  void on_btnChooseDir_clicked();

  void on_btnCreateDir_clicked();

  void on_btnDirExist_clicked();

  void on_btnDirOrFile_clicked();

  void on_btnFolderContent_clicked();

private:
  Ui::Widget *ui;
};

#endif // WIDGET_H
