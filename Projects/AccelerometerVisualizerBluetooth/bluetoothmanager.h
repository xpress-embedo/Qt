#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QObject>
#include <QtBluetooth>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothSocket>
#include <QDebug>

class BluetoothManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QStringList detectedDevicesList READ detectedDevicesList WRITE setDetectedDevicesList NOTIFY detectedDevicesListChanged);
  Q_PROPERTY(QString selectedDevice READ selectedDevice WRITE setSelectedDevice NOTIFY selectedDeviceChanged);
  Q_PROPERTY(bool connStatus READ connStatus WRITE setConnStatus NOTIFY connStatusChanged);
public:
  explicit BluetoothManager(QObject *parent = nullptr);

  QStringList detectedDevicesList() const;
  void setDetectedDevicesList(const QStringList &newDetectedDevicesList);

  QString selectedDevice() const;
  void setSelectedDevice(const QString &newSelectedDevice);

  bool connStatus() const;
  void setConnStatus(bool newConnStatus);

private slots:
  void deviceDiscovered( const QBluetoothDeviceInfo &device);

signals:

  void detectedDevicesListChanged();

  void selectedDeviceChanged();

  void connStatusChanged();

private:
  QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
  QBluetoothSocket *socket;
  QString m_deviceName;
  QStringList m_detectedDevicesList;
  QStringList m_detectedDevicesAddressList;
  QString m_selectedDevice;
  bool m_connStatus;
};

#endif // BLUETOOTHMANAGER_H
