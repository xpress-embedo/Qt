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
  /*
  if (m_connStatus == newConnStatus)
    return;
  */
  m_connStatus = newConnStatus;
  qDebug() << "Connection Status: " << (m_connStatus ? "TRUE":"FALSE");
  if( m_connStatus == true )
  {
    // static const QString serviceUuid(QStringLiteral("00001101-0000-1000-8000-00805F9B34FB"));
    idx = m_detectedDevicesList.indexOf(m_selectedDevice);
    if( idx >= 0 )
    {
      qDebug() << "Index: " << idx << ", Address: " << m_detectedDevicesAddressList[idx];
    }

    // socket = new QBluetoothSocket(QBluetoothAddress(), QBluetoothUuid(serviceUuid), QIODevice::ReadWrite );
  }
  emit connStatusChanged();
}
