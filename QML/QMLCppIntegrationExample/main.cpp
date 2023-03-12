#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "machine.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  qmlRegisterType<Machine>("com.company.machine",1,0,"Machine");

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/QMLCppIntegrationExample/main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
