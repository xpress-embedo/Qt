
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QColor>
#include <QList>
#include <QPushButton>

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
  void on_pushButton_1_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_5_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_7_clicked();

  void on_pushButton_8_clicked();

  void on_pushButton_9_clicked();

  void on_btnSaveColors_clicked();

  void on_btnLoadColors_clicked();

private:
  Ui::Widget *ui;
  QList<QColor> colorList;

  void saveColor( QString key, QColor color);
  QColor loadColor( QString key );

  void setLoadedColor( QString key, int index, QPushButton *button );
};

#endif // WIDGET_H
