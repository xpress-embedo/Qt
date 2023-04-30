
#include "widget.h"
#include "./ui_widget.h"
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
  : QWidget(parent)
  , ui(new Ui::Widget)
{
  ui->setupUi(this);

  // Declare the widget
  QWidget * widget = new QWidget(this);

  // Declare the layout for the widget
  QVBoxLayout *layout = new QVBoxLayout();

  layout->addWidget( new QPushButton("Button-1", this) );
  layout->addWidget( new QPushButton("Button-2", this) );
  layout->addWidget( new QPushButton("Button-3", this) );
  QPushButton *button4 = new QPushButton("Button-4", this);
  connect( button4, &QPushButton::clicked, [=](){
    qDebug() << "Button-4 from Our Custom Tab Clicked";
  });
  layout->addWidget( button4 );
  layout->addSpacerItem( new QSpacerItem(100,200) );
  // Set the layout to the widget
  widget->setLayout( layout );

  // Add the widget to the layout
  // ui->tabWidget->addTab( widget, "Tab 4");
  // if we wanted to insert the tab in between
  ui->tabWidget->insertTab(1, widget, "Tab-4");

}

Widget::~Widget()
{
  delete ui;
}



void Widget::on_btn_tab1_clicked()
{
  qDebug() << "Tab-1 Button Clicked";
}

