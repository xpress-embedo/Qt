#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>

class SerialManager : public QObject
{
  Q_OBJECT
  Q_PROPERTY(float roll READ roll WRITE setRoll NOTIFY rollChanged);
  Q_PROPERTY(float pitch READ pitch WRITE setPitch NOTIFY pitchChanged);
public:
  explicit SerialManager(QObject *parent = nullptr);
  ~SerialManager();

  float roll() const;
  void setRoll(float newRoll);

  float pitch() const;
  void setPitch(float newPitch);

signals:
  void rollChanged();
  void pitchChanged();

public slots:
  void readyRead(void);

private:
  QSerialPort m_serial;
  bool m_connectStatus;
  float m_roll;
  float m_pitch;
};

#endif // SERIALMANAGER_H
