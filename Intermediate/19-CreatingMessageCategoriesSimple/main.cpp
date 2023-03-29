#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QLoggingCategory logtest("testing");
  // here disabling the debug message not info, warning, critical
  logtest.setEnabled(QtMsgType::QtDebugMsg, false);

  qDebug() << "Debug    = " << logtest.isDebugEnabled();
  qInfo() << "Info     = " << logtest.isInfoEnabled();
  qWarning() << "Warning  = " << logtest.isWarningEnabled();
  qCritical() << "Critical = " << logtest.isCriticalEnabled();

  qDebug(logtest) << "This is a debug";
  qInfo(logtest) << "This is a Info";
  qWarning(logtest) << "This is a warning";
  qCritical(logtest) << "This is a Critical";

  return a.exec();
}
