#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>

class Test : public QObject
{
  Q_OBJECT
public:
  Test();

  // Normal Function
  int number();
signals:

public slots:
  void bark();

};

#endif // TEST_H
