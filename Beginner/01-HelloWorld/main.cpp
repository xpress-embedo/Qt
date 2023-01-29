#include <QCoreApplication>
#include <QDebug>     // Part of Qt
#include <iostream>   // Part from Standard C++ Library

using namespace std;

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  int age = 34;
  double height = 5.6;

  qInfo() << "Hello World, this is information message";
  qDebug() << "This is a debug message";

  qInfo() << "Age : " << age;
  qInfo() << "Height : " << height;

  // compiler, static analyzer all should generate warning here
  age = 34.5;
  qInfo() << "Age : " << age;

  // NOTE: This will print only in Terminal not in Qt Application Output
  cout << "Hello World from IOSTREAM\n";
  cout << "Enter a age?" << endl;
  cin >> age;
  qInfo() << "Age : " << age;

  // C++ Standard Error
  cerr << "Standard Error";


  return a.exec();
}
