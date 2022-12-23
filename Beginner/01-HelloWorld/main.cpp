#include <QCoreApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInfo() << "Hello World, this is information message\n";
  qDebug() << "This is a debug message\n";

  return a.exec();
}
