#ifndef DIRHELPER_H
#define DIRHELPER_H

#include <QObject>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>

class DirHelper : public QObject
{
  Q_OBJECT

  // Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged)
  Q_PROPERTY(QString path READ path WRITE setPath)
  Q_PROPERTY(QStringList files READ files)

public:
  explicit DirHelper(QObject *parent = nullptr);

signals:

private:
  QDir dir;
  QString path( void );
  void setPath( QString value );
  QStringList files( void );
};

#endif // DIRHELPER_H
