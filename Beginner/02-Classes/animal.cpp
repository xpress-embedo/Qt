#include "animal.h"
#include <QDebug>

Animal::Animal(QObject *parent)
  : QObject{parent}
{
  qInfo() << this << " Constructed";
}

void Animal::Speak(QString message)
{
  qInfo() << this << message;
}
