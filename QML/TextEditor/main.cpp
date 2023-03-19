#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "backend.h"


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  qmlRegisterType<Backend>("BackEnd", 1, 0, "Backend");

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/TextEditor/main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
