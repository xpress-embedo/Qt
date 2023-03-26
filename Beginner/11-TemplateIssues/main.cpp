#include <QCoreApplication>

template<class T, class F>
T add( T valueT, F valueF )
{
  return (valueT + valueF);
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInfo() << add<int, double>( 1, 4.6 );
  qInfo() << add( 55, true);
  qInfo() << add( true, 56);
  qInfo() << add<int, bool>( 55, true);

  return a.exec();
}
