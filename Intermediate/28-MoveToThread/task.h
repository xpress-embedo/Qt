#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QThread>
#include <QDebug>

class Task : public QObject
{
  Q_OBJECT
public:
  explicit Task(QObject *parent = nullptr);
  ~Task( void );

signals:

public slots:
  void work( void );
};

#endif // TASK_H
