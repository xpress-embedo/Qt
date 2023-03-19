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

  // Public Members
  int weight;
  QString name;

  // Public Methods
  double asKilo( void );
  void test( void );

signals:

};

#endif // LAPTOP_H
