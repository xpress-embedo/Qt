#include <QCoreApplication>
#include <QDebug>
#include <QDate>
#include <QTime>
#include <QDateTime>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  QDate today = QDate::currentDate();
  qInfo() << today;
  qInfo() << today.addDays(1);
  qInfo() << today.addYears(2);

  // Dates in different format
  qInfo() << "ISO Date" << today.toString(Qt::DateFormat::ISODate);
  qInfo() << "RFC2822 Date" << today.toString(Qt::DateFormat::RFC2822Date);
  qInfo() << "Text Date" << today.toString(Qt::DateFormat::TextDate);

  QTime now = QTime::currentTime();
  // Times in different format (note there is no Qt::TimeFormat
  qInfo() << now;
  qInfo() << "ISO Time" << now.toString(Qt::DateFormat::ISODate);
  qInfo() << "RFC2822 Time" << now.toString(Qt::DateFormat::RFC2822Date);
  qInfo() << "Text Time" << now.toString(Qt::DateFormat::TextDate);

  QDateTime current = QDateTime::currentDateTime();
  qInfo() << current;

  QDateTime expire = current.addDays(45);
  qInfo() << "Expire on" << expire;


  return a.exec();
}
