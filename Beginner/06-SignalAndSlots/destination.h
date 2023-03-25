#ifndef DESTINATION_H
#define DESTINATION_H

#include <QObject>

class Destination : public QObject
{
  Q_OBJECT
public:
  explicit Destination(QObject *parent = nullptr);

signals:

public slots:
  // here we used the same name as signal but it can be different also
  void mySignal( QString message );

};

#endif // DESTINATION_H
