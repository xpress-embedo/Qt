#include "mqtthandler.h"
#include <QDebug>
#include <QMqttTopicName>

MqttHandler::MqttHandler(QObject *parent)
  : QObject{parent}
{
  // hard-coding the hostname and port for now
  m_client.setHostname("test.mosquitto.org");
  m_client.setPort(1883);
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
