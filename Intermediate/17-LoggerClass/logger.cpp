#include "logger.h"

bool Logger::logging = false;
QString Logger::filename = QDir::currentPath() + QDir::separator() + "log.txt";
const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

Logger::Logger(QObject *parent) : QObject{parent}
{

}

void Logger::attach()
{
  Logger::logging = true;
  qInstallMessageHandler(Logger::handler);
}

void Logger::handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
  if( Logger::logging )
  {
    QString text;
    switch (type)
    {
      case QtDebugMsg:
        text = QString("Debug: %1").arg(msg);
        break;
      case QtInfoMsg:
        text = QString("Info: %1").arg(msg);
        break;
      case QtWarningMsg:
        text = QString("Warning: %1").arg(msg);
        break;
      case QtCriticalMsg:
        text = QString("Critical: %1").arg(msg);
        break;
      case QtFatalMsg:
        text = QString("Fatal: %1").arg(msg);
        break;
    }

    // Saving this in a file
    QFile file(Logger::filename);
    if( file.open(QIODevice::Append) )
    {
      QTextStream stream(&file);
      stream << QDateTime::currentDateTime().toString() << " - " << text << \
                context.file << " line " << context.line << "\r\n";
      stream.flush();
      file.close();
    }

    // This is done because after saving the messages to log file, we are asking
    // Qt to go out and pump out this data in a normal way also
    // and by this approach we can save the data and also retain the previous
    // functionality of printing the logs on the terminal
    (*QT_DEFAULT_MESSAGE_HANDLER)(type, context, msg );
  }
}
