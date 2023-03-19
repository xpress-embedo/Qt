#include <QCoreApplication>
#include "animal.h"
#include "laptop.h"

// Passing by Reference
void test( Laptop &machine )
{
  machine.test();
}

void makeLaptops( void )
{
  Laptop mine(nullptr, "My Laptop");
  Laptop yours(nullptr, "Your Laptop");

  mine.weight = 3;
  yours.weight = 5;

  test(mine);
  test(yours);

  // will be deleted from the stack (automatically)
  // because this function will go out of scope
  // and this will call the deconstructor function also
}

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

  makeLaptops();

  return a.exec();
}
