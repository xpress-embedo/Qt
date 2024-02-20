#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "mqtthandler.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  // Register a type in QML (URI (Package Name), Major Ver., Minor Ver., QML name)
  qmlRegisterType<MqttHandler>("com.company.mqtthandler", 1, 0, "MqttHandler" );

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/MQTT_DeviceControl/Main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
