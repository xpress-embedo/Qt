#include <QCoreApplication>
#include <QDebug>

void display( QString *value )
{
  qInfo() << "The Pointer" << value;
  qInfo() << "The Address" << &value;
  qInfo() << "The Data" << *value;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QString name = "Test Name";                             // This goes to Stack - C++ Manages this
  QString *description = new QString("Hello Pointer");    // This goes to Heap - and we have to manage this

  qInfo() << description;

  display( description );

  // As mentioned above this is in heap and we have to manage this
  delete description;

  // description is deleted above and if we tried to use the below statement
  // the program will crash (Use of Memory after it is freed)
  // display( description );

  return a.exec();
}
