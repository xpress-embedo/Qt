#ifndef FTPMANAGER_H
#define FTPMANAGER_H

#include <QObject>
#include <QQmlEngine>

class FTPManager : public QObject
{
  Q_OBJECT
  QML_ELEMENT
public:
  explicit FTPManager(QObject *parent = nullptr);

signals:

};

#endif // FTPMANAGER_H
