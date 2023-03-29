#include "test.h"

Test::Test(QObject *parent)
  : QObject{parent}
{
  qInfo() <<this << "Constructed";
}

void Test::testing()
{
  qWarning() << "This is for Testing";
}
