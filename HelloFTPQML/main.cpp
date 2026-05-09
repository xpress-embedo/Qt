#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "ftpmanager.h"


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  FTPManager ftpManager;
  engine.rootContext()->setContextProperty("ftpManager", &ftpManager);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                   &app, []() { QCoreApplication::exit(-1); },
  Qt::QueuedConnection);
  engine.loadFromModule("HelloFTPQML", "Main");

  return app.exec();
}
