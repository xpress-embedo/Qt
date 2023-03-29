#include <QCoreApplication>
#include <QDebug>
#include <QLoggingCategory>

// Declare Logging Category
Q_DECLARE_LOGGING_CATEGORY(network);
Q_LOGGING_CATEGORY(network, "network");

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInfo() << "test";

  qInfo(network) << "test";
  qWarning(network) << "test";

  // turn off network logs in debug mode
  // NOTE: there is a catch, only the last set filter rules will be accepted
  // so here info messages will be off but not the debug message
  QLoggingCategory::setFilterRules("network.debug=false");
  QLoggingCategory::setFilterRules("network.info=false");

  qInfo() << "test working";
  // will no log
  qInfo(network) << "test not working or not logged-1";
  qDebug(network) << "test not working or not logged-2";

  if( !network().isDebugEnabled() )
  {
    qDebug(network) << "This message shouldn't print, but is? check NOTE above";
    QLoggingCategory::setFilterRules("network.debug=true");
    qDebug(network) << "Debugging is Enabled again";
  }
  else
  {
    qDebug(network) << "Debugging is already Enabled (Check NOTE above)";
  }

  return a.exec();
}
