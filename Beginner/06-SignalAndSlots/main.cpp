#include <QCoreApplication>

#include "source.h"
#include "destination.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Source source;
  Destination destination;

  QObject::connect(&source, &Source::mySignal, &destination, &Destination::mySignal );

  // This function emits the mySignal, and due to signal and slot
  // mySignal slot function of destination class is called
  source.test();

  return a.exec();
}
