
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H


#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool connectStatus READ connectStatus WRITE setConnectStatus NOTIFY connectStatusChanged);
  Q_PROPERTY(uint8_t temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged);
  Q_PROPERTY(uint8_t humidity READ humidity WRITE setHumidity NOTIFY humidityChanged);

public:
  explicit SerialManager(QObject *parent = nullptr);
  ~SerialManager();

  bool connectStatus( void );
  uint8_t temperature() const;
  void setTemperature(uint8_t newTemperature);

  uint8_t humidity() const;
  void setHumidity(uint8_t newHumidity);

signals:
  void connectStatusChanged( bool currentStatus );

  void temperatureChanged();

  void humidityChanged();

public slots:
  void readyRead( void );
  void setConnectStatus( bool value );

private:
  QSerialPort m_serial;
  bool m_connectStatus;
  uint8_t m_temperature;
  uint8_t m_humidity;
};

#endif // SERIALMANAGER_H
