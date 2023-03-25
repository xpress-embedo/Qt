#include "test.h"

Test::Test(QObject *parent)
  : QObject{parent}
{
  qInfo() << this << "Constructed";
}

Test::~Test( void )
{
  qInfo() << this << "Deconstructed";
}

void Test::doStuff( void )
{
  qInfo() << this << Q_FUNC_INFO;
}
