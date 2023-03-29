#include <QCoreApplication>
#include <QDebug>
#include "logger.h"
#include "test.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInfo() << "File:" << Logger::filename;
  // Now Logging will Start
  Logger::attach();
  qInfo() << "Test";
  Test test;
  test.testing();
  Logger::logging = false;
  qInfo() << "This will not be logged in a file";

  return a.exec();
}
