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
  qDebug() << device.name();
  if( !m_detectedDevicesList.contains(device.name()) )
  {
    m_detectedDevicesList.append( device.name() );
    emit detectedDevicesListChanged();
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
