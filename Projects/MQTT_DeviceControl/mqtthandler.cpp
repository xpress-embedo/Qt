#include "mqtthandler.h"
#include <QDebug>
#include <QMqttTopicName>

/**
 * @brief Constructor Function to initialize the MQTT client
 * @param parent 
 */
MqttHandler::MqttHandler(QObject *parent)
  : QObject{parent}
{
  // hard-coding the hostname and port for now
  m_client.setHostname("test.mosquitto.org");
  m_client.setPort(1883);

  // attaching signal slot for mqtt connection successful
  connect(&m_client, &QMqttClient::connected, this, &MqttHandler::onConnected);
  // attaching signal slot for mqtt message received for subscribed topic
  connect(&m_client, &QMqttClient::messageReceived, this, &MqttHandler::onMessageReceived);
}

/**
 * @brief Qt Invokable Function which makes them accesible from QML, this is
 *        used to connect with mqtt host
 */
void MqttHandler::connectToHost()
{
  qDebug() << "Connect with Host";
  m_client.connectToHost();
}

/**
 * @brief Qt Invokable Function which makes them accesible from QML, this is
 *        used to disconnect with mqtt host
 */
void MqttHandler::disconnectFromHost()
{
  qDebug() << "Disconnect with Host";
  m_client.disconnectFromHost();
}

/**
 * @brief Qt Invokable Function which makes it accessible from QML, this is used
 *        to publish the topic with message and some other information
 * @param topic   topic name
 * @param message message
 * @param qos     quality of service
 * @param retain  true or false
 * @return status
 */
int MqttHandler::publish(const QString &topic, const QString &message, int qos, bool retain)
{
  qDebug() << "Publishing Message";
  auto result = m_client.publish(QMqttTopicName(topic), message.toUtf8(), qos, retain);
  return result;
}

/**
 * @brief MQTT connection status
 * @return MqttHandler.Connected if connected else not
 */
QMqttClient::ClientState MqttHandler::state() const
{
  return m_client.state();
}

/**
 * @brief Set the MQTT State
 * @param newState 
 */
void MqttHandler::setState(const QMqttClient::ClientState &newState)
{
  m_client.setState(newState);
  qDebug() << "Connection State Changed";
  emit stateChanged();
}

/**
 * @brief Private Slot when MQTT client is connected with Host
 *        Here we do subscription of the topics
 * @param none
 */
void MqttHandler::onConnected(void)
{
  // always subscribe after connection is successful
  m_client.subscribe(QMqttTopicFilter(topic1));
  m_client.subscribe(QMqttTopicFilter(topic2));
  m_client.subscribe(QMqttTopicFilter(topic3));
  qDebug() << "Connected and Subscribed to topic";
}

/**
 * @brief Private Slot when MQTT client receives a topic with message
 * @param message message information
 * @param topic   topic information, use topic.name to get the topic name
 */
void MqttHandler::onMessageReceived(const QByteArray &message, const QMqttTopicName &topic)
{
  bool ok;
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
  // similarly we can do checks for other topics here
  if( topic.name() == topic2 )
  {
    quint16 slider = message.toUInt(&ok);
    if( ok )
    {
      // qDebug() << "Topic2 Received:" << slider;
      // update the latest value, this will automatically emit the signal
      setSlider(slider);
    }
  }

  if( topic.name() == topic3 )
  {
    // qDebug() << "Topic3 Received:" << message;
    quint8 ledState = message.toUShort(&ok);
    if( ok )
    {
      // convert positive value as 1 and 0 as zero
      ledState = ledState > 0 ? 1:0;
      setLed(ledState);
    }
  }
}

/**
 * @brief Get Temperature Value
 * @return QString value as temperature
 */
QString MqttHandler::temperature() const
{
  return m_temperature;
}

/**
 * @brief Set the Temperature Value, and emit the signal
 * @param newTemperature 
 */
void MqttHandler::setTemperature(const QString &newTemperature)
{
  if (m_temperature == newTemperature)
    return;
  m_temperature = newTemperature;
  emit temperatureChanged();
}

/**
 * @brief Get Humidity Value
 * @return QString value as Humidity
 */
QString MqttHandler::humidity() const
{
  return m_humidity;
}

/**
 * @brief Set the Humidity Value, and emit the signal
 * @param newHumidity
 */
void MqttHandler::setHumidity(const QString &newHumidity)
{
  if (m_humidity == newHumidity)
    return;
  m_humidity = newHumidity;
  emit humidityChanged();
}

quint16 MqttHandler::slider() const
{
  return m_slider;
}

void MqttHandler::setSlider(quint16 newSlider)
{
  if (m_slider == newSlider)
    return;
  m_slider = newSlider;
  emit sliderChanged();
}

bool MqttHandler::led() const
{
  return m_led;
}

void MqttHandler::setLed(bool newLed)
{
  if (m_led == newLed)
    return;
  m_led = newLed;
  emit ledChanged();
}
