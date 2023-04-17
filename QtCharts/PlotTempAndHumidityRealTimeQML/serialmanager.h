
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H


#include <QObject>
#include <QDebug>
#include <QVariant>
#include <QDateTime>
#include <QPointF>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool connectStatus READ connectStatus WRITE setConnectStatus NOTIFY connectStatusChanged);
  Q_PROPERTY(QPointF humidity READ humidity WRITE setHumidity NOTIFY humidityChanged);
  Q_PROPERTY(QPointF temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged);
  Q_PROPERTY(QDateTime minRange READ minRange WRITE setMinRange NOTIFY minRangeChanged);
  Q_PROPERTY(QDateTime maxRange READ maxRange WRITE setMaxRange NOTIFY maxRangeChanged);
  Q_PROPERTY(QString comName READ comName WRITE setComName NOTIFY comNameChanged);
  Q_PROPERTY(QStringList detectedComNames READ detectedComNames WRITE setDetectedComNames NOTIFY detectedComNamesChanged);

public:
  explicit SerialManager(QObject *parent = nullptr);
  ~SerialManager();

  bool connectStatus( void );

  QPointF temperature() const;
  void setTemperature(QPointF newTempValue);

  QPointF humidity() const;
  void setHumidity(QPointF newHumidity);

  QDateTime minRange() const;
  void setMinRange(const QDateTime &newMinRange);

  QDateTime maxRange() const;
  void setMaxRange(const QDateTime &newMaxRange);

  QString comName() const;

  QStringList detectedComNames() const;
  void setDetectedComNames(const QStringList &newDetectedComNames);

signals:
  void connectStatusChanged( bool currentStatus );

  void temperatureChanged();

  void humidityChanged();

  void minRangeChanged();

  void maxRangeChanged();

  void comNameChanged();

  void detectedComNamesChanged();

public slots:
  void readyRead( void );
  void setConnectStatus( bool value );
  void setComName(const QString &newComName);

private:
  QSerialPort m_serial;
  bool m_connectStatus;
  QPointF m_temperature;
  QPointF m_humidity;
  QDateTime m_minRange;
  QDateTime m_maxRange;
  QString m_comName;
  QStringList m_detectedComNames;
};

#endif // SERIALMANAGER_H
