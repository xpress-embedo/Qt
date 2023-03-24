#ifndef CANINE_H
#define CANINE_H

#include <QObject>
#include "mammal.h"

class Canine : public Mammal
{
  Q_OBJECT
public:
  explicit Canine(QObject *parent = nullptr);

  void bark( void )
  {
    qInfo() << "Bark";
  }

signals:

};

#endif // CANINE_H
