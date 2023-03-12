#include "test.h"

Test::Test()
{
  connect( &m_timer, &QTimer::timeout, \
           this, &Test::timeout );
  m_timer.setInterval(1000);
  m_display = "Starting";
  qInfo() << m_display;
  emit notice( QVariant(m_display) );
}

int Test::number()
{
  qInfo() << "Called number()";
  // return a number
  return 42;
}

void Test::bark()
{
  qInfo() << "Bark Bark Bark";
}

void Test::timeout( void )
{
  m_display = QDateTime::currentDateTime().toString();
  qInfo() << m_display;
  emit notice( QVariant(m_display) );
}

void Test::start( void )
{
  m_display = "Starting";
  qInfo() << m_display;
  emit notice( QVariant(m_display) );
  m_timer.start();
}

void Test::stop( void )
{
  m_timer.stop();
  m_display = "Stopped";
  qInfo() << m_display;
  emit notice( QVariant(m_display) );
}

