#ifndef FTPMANAGER_H
#define FTPMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include <QLineSeries>

class FTPManager : public QObject
{
  Q_OBJECT
  QML_ELEMENT
public:
  explicit FTPManager(QObject *parent = nullptr);

  Q_INVOKABLE void downloadFTPData();

signals:

private:
  QLineSeries *m_data1 = nullptr;
  QLineSeries *m_data2 = nullptr;
};

#endif // FTPMANAGER_H
