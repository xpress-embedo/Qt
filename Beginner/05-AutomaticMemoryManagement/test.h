#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
  Q_OBJECT
public:
  explicit Test(QObject *parent = nullptr);
  ~Test( void );

  void doStuff( void );

signals:

};

#endif // TEST_H
