/*
 * Templates are independent of any particular type. A template is a blueprint
 * of formula for creating a template class or a function.
*/

#include <QCoreApplication>
#include <QDebug>

template<typename T>

void print( T value )
{
  qInfo() << value;
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  print<QString>("Hello World");
  print<double>(2.05);
  print<int>(1);

  return a.exec();
}
