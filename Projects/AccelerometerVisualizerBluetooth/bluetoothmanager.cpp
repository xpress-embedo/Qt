#include "bluetoothmanager.h"

QBluetoothLocalDevice localDevice;
QString localDeviceName;

BluetoothManager::BluetoothManager(QObject *parent)
    : QObject{parent}
{
  connect( agent, SIGNAL(deviceDiscovered(QBluetoothDeviceInfo)), this, \
          SLOT(deviceDiscovered(QBluetoothDeviceInfo)));
  agent->start();
  qDebug() << "Starting Agent";
}

void BluetoothManager::deviceDiscovered(const QBluetoothDeviceInfo &device)
{
  // Store only if device name is not empty
  if( device.name() != "" )
  {
    qDebug() << "Device Name:" << device.name() << "Device Address:" << device.address();
    if( !m_detectedDevicesList.contains(device.name()) )
    {
      // Saving the device name, useful for displaying purpose on front end
      m_detectedDevicesList.append( device.name() );
      // Saving the device address, useful for communication
      // Best approach should be to use the dictionary with device name as key value
      m_detectedDevicesAddressList.append( device.address().toString() );
      emit detectedDevicesListChanged();
    }
  }
}

void BluetoothManager::readyRead()
{
  QByteArray data;
  float tempPitch;
  float tempRoll;
  bool ok;

  if( !socket )
    return;

  while( socket->canReadLine() )
  {
    data = socket->readLine();
    // Convert this data into string, which is better for splitting
    QString dataString(data);
    // Now Split this data based on ',' delimiter
    QStringList parts = dataString.split(",");
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

void BluetoothManager::connected()
{
  qDebug() << "Connection with Device is Successful";
  m_connStatus = true;
  emit connStatusChanged();
}

void BluetoothManager::disconnected()
{
  qDebug() << "Disconnected from Device is Successful";
  socket->close();
  delete socket;
  socket = nullptr;
  m_connStatus = false;
  emit connStatusChanged();
}

void BluetoothManager::onSocketErrorOccurred(QBluetoothSocket::SocketError)
{
  qDebug() << "Some Socket Error, Need Investigation";
}

QStringList BluetoothManager::detectedDevicesList() const
{
  return m_detectedDevicesList;
}

void BluetoothManager::setDetectedDevicesList(const QStringList &newDetectedDevicesList)
{
  if (m_detectedDevicesList == newDetectedDevicesList)
    return;
  m_detectedDevicesList = newDetectedDevicesList;
  emit detectedDevicesListChanged();
}

QString BluetoothManager::selectedDevice() const
{
  return m_selectedDevice;
}

void BluetoothManager::setSelectedDevice(const QString &newSelectedDevice)
{
  if (m_selectedDevice == newSelectedDevice)
    return;
  m_selectedDevice = newSelectedDevice;
  emit selectedDeviceChanged();
}

bool BluetoothManager::connStatus() const
{
  return m_connStatus;
}

void BluetoothManager::setConnStatus(bool newConnStatus)
{
  qsizetype idx;
  agent->stop();
  if (m_connStatus == newConnStatus)
    return;
  // don't update here, instead update the member in connected and disconnected methods
  // m_connStatus = newConnStatus;
  qDebug() << "Old Status: " << m_connStatus << ", New Status: " << (newConnStatus ? "TRUE":"FALSE");
  if( newConnStatus == true )
  {
    idx = m_detectedDevicesList.indexOf(m_selectedDevice);
    if( idx >= 0 )
    {
      static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
      qDebug() << "Index: " << idx << ", Address: " << m_detectedDevicesAddressList[idx];
      socket = new QBluetoothSocket(QBluetoothServiceInfo::RfcommProtocol);
      socket->connectToService( QBluetoothAddress(m_detectedDevicesAddressList[idx]), \
                                QBluetoothUuid(serviceUuid), QIODevice::ReadWrite );
      connect(socket, &QBluetoothSocket::readyRead, this, &BluetoothManager::readyRead);
      connect(socket, &QBluetoothSocket::connected, this, &BluetoothManager::connected);
      connect(socket, &QBluetoothSocket::disconnected, this, &BluetoothManager::disconnected);
      connect(socket, &QBluetoothSocket::errorOccurred, this, &BluetoothManager::onSocketErrorOccurred);
    }
  }
  else
  {
    // call disconnected function
    disconnected();
  }
  // Trigger signal when connection is established or disconnected
  // emit connStatusChanged();
}

float BluetoothManager::roll() const
{
  return m_roll;
}

void BluetoothManager::setRoll(float newRoll)
{
  if (qFuzzyCompare(m_roll, newRoll))
    return;
  m_roll = newRoll;
  emit rollChanged();
}

float BluetoothManager::pitch() const
{
  return m_pitch;
}

void BluetoothManager::setPitch(float newPitch)
{
  if (qFuzzyCompare(m_pitch, newPitch))
    return;
  m_pitch = newPitch;
  emit pitchChanged();
}
