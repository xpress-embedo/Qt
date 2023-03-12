#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QVariant>
#include <QDebug>

class Test : public QObject
{
  Q_OBJECT
public:
  Test();

  // Normal Function
  int number();

signals:
  void notice( QVariant data );

private slots:
  void timeout();
public slots:
  void bark();
  void start();
  void stop();

private:
  QTimer m_timer;
  QString m_display;

};

#endif // TEST_H
