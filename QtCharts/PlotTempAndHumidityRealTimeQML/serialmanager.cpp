#include <QDateTime>
#include "serialmanager.h"

// https://doc.qt.io/qt-5/qtquick-modelviewsdata-cppmodels.html
SerialManager::SerialManager(QObject *parent) : QObject{parent}
{
  qDebug() << "Serial Manager Constructed";
  m_connectStatus = false;

  qDebug() << "Detecting the available Serial Ports";
  // Get the list of available serial ports
  QList<QSerialPortInfo> serial_port_infos = QSerialPortInfo::availablePorts();
  // print the available ports, and here we need to update the QML ComboBox
  for( const QSerialPortInfo &port_info : serial_port_infos )
  {
    qDebug() << "Port: " << port_info.portName();
    // we have to add this port name in the combo box "port_info.portName()"
    // on QML which I don't know as of now
  }
}

SerialManager::~SerialManager()
{
  // If serial port is open close it
  if( m_serial.isOpen() )
  {
    m_serial.close();
  }
}

bool SerialManager::connectStatus()
{
  return m_connectStatus;
}

void SerialManager::setConnectStatus( bool value )
{
  if( value != m_connectStatus )
  {
    // if false, we have to connect, else disconnect
    if( m_connectStatus == false )
    {
      //  TODO: qDebug() << "Connecting: " << comPortName;
      m_serial.setBaudRate( QSerialPort::Baud9600 );
      m_serial.setDataBits( QSerialPort::Data8 );
      m_serial.setParity( QSerialPort::NoParity );
      m_serial.setStopBits( QSerialPort::OneStop );
      m_serial.setFlowControl( QSerialPort::NoFlowControl );
      // m_serial.setPortName( comPortName );
      m_serial.setPortName( "COM1" );
      if( m_serial.open( QIODevice::ReadWrite ) )
      {
        qDebug() << "Serial Port Opened Successfully";
        m_serial.write("Hello World from Qt\r\n");
        m_connectStatus = true;
        // TODO: updae the button name from "Connect" to "Disconnect"
        // TODO: disable the combo box
        // Connect Signal and Slots
        connect(&m_serial, SIGNAL( readyRead() ), this, SLOT(readyRead() ) );
      }
      else
      {
        m_connectStatus = false;
        qDebug() << "Unable to open the Selected Serial Port" << m_serial.error();
      }
    }
    else
    {
      m_connectStatus = false;
      qDebug() << "Disconnecting...";
      // close the serial port
      m_serial.close();
      // TODO: Revert the status of "Disconnect" button to "Connect"
      // TODO: Enable the combo box
    }
    emit connectStatusChanged( m_connectStatus );
  }
}

void  SerialManager::readyRead( void )
{
  QByteArray serialData;
  QByteArray temperature;
  QByteArray humidity;
  QPointF temperatureValue;
  QPointF humidityValue;
  double now;

  if( m_serial.canReadLine() )
  {
    serialData = m_serial.readLine();
    // to checking here, make sure the data received is in correct format
    temperature.append(serialData[0]);
    temperature.append(serialData[1]);
    humidity.append(serialData[3]);
    humidity.append(serialData[4]);
    // qDebug() << temperature.toUInt() << humidity.toUInt();
    // The function calls will automatically emit the value changed signals
    now = QDateTime::currentSecsSinceEpoch();
    temperatureValue.setX( now );
    temperatureValue.setY( temperature.toUShort() );
    setTemperature( temperatureValue );
    humidityValue.setX( now );
    humidityValue.setY( humidity.toUShort() );
    setHumidity( humidityValue );
  }
}

QPointF SerialManager::temperature() const
{
  return m_temperature;
}

void SerialManager::setTemperature(QPointF newTemperature)
{
  if (m_temperature == newTemperature)
    return;
  m_temperature = newTemperature;
  emit temperatureChanged();
}

QPointF SerialManager::humidity() const
{
  return m_humidity;
}

void SerialManager::setHumidity(QPointF newHumidity)
{
  if (m_humidity == newHumidity)
    return;
  m_humidity = newHumidity;
  emit humidityChanged();
}
