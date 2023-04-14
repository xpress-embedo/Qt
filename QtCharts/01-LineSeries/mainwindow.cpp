#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QtCharts>
#include <QLineSeries>
#include <QChartView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  QLineSeries *series = new QLineSeries();
  QChart *chart = new QChart();
  QChartView *chartView = new QChartView(chart);

  for (int i=0; i<101; i++ )
  {
    series->append(i, i*i);
  }

  chart->legend()->hide();
  chart->addSeries(series);
  chart->createDefaultAxes();
  chart->setTitle("Simple line chart example");

  chartView->setRenderHint(QPainter::Antialiasing);
  chartView->setParent(ui->frame);
  chartView->setMinimumSize( ui->frame->size() );
}

MainWindow::~MainWindow()
{
  delete ui;
}

