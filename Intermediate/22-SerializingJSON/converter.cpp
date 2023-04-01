#include "converter.h"

Converter::Converter(QObject *parent)
    : QObject{parent}
{

}

void Converter::writeJson(Test *obj, QString path)
{
  QVariantMap map;
  QVariantMap items;

  map["items"] = obj->name();
  foreach ( QString key, obj->map().keys() )
  {
    items.insert(key, QVariant( obj->map().value(key)) );
  }
}

Test *Converter::readJson(QString path)
{

}
