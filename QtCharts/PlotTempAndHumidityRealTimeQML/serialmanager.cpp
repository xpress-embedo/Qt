
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
        // connect(&m_serial, SIGNAL( readyRead() ), this, SLOT(readyRead() ) );
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

