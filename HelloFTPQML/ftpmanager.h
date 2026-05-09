#ifndef FTPMANAGER_H
#define FTPMANAGER_H

#include <QObject>
#include <QQmlEngine>
#include <QVariantList>

class FTPManager : public QObject
{
  Q_OBJECT
  QML_ELEMENT
  Q_PROPERTY(QVariantList series1 READ getSeries1 NOTIFY dataReady)
  Q_PROPERTY(QVariantList series2 READ getSeries2 NOTIFY dataReady)
public:
  explicit FTPManager(QObject *parent = nullptr);

  Q_INVOKABLE void downloadFTPData();

  // getter methods
  QVariantList getSeries1() const { return m_series1; }
  QVariantList getSeries2() const { return m_series2; }

signals:
  void dataReady();

private:
  QVariantList m_series1;
  QVariantList m_series2;
};

#endif // FTPMANAGER_H
