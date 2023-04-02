#include <QCoreApplication>
#include <QThread>

// View Current Thread

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QThread *thread = QThread::currentThread();
  thread->setObjectName("Main Thread");

  qInfo() << "Starting" << thread;

  for(int i = 0; i < 10; i++)
  {
    qInfo() << i << "on" << thread;
  }
  qInfo() << "Finished" << thread;

  return a.exec();
}
