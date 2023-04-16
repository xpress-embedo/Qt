#include <QtWidgets/QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "serialmanager.h"


int main(int argc, char *argv[])
{
  /* NOTE: Some important links to understand why we have to use QApplication
   * instead of QGuiApplication
   * https://doc.qt.io/qt-6.2/qtcharts-index.html
   * From Qt Website: Projects created with Qt Creator's Qt Quick Application
   * wizard are based on the Qt Quick 2 template that uses QGuiApplication by
   * default. All such QGuiApplication instances in the project must be replaced
   *  with QApplication as the module depends on Qt's Graphics View Framework
   *  for rendering.
   * https://forum.qt.io/topic/113883/importing-qtcharts-in-qml-causes-module-not-installed-error-and-app-crash
   * https://youtu.be/t2jcY-HB4C0
  */
  // Qt Charts uses Qt Graphics View Framework for drawing, therefore QApplication must be used.
  QApplication app(argc, argv);

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
