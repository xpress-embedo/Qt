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

  return a.exec();
}
