#ifndef CONVERTER_H
#define CONVERTER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QVariant>
#include <QVariantMap>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMap>
#include "test.h"

class Converter : public QObject
{
  Q_OBJECT
public:
  explicit Converter(QObject *parent = nullptr);

  static void writeJson( Test *obj, QString path );
  static Test* readJson( QString path );

signals:

};

#endif // CONVERTER_H
