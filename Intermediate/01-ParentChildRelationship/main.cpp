#include <QCoreApplication>

#include "test.h"

Test* makeTree( void )
{
  Test* root = new Test(nullptr, "Root");

  for( int i=0; i<5; i++ )
  {
    Test* pobj = new Test(root, "Parent-" + QString::number(i));
    for( int j=0; j<3; j++ )
    {
      Test* cobj = new Test(pobj, "Child-" + \
                            QString::number(i) + " " + \
                            QString::number(j));
      // Q_UNUSED(cobj);
      for( int k=0; k<3; k++ )
      {
        Test* sobj = new Test(cobj, "Sub-" + QString::number(i) + " " + \
                              QString::number(j) + " " + \
                              QString::number(k));
        // This is used to get rid of the warning
        Q_UNUSED(sobj);
      }
    }
  }

  return root;
}

void printTree( Test* root, int level=0 )
{
  if( root->children().length() == 0 )
  {
    return;
  }

  QString lead = "-";
  lead.fill('-', level*5);
  foreach (QObject* obj, root->children() )
  {
    Test* child = qobject_cast<Test*>(obj);
    if( !child )
    {
      // not a valid pointer
      return;
    }
    qInfo() << lead << child;
    // Recursive Function
    printTree( child, level + 1);
  }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Test* tree = makeTree();
  printTree(tree, 1);
  delete tree;

  return a.exec();
}
