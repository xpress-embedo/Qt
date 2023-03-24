#include "feline.h"

Feline::Feline(QObject *parent)
  : Mammal{parent}
{
  qDebug() << this << " Constructed";
}
