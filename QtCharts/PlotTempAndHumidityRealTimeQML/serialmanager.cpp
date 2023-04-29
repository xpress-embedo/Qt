#include "serialmanager.h"

const uint8_t SECONDS_SHOW_ON_GRAPH = 60;   // Display "x" seconds on the graph
static qint64 startTime;

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
    m_detectedComNames.append( port_info.portName() );
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
      qDebug() << "Connecting: " << comName();
      m_serial.setBaudRate( QSerialPort::Baud9600 );
      m_serial.setDataBits( QSerialPort::Data8 );
      m_serial.setParity( QSerialPort::NoParity );
      m_serial.setStopBits( QSerialPort::OneStop );
      m_serial.setFlowControl( QSerialPort::NoFlowControl );
      m_serial.setPortName( comName() );
      if( m_serial.open( QIODevice::ReadWrite ) )
      {
        qDebug() << "Serial Port Opened Successfully";
        m_serial.write("Hello World from Qt\r\n");
        m_connectStatus = true;
        // updae the button name from "Connect" to "Disconnect" is done in QML
        // disable the combo box is also done is the QML code
        // Connect Signal and Slots
        connect(&m_serial, SIGNAL( readyRead() ), this, SLOT(readyRead() ) );

        // Setting range of SECONDS_SHOW_ON_GRAPH
        // get the current time
        QDateTime now = QDateTime::currentDateTime();
        // convert this time in seconds, to compare it with time and readjust the
        // the graph range
        startTime = now.toSecsSinceEpoch();
        // emit signal to adjust the ranges
        setMinRange( now );
        setMaxRange( now.addSecs(SECONDS_SHOW_ON_GRAPH) );
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
      // Reverting the status of "Disconnect" button to "Connect" is done in QML
      // Enable the combo box is also done in QML
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
  QDateTime now;

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
    now = QDateTime::currentDateTime();
    temperatureValue.setX( now.toMSecsSinceEpoch() );
    temperatureValue.setY( temperature.toUShort() );
    // set the temperature value, this will emit the signal to update the label
    // and line series which in turn update the chart
    setTemperature( temperatureValue );
    humidityValue.setX( now.toMSecsSinceEpoch() );
    humidityValue.setY( humidity.toUShort() );
    // set the humidity value, this will emit the signal to update the label
    // and line series which in turn update the chart
    setHumidity( humidityValue );

    // Check if we need to readjust the range of x-axis i.e. time axis
    if( (now.toSecsSinceEpoch()-startTime) > SECONDS_SHOW_ON_GRAPH )
    {
      // Already SECONDS_SHOW_ON_GRAPH time has expired, means we need to update
      // the minimum and maximum time axis ranges
      setMaxRange( now );
      setMinRange( now.addSecs((-1)*SECONDS_SHOW_ON_GRAPH) );
    }
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

QDateTime SerialManager::minRange() const
{
  return m_minRange;
}

void SerialManager::setMinRange(const QDateTime &newMinRange)
{
  if (m_minRange == newMinRange)
    return;
  m_minRange = newMinRange;
  emit minRangeChanged();
}

QDateTime SerialManager::maxRange() const
{
  return m_maxRange;
}

void SerialManager::setMaxRange(const QDateTime &newMaxRange)
{
  if (m_maxRange == newMaxRange)
    return;
  m_maxRange = newMaxRange;
  emit maxRangeChanged();
}

QString SerialManager::comName() const
{
  return m_comName;
}

void SerialManager::setComName(const QString &newComName)
{
  if (m_comName == newComName)
    return;
  m_comName = newComName;
  emit comNameChanged();
}


QStringList SerialManager::detectedComNames() const
{
  return m_detectedComNames;
}
