#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

// Uncomment to use Qt provided example
// #define USE_QT_EXAMPLE

#ifdef USE_QT_EXAMPLE
void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
  QByteArray localMsg = msg.toLocal8Bit();
  const char *file = context.file ? context.file : "";
  const char *function = context.function ? context.function : "";
  switch (type)
  {
    case QtDebugMsg:
      fprintf(stderr, "Debug: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
      break;
    case QtInfoMsg:
      fprintf(stderr, "Info: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
      break;
    case QtWarningMsg:
      fprintf(stderr, "Warning: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
      break;
    case QtCriticalMsg:
      fprintf(stderr, "Critical: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
      break;
    case QtFatalMsg:
      fprintf(stderr, "Fatal: %s (%s:%u, %s)\n", localMsg.constData(), file, context.line, function);
      break;
  }
}
#else
// This is done because after saving the messages to log file, we are asking
// Qt to go out and pump out this data in a normal way also
// and by this approach we can save the data and also retain the previous
// functionality of printing the logs on the terminal
const QtMessageHandler QT_DEFAULT_MESSAGE_HANDLER = qInstallMessageHandler(nullptr);

void myMessageOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
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
  QFile file("log.txt");
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
#endif

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qInstallMessageHandler(myMessageOutput);


  qInfo() << "This is an info message";
  qDebug() << "This is a debug message";
  qWarning() << "This is a warning message";
  qCritical() << "This is a critical message";
  qFatal("This is SPARTA!!");

  return a.exec();
}
