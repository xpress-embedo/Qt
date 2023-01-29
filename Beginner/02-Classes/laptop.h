#ifndef LAPTOP_H
#define LAPTOP_H

#include <QObject>

class Laptop : public QObject
{
  Q_OBJECT
public:
  // Constructor
  explicit Laptop(QObject *parent = nullptr, QString name="");
  // Deconstructor
  ~Laptop();
  int weight;
  QString name;
  double asKilo();
  void test();

signals:

};

#endif // LAPTOP_H
