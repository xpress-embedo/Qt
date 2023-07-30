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
  // Check if the device name is already present or not
  if( !m_detectedDevices.contains(device.name()) )
  {
    m_detectedDevices.append(device.name());
  }
}

QStringList BluetoothManager::detectedDevices() const
{
  return m_detectedDevices;
}
