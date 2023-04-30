
#include "widget.h"
#include "./ui_widget.h"


Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);
  // Set Multi Selection mode for List Widget
  ui->listWidget->setSelectionMode( QAbstractItemView::MultiSelection );
}

Widget::~Widget()
{
  delete ui;
}



void Widget::on_btnAddItem_clicked()
{
  ui->listWidget->addItem("New Item");
}


void Widget::on_bnDeleteItem_clicked()
{
  int selectedItem = ui->listWidget->currentRow();
  ui->listWidget->takeItem( selectedItem );
}


void Widget::on_btnSelectedItems_clicked()
{
  // get the list of the selected items, for multi item selection make sure
  // SelectionMode is set correctly for multi-selection
  QList<QListWidgetItem*> list = ui->listWidget->selectedItems();

  for( int i=0; i<list.count(); i++ )
  {
    qDebug() << "Selected Item: " << list.at(i)->text() << " , Row Number Id : "
             << ui->listWidget->row( list.at(i) );
  }
}

