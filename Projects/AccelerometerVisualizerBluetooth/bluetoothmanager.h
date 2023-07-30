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
  /* IMPOTANT NOTE for below mentioned property
   * I deleted the WRITE and NOTIFY signal, I am not using them, hence removed
   * Why I added CONSTANT in the below mentioned property, because I was getting
   * the "Warning about non-NOTIFYable properties in QML"
   * If the property values can change, then QML needs a NOTIFY signal so it can
   * know when they have changed and update property bindings. If they can't
   * change, add CONSTANT to your property declaration
   * https://stackoverflow.com/questions/6728615/warning-about-non-notifyable-properties-in-qml
  */
  Q_PROPERTY(QStringList detectedDevices READ detectedDevices CONSTANT);
public:
  explicit BluetoothManager(QObject *parent = nullptr);

  QStringList detectedDevices() const;

private slots:
  void deviceDiscovered( const QBluetoothDeviceInfo &device);

signals:

private:
  QBluetoothDeviceDiscoveryAgent *agent = new QBluetoothDeviceDiscoveryAgent;
  QStringList m_detectedDevices;
  QString m_deviceName;
};

#endif // BLUETOOTHMANAGER_H
