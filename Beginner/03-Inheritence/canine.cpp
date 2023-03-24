#include "canine.h"

Canine::Canine(QObject *parent)
  : Mammal{parent}
{
  qDebug() << this << " Constructed";
}
