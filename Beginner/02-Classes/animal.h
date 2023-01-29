#ifndef ANIMAL_H
#define ANIMAL_H

#include <QObject>

class Animal : public QObject
{
  Q_OBJECT
public:
  explicit Animal(QObject *parent = nullptr);
  void Speak( QString message );

signals:

};

#endif // ANIMAL_H
