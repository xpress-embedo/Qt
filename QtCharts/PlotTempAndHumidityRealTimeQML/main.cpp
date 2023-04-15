
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "serialmanager.h"


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  // Register a type in QML (URI (Package Name), Major Ver., Minor Ver., QML name)
  qmlRegisterType<SerialManager>("com.company.serialmanager", 1, 0, "SerialManager" );

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/PlotTempAndHumidityRealTimeQML/Main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
