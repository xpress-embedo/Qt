#include <QDebug>
#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
  : QObject{parent}
{
  m_connectStatus = false;
  qDebug() << "Connecting with Serial Port";
  m_serial.setBaudRate( QSerialPort::Baud115200 );
  m_serial.setDataBits( QSerialPort::Data8 );
  m_serial.setParity( QSerialPort::NoParity );
  m_serial.setStopBits( QSerialPort::OneStop );
  m_serial.setFlowControl( QSerialPort::NoFlowControl );
  m_serial.setPortName( "COM2" );
  if( m_serial.open( QIODevice::ReadWrite ) )
  {
    m_connectStatus = true;
    qDebug() << "Serial Port Opened Successfully";
    m_serial.write("Hello World from Qt\r\n");
    // Connect Signal and Slots
    connect(&m_serial, SIGNAL( readyRead() ), this, SLOT(readyRead() ) );
  }
  else
  {
    m_connectStatus = false;
    qDebug() << "Unable to open the Selected Serial Port" << m_serial.error();
  }
}

void SerialManager::readyRead()
{
  QByteArray serialData;
  float tempPitch;
  float tempRoll;
  bool ok;

  if( m_serial.canReadLine() )
  {
    serialData = m_serial.readLine();
    // Convert this data into string, which is better for splitting
    QString serialDataString(serialData);
    // Now Split this data based on ',' delimiter
    QStringList parts = serialDataString.split(",");
    if( parts.size() == 2 )
    {
      tempRoll = parts[0].toFloat(&ok);
      if( ok )
      {
        // if first is okay, then only move to next
        tempPitch = parts[1].toFloat(&ok);
        if( ok )
        {
          // both values are converted sucessfully update the globals
          qDebug() << "Roll: " << tempRoll;
          qDebug() << "Pitch: " << tempPitch;
          // setting will automatically emit the changed signal
          setRoll(tempRoll);
          setPitch(tempPitch);
        }
      }
    }
  }
}

float SerialManager::roll() const
{
  return m_roll;
}

void SerialManager::setRoll(float newRoll)
{
  if (qFuzzyCompare(m_roll, newRoll))
    return;
  m_roll = newRoll;
  emit rollChanged();
}

float SerialManager::pitch() const
{
  return m_pitch;
}

void SerialManager::setPitch(float newPitch)
{
  if (qFuzzyCompare(m_pitch, newPitch))
    return;
  m_pitch = newPitch;
  emit pitchChanged();
}
