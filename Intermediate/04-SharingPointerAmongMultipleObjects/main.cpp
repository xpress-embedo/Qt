#include <QCoreApplication>
#include <QSharedPointer>
#include "cat.h"
#include "toy.h"
#include <vector>

void test( void )
{
  int max = 5;
  // QSharedPointer<Toy> toy(new Toy());
  // std::vector<QSharedPointer><Cat>> cats(max);
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  return a.exec();
}
