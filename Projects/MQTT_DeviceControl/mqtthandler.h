#ifndef MQTTHANDLER_H
#define MQTTHANDLER_H

#include <QObject>
#include <QtMqtt/QMqttClient>

class MqttHandler : public QObject
{
  Q_OBJECT
  Q_PROPERTY(QMqttClient::ClientState state READ state WRITE setState NOTIFY stateChanged FINAL)
public:
  explicit MqttHandler(QObject *parent = nullptr);

  Q_INVOKABLE void connectToHost();
  Q_INVOKABLE void disconnectFromHost();
  Q_INVOKABLE int  publish(const QString &topic, \
                           const QString &message, \
                           int qos = 0, bool retain = false);

  QMqttClient::ClientState state() const;
  void setState(const QMqttClient::ClientState &newState);

signals:

  void stateChanged();

private slots:
  void onConnected(void);
  void onMessageReceived(const QByteArray &message, const QMqttTopicName &topic);

private:
  QString topic1 = "SensorData";
  QMqttClient m_client;
};

#endif // MQTTHANDLER_H
