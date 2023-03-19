#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QDebug>

class Backend : public QObject
{
  Q_OBJECT

  Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
  Q_PROPERTY(QString data READ data WRITE setData NOTIFY dataChanged)
public:
  explicit Backend(QObject *parent = nullptr);

  QString path( void );
  void setPath( QString value );
  QString data( void );
  void setData( QString value );

signals:
  void pathChanged( void );
  void dataChanged( void );

private:
  QString m_path;

};

#endif // BACKEND_H
