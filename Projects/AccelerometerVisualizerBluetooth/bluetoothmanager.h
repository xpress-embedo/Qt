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
  Q_PROPERTY(float roll READ roll WRITE setRoll NOTIFY rollChanged);
  Q_PROPERTY(float pitch READ pitch WRITE setPitch NOTIFY pitchChanged);
public:
  explicit BluetoothManager(QObject *parent = nullptr);

  QStringList detectedDevicesList() const;
  void setDetectedDevicesList(const QStringList &newDetectedDevicesList);

  QString selectedDevice() const;
  void setSelectedDevice(const QString &newSelectedDevice);

  bool connStatus() const;
  void setConnStatus(bool newConnStatus);

  float roll() const;
  void setRoll(float newRoll);

  float pitch() const;
  void setPitch(float newPitch);

private slots:
  void deviceDiscovered( const QBluetoothDeviceInfo &device);
  void readyRead();
  void connected();
  void disconnected();
  void onSocketErrorOccurred(QBluetoothSocket::SocketError);

signals:

  void detectedDevicesListChanged();

  void selectedDeviceChanged();

  void connStatusChanged();

  void rollChanged();

  void pitchChanged();

private:
  QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
  QBluetoothSocket *socket;
  QString m_deviceName;
  QStringList m_detectedDevicesList;
  QStringList m_detectedDevicesAddressList;
  QString m_selectedDevice;
  bool m_connStatus;
  float m_roll;
  float m_pitch;
};

#endif // BLUETOOTHMANAGER_H
