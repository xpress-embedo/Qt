#include <QCoreApplication>
#include <QDebug>

#include "test.h"

void wow( void )
{
  // Automatic Memory Management
  std::unique_ptr<Test> t(new Test() );
  t->doStuff();
}

void anotherWow( void )
{
  Test *t  = new Test();
  t->doStuff();
  // here we have to do manually
  delete (t);
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInfo() << "Starting Wow";
  // this function is an exmaple of automatic memory management as class is
  // deconstructed automatically, see anotherWow where we have to manually
  // delete the memory allocated to class
  wow();
  qInfo() << "Finished Wow";

  qInfo() << "Starting anotherWow";
  anotherWow();
  qInfo() << "Finished Another Wow";

  return a.exec();
}
