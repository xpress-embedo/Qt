#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Step-1: Import
#include <QQmlContext>
#include "test.h"

// Entry Point of the Application
int main(int argc, char *argv[])
{
  // Application Attributes (this is deprecated now, and has no impact, High-DPI Scaling is always enabled
  // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  // The Application Class
  QGuiApplication app(argc, argv);

  // The QML Engine
  QQmlApplicationEngine engine;

  // Step-2: Add Engine to Root Context
  // Basically here we are creating an instance of our class and then
  // shove it in the context property.
  Test test;
  engine.rootContext()->setContextProperty("testing", &test);

  // The URL of the QML File, note this is a complied resource
  const QUrl url(u"qrc:/QMLCppIntro/main.qml"_qs);

  // Connecting a signal & slot, making sure the object and URL matches
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                   &app, [url](QObject *obj, const QUrl &objUrl) {
    if (!obj && url == objUrl)
      QCoreApplication::exit(-1);
  }, Qt::QueuedConnection);

  // The Engine Loading the QML file
  engine.load(url);

  // The application entering an event loop that keeps the application open
  return app.exec();
}
