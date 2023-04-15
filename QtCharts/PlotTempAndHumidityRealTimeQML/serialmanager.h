
#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H


#include <QObject>
#include <QDebug>
#include <QVariant>

class SerialManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(bool connectStatus READ connectStatus WRITE setConnectStatus NOTIFY connectStatusChanged)
public:
  explicit SerialManager(QObject *parent = nullptr);
  bool connectStatus( void );
signals:
  void connectStatusChanged( bool currentStatus );

public slots:
  void setConnectStatus( bool value );

private:
  bool m_connectStatus;
};

#endif // SERIALMANAGER_H
