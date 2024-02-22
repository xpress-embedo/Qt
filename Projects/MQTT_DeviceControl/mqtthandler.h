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
  Q_PROPERTY(quint16 slider READ slider WRITE setSlider NOTIFY sliderChanged FINAL)
  Q_PROPERTY(bool led READ led WRITE setLed NOTIFY ledChanged FINAL)
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

  quint16 slider() const;
  void setSlider(quint16 newSlider);

  bool led() const;
  void setLed(bool newLed);

signals:

  void stateChanged();

  void temperatureChanged();

  void humidityChanged();

  void sliderChanged();

  void ledChanged();

private slots:
  void onConnected(void);
  void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
  QString topic1 = "SensorTopic";
  QString topic2 = "SliderTopic";
  QString topic3 = "LedTopic";
  QMqttClient m_client;
  QString m_temperature;
  QString m_humidity;
  quint16 m_slider;
  bool m_led;
};

#endif // MQTTHANDLER_H
