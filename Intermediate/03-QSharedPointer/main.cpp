#include <QCoreApplication>
#include <QSharedPointer>
#include "test.h"

QSharedPointer<Test> getObject(QString name)
{
  QSharedPointer<Test> sp(new Test());
  sp->setObjectName(name);
  // Do other things here
  return sp;
}

void doWork( QSharedPointer<Test> sp )
{
  // We are using a copy of the shared pointer
  qInfo() << "Work" << sp.data();
  qInfo() << "Shared Pointer" << &sp;
  // qInfo() << "Object" << sp.data();
}

void test( void )
{
  qInfo() << "Getting the Object";
  QSharedPointer<Test> ptr = getObject("My Object");
  qInfo() << "Shared Pointer" << &ptr;
  qInfo() << "Object" << ptr.data();
  doWork(ptr);
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  test();

  return a.exec();
}
