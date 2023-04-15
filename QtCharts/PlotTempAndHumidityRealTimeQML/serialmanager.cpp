
#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent) : QObject{parent}
{
  qDebug() << "Serial Manager Constructed";
  m_connectStatus = false;
}

bool SerialManager::connectStatus()
{
  return m_connectStatus;
}

void SerialManager::setConnectStatus(bool value)
{
  if( value != m_connectStatus )
  {
    m_connectStatus = value;
    // qDebug() << "Connection Status Changed";
    emit connectStatusChanged( m_connectStatus );
  }
}

