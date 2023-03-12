#include <QGuiApplication>
#include <QQmlApplicationEngine>

// Entry Point of the Application
int main(int argc, char *argv[])
{
  // Application Attributes (this is deprecated now, and has no impact, High-DPI Scaling is always enabled
  // QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  // The Application Class
  QGuiApplication app(argc, argv);

  // The QML Engine
  QQmlApplicationEngine engine;

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
