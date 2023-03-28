#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

void info( QSettings &settings )
{
  qInfo() << "File:" << settings.fileName();
  qInfo() << "Key:"  << settings.allKeys();
}

void save( QSettings &settings )
{
  settings.setValue("test", QVariant(123) );
  qInfo() << settings.status();
  qInfo() << "Saved";
}

void load( QSettings &settings )
{
  bool ok;
  info(settings);
  qInfo() << settings.value("test").toString();
  qInfo() << settings.value("test").toInt(&ok);
  if( !ok )
  {
    // Something bad has happened and conversion to integer failed
    qInfo() << "Couldn't Convert to Integer";
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QCoreApplication::setOrganizationName("Embedded Laboratory");
  QCoreApplication::setOrganizationDomain("embeddedlaboratory.com");
  QCoreApplication::setApplicationName("QSetting Testing");

  QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName() );
  if( settings.allKeys().length() == 0 )
  {
    qInfo() << "No Setting...saving...";
    save(settings);
  }
  else
  {
    qInfo() << "Loading the Settings..";
    load(settings);
  }

  return a.exec();
}
