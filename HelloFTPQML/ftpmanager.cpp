#include "ftpmanager.h"
#include <QDebug>


FTPManager::FTPManager(QObject *parent)
  : QObject{parent}
{

}

void FTPManager::downloadData()
{
  qDebug() << "Downloading data is in progress...";
}
