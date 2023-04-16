
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H


#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QPointF>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool connectStatus READ connectStatus WRITE setConnectStatus NOTIFY connectStatusChanged);
  Q_PROPERTY(QPointF humidity READ humidity WRITE setHumidity NOTIFY humidityChanged);
  Q_PROPERTY(QPointF temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged)

public:
  explicit SerialManager(QObject *parent = nullptr);
  ~SerialManager();

  bool connectStatus( void );

  QPointF temperature() const;
  void setTemperature(QPointF newTempValue);

  QPointF humidity() const;
  void setHumidity(QPointF newHumidity);

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
  QPointF m_temperature;
  QPointF m_humidity;
};

#endif // SERIALMANAGER_H
