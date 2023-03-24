#include "mammal.h"

Mammal::Mammal(QObject *parent)
  : Animal{parent}
{
  qDebug() << this << " Constructed";
}
