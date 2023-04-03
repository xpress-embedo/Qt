#include "task.h"

Task::Task(QObject *parent)
    : QObject{parent}
{
  qInfo() << "Constructed" << this << "on" << QThread::currentThread();
}

Task::~Task()
{
  qInfo() << "Deconstructed" << this << "on" << QThread::currentThread();
}

void Task::run()
{
  QThread *thread = QThread::currentThread();
  qInfo() << "Starting" << thread;
  for (int idx = 0; idx < 10; idx++ )
  {
    qInfo() << idx << "on" << thread;
  }
  qInfo() << "Finished" << thread;
}
