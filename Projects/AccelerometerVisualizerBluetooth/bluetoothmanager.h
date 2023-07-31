#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>
#include <QtBluetooth>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothLocalDevice>
#include <QDebug>

class BluetoothManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QStringList detectedDevicesList READ detectedDevicesList WRITE setDetectedDevicesList NOTIFY detectedDevicesListChanged);
public:
  explicit BluetoothManager(QObject *parent = nullptr);

  QStringList detectedDevicesList() const;
  void setDetectedDevicesList(const QStringList &newDetectedDevicesList);

private slots:
  void deviceDiscovered( const QBluetoothDeviceInfo &device);

signals:

  void detectedDevicesListChanged();

private:
  QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
  QString m_deviceName;
  QStringList m_detectedDevicesList;
};

#endif // BLUETOOTHMANAGER_H
