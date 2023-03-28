#include "toy.h"

Toy::Toy(QObject *parent, QString name) : QObject{parent}
{
  setObjectName(name);
  qInfo() << "Constructed" << this;
}

Toy::~Toy( void )
{
  qInfo() << "Deconstructed" << this;
}
