#include <QCoreApplication>

#include "feline.h"
#include "canine.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Canine dog;
  dog.bark();
  qInfo() << dog.hasBackBone();


  Feline cat;
  cat.meow();

  return a.exec();
}
