#include "mqtthandler.h"
#include <QDebug>
#include <QMqttTopicName>


MqttHandler::MqttHandler(QObject *parent)
  : QObject{parent}
{
  // hard-coding the hostname and port for now
  m_client.setHostname("test.mosquitto.org");
  m_client.setPort(1883);

  connect(&m_client, &QMqttClient::connected, this, &MqttHandler::onConnected);
  connect(&m_client, &QMqttClient::messageReceived, this, &MqttHandler::onMessageReceived);
}

void MqttHandler::connectToHost()
{
  qDebug() << "Connect with Host";
  m_client.connectToHost();
}

void MqttHandler::disconnectFromHost()
{
  qDebug() << "Disconnect with Host";
  m_client.disconnectFromHost();
}

int MqttHandler::publish(const QString &topic, const QString &message, int qos, bool retain)
{
  qDebug() << "Publishing Message";
  auto result = m_client.publish(QMqttTopicName(topic), message.toUtf8(), qos, retain);
  return result;
}

QMqttClient::ClientState MqttHandler::state() const
{
  return m_client.state();
}

void MqttHandler::setState(const QMqttClient::ClientState &newState)
{
  m_client.setState(newState);
  qDebug() << "Connection State Changed";
  emit stateChanged();
}


void MqttHandler::onConnected(void)
{
  // always subscribe after connection is successful
  m_client.subscribe(QMqttTopicFilter(topic1));
  qDebug() << "Connected and Subscribed to topic";
}

void MqttHandler::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
  // qDebug() << "Message Received";
  // check if SensorData is received
  if( topic.name() == topic1 )
  {
    // Convert QByteArray to QString
    QString string = QString::fromUtf8(message);
    // Split the QString based on the comma delimiter
    QStringList values = string.split(',');
    // Extract values
    if (values.size() == 2)
    {
      QString temperature = values.at(0);
      QString humidity = values.at(1);
      // Output values
      qDebug() << "Temperature: " << temperature;
      qDebug() << "Humdity:" << humidity;
      setTemperature(temperature);
      setHumidity(humidity);
    }
  }
}

QString MqttHandler::temperature() const
{
  return m_temperature;
}

void MqttHandler::setTemperature(const QString &newTemperature)
{
  if (m_temperature == newTemperature)
    return;
  m_temperature = newTemperature;
  emit temperatureChanged();
}

QString MqttHandler::humidity() const
{
  return m_humidity;
}

void MqttHandler::setHumidity(const QString &newHumidity)
{
  if (m_humidity == newHumidity)
    return;
  m_humidity = newHumidity;
  emit humidityChanged();
}
