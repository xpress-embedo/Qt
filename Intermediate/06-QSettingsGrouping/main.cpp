#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

void saveAge( QSettings *setting, QString group, QString name, int age )
{
  setting->beginGroup(group);
  setting->setValue(name, age);
  setting->endGroup();
}

int getAge( QSettings *setting, QString group, QString name )
{
  setting->beginGroup(group);
  // first check if this exist or not
  if( !setting->contains(name) )
  {
    qWarning() << "Does't contain " << name << " in " << group;
    setting->endGroup();
    return 0;
  }

  bool ok;
  // NOTE: the QSettings value is a QVariant and hence always needs to be converted
  // either to string or integer etc. based on our requirement
  int value = setting->value(name).toInt(&ok);
  setting->endGroup();
  if( !ok )
  {
    qWarning() << "Can't convert to integer";
    return 0;
  }
  return value;
}


int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QCoreApplication::setOrganizationName("Embedded Laboratory");
  QCoreApplication::setOrganizationDomain("embeddedlaboratory.com");
  QCoreApplication::setApplicationName("QSetting Testing");

  QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName() );

  saveAge( &settings, "people", "Bryan", 44 );
  saveAge( &settings, "beer", "twoheart", 1 );
  saveAge( &settings, "beer", "Bryan", 11 );

  qInfo() << "TwoHeart" << getAge( &settings, "beer", "twoheart" );
  qInfo() << "Bryan (People)" << getAge( &settings, "people", "Bryan" );
  qInfo() << "Bryan (Beer)" << getAge( &settings, "beer", "Bryan" );

  return a.exec();
}
