#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ftpmanager.h"


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  // Register a type in QML (URI (Package Name), Major Ver., Minor Ver., QML name)
  qmlRegisterType<FTPManager>("com.company.ftpmanager", 1, 0, "FTPManager");

  QQmlApplicationEngine engine;
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                   &app, []() { QCoreApplication::exit(-1); },
  Qt::QueuedConnection);
  engine.loadFromModule("HelloFTPQML", "Main");

  return app.exec();
}
