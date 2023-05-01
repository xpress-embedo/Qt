
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QNetworkAccessManager>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget

{
  Q_OBJECT

public:
  Widget(QWidget *parent = nullptr);
  ~Widget();

public slots:
  void dataReadyToRead( void );
  void dataReadFinished( void );

private:
  Ui::Widget *ui;
  QNetworkAccessManager *netManager;
  QNetworkReply *netReply;
  QByteArray *mDataBuffer;
};

#endif // WIDGET_H
