#include "backend.h"

Backend::Backend(QObject *parent)
  : QObject{parent}
{
  m_path = QCoreApplication::applicationDirPath();
  m_path.append("/file.txt");
}

QString Backend::path()
{
  return m_path;
}

void Backend::setPath(QString value)
{
  m_path = value;
  m_path.remove("file://");
  emit pathChanged();
}

QString Backend::data()
{
  QFile file(m_path);
  if( !file.open( QIODevice::ReadOnly ) )
  {
    qWarning() << "Couldn't Read the File!";
    return "";
  }

  QTextStream stream(&file);
  QString value = stream.readAll();
  file.close();
  return value;
}

void Backend::setData(QString value)
{
  QFile file(m_path);
  if( !file.open( QIODevice::WriteOnly ) )
  {
    qWarning() << "Couldn't Write the File!";
  }

  QTextStream stream(&file);
  stream << value;
  stream.flush();
  file.close();
  emit dataChanged();
}
