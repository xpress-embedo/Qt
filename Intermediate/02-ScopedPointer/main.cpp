#include <QCoreApplication>
#include <QScopedPointer>
#include "test.h"

void test()
{
  QScopedPointer<Test> sp(new Test());
  // sp.data()->setObjectName("My Test");
  sp->setObjectName("My Test");

  qInfo() << "Scoped Pointer" << &sp;
  qInfo() << "Pointer Data" << sp.data();
  qInfo() << sp->objectName();

  // Here the observation is that the deconstructor is also called even though
  // we didn't called the delete function
  // This is the beauty of the smart pointer of Qt QScopedPointer
  // This is happening because when this function is executed and we returned
  // to our main function, then the sp pointer is also destroyed and in turn it
  // also destroy the the class and deconstructor function is called
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  test();

  return a.exec();
}
