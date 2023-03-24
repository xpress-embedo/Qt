#ifndef MAMMAL_H
#define MAMMAL_H

#include <QObject>
#include "animal.h"

class Mammal : public Animal
{
  Q_OBJECT
public:
  explicit Mammal(QObject *parent = nullptr);

  bool hasBackBone( void )
  {
    return true;
  }

signals:

};

#endif // MAMMAL_H
