#include "test.h"

Test::Test()
{

}

int Test::number()
{
  qInfo() << "Called number()";
  // return a number
  return 42;
}

void Test::bark()
{
  qInfo() << "Bark Bark Bark";
}
