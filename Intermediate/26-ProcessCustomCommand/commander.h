#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>
#include <QDebug>
#include <QProcess>
#include <QSysInfo>

class Commander : public QObject
{
  Q_OBJECT
public:
  explicit Commander(QObject *parent = nullptr);
  ~Commander( void );

signals:

public slots:
  void readyRead( void );
  void action( QByteArray data );

private:
  QProcess proc;
  QString app;
  QString endl;
};

#endif // COMMANDER_H
