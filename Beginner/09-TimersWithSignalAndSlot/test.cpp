#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{
  // connect QTimer signal to this class timeout (slot)
  connect(&m_timer, &QTimer::timeout, this, &Test::timeout );
  // Start Timer configured @ 1sec
  m_timer.setInterval(1000);
  m_timer.start();
  count = 0;
}

void Test::timeout()
{
  qInfo() << "Test!";
  count++;
  if( count >= 3 )
  {
    // Stop the timer after 3 seconds
    m_timer.stop();
  }
}
