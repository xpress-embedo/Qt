#include "laptop.h"
#include <QDebug>

Laptop::Laptop(QObject *parent, QString name)
  : QObject{parent}
{
  qInfo() << this << " Constructor " << name;
}

Laptop::~Laptop( void )
{
  qInfo() << this << " Deconstructor " << name;
}

double Laptop::asKilo( void )
{
  // convert pounds to kilograms
  return weight * 0.453592;
}

void Laptop::test( void )
{
  qInfo() << this << " Test: " << name << " Kilo: " << asKilo();
}
