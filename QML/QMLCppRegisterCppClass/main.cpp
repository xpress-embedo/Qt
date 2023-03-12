#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>
#include "test.h"

int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  qmlRegisterType<Test>("com.company.test",1,0,"Test");

  QQmlApplicationEngine engine;
  const QUrl url(u"qrc:/QMLCppRegisterCppClass/main.qml"_qs);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
