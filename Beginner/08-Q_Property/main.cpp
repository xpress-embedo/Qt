#include <QCoreApplication>
#include <QVariant>

#include "test.h"
#include "watcher.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Test tester;
  Watcher destination;

  QObject::connect(&tester, &Test::messageChanged, &destination, &Watcher::messageChanged );

  // Both Method Works, first normal method
  tester.setMessage("Hello World Using SetMessage");
  // Second message is setting the property, here property is "message"
  tester.setProperty("message", QVariant("Hello World using SetProperty"));

  return a.exec();
}
