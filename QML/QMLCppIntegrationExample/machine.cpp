#include "machine.h"

Machine::Machine(QObject *parent)
  : QObject{parent}
{
  m_timer.setInterval(1000);
  connect( &m_timer, &QTimer::timeout, this, &Machine::timeout );
}

int Machine::value( void )
{
  qInfo() << "Returing the value";
  return m_value;
}

void Machine::setValue( int data )
{
  qInfo() << "Setting the value";
  m_value = data;
  emit progress();
}

void Machine::start( void )
{
  setValue(0);
  m_timer.start();
  emit started();
}

void Machine::stop( void )
{
  m_timer.stop();
  emit stoped();
}

void Machine::pause( void )
{
  m_timer.stop();
  emit paused();
}

void Machine::resume( void )
{
  m_timer.start();
  emit resumed();
}

void Machine::timeout( void )
{
  m_value++;
  emit progress();
  if( m_value > 99 )
  {
    stop();
  }
}
