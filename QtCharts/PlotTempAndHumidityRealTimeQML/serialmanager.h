
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
  /* IMPOTANT NOTE for below mentioned property
   * I deleted the WRITE and NOTIFY signal, I am not using them, hence removed
   * Why I added CONSTANT in the below mentioned property, because I was getting
   * the "Warning about non-NOTIFYable properties in QML"
   * If the property values can change, then QML needs a NOTIFY signal so it can
   * know when they have changed and update property bindings. If they can't
   * change, add CONSTANT to your property declaration
   * https://stackoverflow.com/questions/6728615/warning-about-non-notifyable-properties-in-qml
  */
  Q_PROPERTY(QStringList detectedComNames READ detectedComNames CONSTANT);

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

signals:
  void connectStatusChanged( bool currentStatus );

  void temperatureChanged();

  void humidityChanged();

  void minRangeChanged();

  void maxRangeChanged();

  void comNameChanged();

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
