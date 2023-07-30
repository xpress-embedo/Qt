#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "bluetoothmanager.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  // Register a type in QML (URI (Package Name), Major Ver., Minor Ver., QML name)
  qmlRegisterType<BluetoothManager>("com.company.bluetoothmanager", 1, 0, "BluetoohManager" );

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/AccelerometerVisualizerBluetooth/Main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
      &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
