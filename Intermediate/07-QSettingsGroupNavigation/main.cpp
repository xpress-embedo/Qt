#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QRandomGenerator>

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

  QStringList people;
  people << "Bryan" << "Tammy" << "Heather" << "Chris";

  foreach ( QString person, people )
  {
    // Here we are creating a new group test and saving the people with some
    // random ages in the settings
    int value = QRandomGenerator::global()->bounded(100);
    saveAge( &settings, "test", person, value );
  }

  // SAVE
  settings.sync();
  qInfo() << "File:" << settings.fileName();

  foreach (QString group, settings.childGroups() )
  {
    settings.beginGroup(group);
    qInfo() << "Group:" << group;

    foreach( QString key, settings.childKeys() )
    {
      qInfo() << "...key:" << key << " = " << settings.value(key).toString();
    }

    settings.endGroup();
  }

//  qInfo() << "TwoHeart" << getAge( &settings, "beer", "twoheart" );
//  qInfo() << "Bryan (People)" << getAge( &settings, "people", "Bryan" );
//  qInfo() << "Bryan (Beer)" << getAge( &settings, "beer", "Bryan" );

  return a.exec();
}
