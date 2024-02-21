#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <QObject>
#include <QtMqtt/QMqttClient>

class MqttHandler : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QMqttClient::ClientState state READ state WRITE setState NOTIFY stateChanged FINAL)
  Q_PROPERTY(QString temperature READ temperature WRITE setTemperature NOTIFY temperatureChanged FINAL)
  Q_PROPERTY(QString humidity READ humidity WRITE setHumidity NOTIFY humidityChanged FINAL)
public:
  explicit MqttHandler(QObject *parent = nullptr);

  Q_INVOKABLE void connectToHost();
  Q_INVOKABLE void disconnectFromHost();
  Q_INVOKABLE int  publish(const QString &topic, \
                           const QString &message, \
                           int qos = 0, bool retain = false);

  QMqttClient::ClientState state() const;
  void setState(const QMqttClient::ClientState &newState);

  QString temperature() const;
  void setTemperature(const QString &newTemperature);

  QString humidity() const;
  void setHumidity(const QString &newHumidity);

signals:

  void stateChanged();

  void temperatureChanged();

  void humidityChanged();

private slots:
  void onConnected(void);
  void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
  QString topic1 = "SensorData";
  QMqttClient m_client;
  QString m_temperature;
  QString m_humidity;
};

#endif // MQTTHANDLER_H
