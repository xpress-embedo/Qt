#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QTextStream>
#include <QDir>
#include <iostream>

class Logger : public QObject
{
  Q_OBJECT
public:
  explicit Logger(QObject *parent = nullptr);

  // NOTE: these are static, as we want to share the data across multiple
  // instantiation of this class
  static bool logging;
  static QString filename;
  static void attach( void );
  static void handler( QtMsgType type, const QMessageLogContext &context, const QString &msg );

signals:

};

#endif // LOGGER_H
