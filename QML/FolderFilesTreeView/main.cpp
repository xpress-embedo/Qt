#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "FileTreeModel.h"


int main(int argc, char *argv[])
{
  QGuiApplication app(argc, argv);

  FileTreeModel fileTreeModel;

  const QString sourceDataPath =
      QDir::cleanPath(QString::fromUtf8(SAMPLE_DATA_PATH));
  fileTreeModel.setSourcePath(sourceDataPath);

  QQmlApplicationEngine engine;
  engine.rootContext()->setContextProperty("fileTreeModel", &fileTreeModel);
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
                   &app, []() { QCoreApplication::exit(-1); },
  Qt::QueuedConnection);
  engine.loadFromModule("FolderFilesTreeView", "Main");

  return QCoreApplication::exec();
}
