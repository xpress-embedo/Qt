#include <QCoreApplication>
#include "task.h"
#include <QScopedPointer>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QThread::currentThread()->setObjectName("Main Thread");

  QThread worker;
  worker.setObjectName("Worker Thread");

  qInfo() << "Starting Work" << QThread::currentThread();
  // Task *tast = new Task(&a);   // can do that if we want to move this to an another thread

  QScopedPointer<Task> t(new Task() );    // Auto Delete
  Task *task = t.data();
  task->moveToThread(&worker);

  worker.connect(&worker, &QThread::started, task, &Task::work );

  worker.start();

  qInfo() << "Free to do other things...." << QThread::currentThread();

  return a.exec();
}
