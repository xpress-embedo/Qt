#include "test.h"

Test::Test()
{

}

void Test::work( QVariant data )
{
  bool ok;
  int numIn = data.toInt( &ok );
  int numOut = 0;

  if( !ok )
  {
    qWarning() << "Not a Valid Number";
  }
  else
  {
    int numRand = QRandomGenerator::global()->bounded(100);
    numOut = numIn * numRand;
    qInfo() << "In: " <<numIn;
    qInfo() << "Random: " << numRand;
    qInfo() << "Out: " << numOut;
  }

  emit status( QVariant(numOut) );
}
