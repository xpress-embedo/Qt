/*
 * QMap Provides Key Value Pair
 * The QMap class is a template class that provides an associative array.
*/

#include <QCoreApplication>
#include <QDebug>
#include "pet.h"

typedef QMap<QString, Pet*> petList;

petList createPets( int max )
{
  petList map;
  for( int idx=0; idx<max; idx++ )
  {
    QString id = QString::number(idx);
    Pet* pet = new Pet();
    pet->setAge(idx*3);
    pet->setName("Pet: " + id);
    map.insert(id, pet);
  }
  return map;
}

void listPets( petList pets )
{
  foreach( QString key, pets.keys() )
  {
    Pet* pet = pets.value(key);
    qInfo() << key << pet->getName() << " is Age: " << pet->age();
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  petList pets;
  // Create QMap of Pets
  pets = createPets(5);

  qInfo() << "Counts: " << pets.count();

  // List Created Pets
  listPets(pets);

  // Let's insert a new pet into our list
  Pet* pet = new Pet();
  pet->setAge(99);
  pet->setName("Bad Kitty");
  pets.insert("My Cat", pet);

  qInfo() << "Counts: " << pets.count();
  listPets(pets);

  // We can also replace an existing key also, by using that key name
  pets.insert("1", pet);
  qInfo() << "Counts: " << pets.count();
  listPets(pets);

  // Lets delete whole list using deleteAll
  qDeleteAll( pets.values() );
  pets.clear();

  qInfo() << "Counts: " << pets.count();
  listPets(pets);


  return a.exec();
}
