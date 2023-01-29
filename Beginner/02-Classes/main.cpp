#include <QCoreApplication>
#include "animal.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Animal cat;
  Animal dog;
  Animal fish;

  // setObjectName is in-built method, and is a part of Q_OBJECT
  cat.setObjectName("Kitty");
  dog.setObjectName("Fido");
  fish.setObjectName("Nemo");

  cat.Speak( "meow" );
  dog.Speak( "bark" );
  fish.Speak( "blablabla" );

  return a.exec();
}
