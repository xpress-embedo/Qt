#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QtDebug>
#include <QVariant>
#include <QRandomGenerator>

class Test : public QObject
{
  Q_OBJECT
public:
  Test();

signals:
  void status( QVariant data );

public slots:
  void work( QVariant data );
};

#endif // TEST_H
