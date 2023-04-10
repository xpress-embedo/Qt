#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRandomGenerator>

/* Plotting date and time data
 * Next, we'll look at how to plot date and/or time related data.
 * It basically comes down to installing a different axis ticker of type
 * QCPAxisTickerDateTime on the respective axis. */

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // set locale to english, so we get english month names:
  ui->customPlot->setLocale(QLocale(QLocale::English, QLocale::UnitedKingdom));
  // seconds of current time, we'll use it as starting point in time for data:
  double now = QDateTime::currentDateTime().toSecsSinceEpoch();
  // Set the random seed, so we always get the same random data
  srand(8);

  // Create Mutiple Graphs
  for( int gi=0; gi<5; gi++ )
  {
    // QColor color("red");
    QColor color(20+200/4.0*gi,70*(1.6-gi/4.0), 150, 150);
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph()->setPen(QPen(color.lighter(200)));
    ui->customPlot->graph()->setBrush(QBrush(color));

    // Generate Random data
    QList<QCPGraphData> timeData(250);
    for( int idx=0; idx<250; idx++ )
    {
      timeData[idx].key = now + 24*60*60*idx;   // current time + (1 day * idx)

      if (idx == 0)
      {
        timeData[idx].value = (idx/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
      else
      {
        timeData[idx].value = qFabs(timeData[idx-1].value)*(1+0.02/4.0*(4-gi)) + (idx/50.0+1)*(rand()/(double)RAND_MAX-0.5);
      }
    }
    ui->customPlot->graph()->data()->set( timeData );
  }

  // Configure Bottom Axis to show date instead of number
  QSharedPointer<QCPAxisTickerDateTime> dateTicker(new QCPAxisTickerDateTime);
  dateTicker->setDateTimeFormat("d. MMMM\nyyyy");
  ui->customPlot->xAxis->setTicker(dateTicker);

  // configure left axis text labels:
  QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
  textTicker->addTick(10, "a bit\nlow");
  textTicker->addTick(50, "quite\nhigh");
  ui->customPlot->yAxis->setTicker(textTicker);

  // set a more compact font size for bottom and left axis tick labels:
  ui->customPlot->xAxis->setTickLabelFont(QFont(QFont().family(), 8));
  ui->customPlot->yAxis->setTickLabelFont(QFont(QFont().family(), 8));

  // set axis labels:
  ui->customPlot->xAxis->setLabel("Date");
  ui->customPlot->yAxis->setLabel("Random wobbly lines value");

  // make top and right axes visible but without ticks and labels:
  ui->customPlot->xAxis2->setVisible(true);
  ui->customPlot->yAxis2->setVisible(true);
  ui->customPlot->xAxis2->setTicks(false);
  ui->customPlot->yAxis2->setTicks(false);
  ui->customPlot->xAxis2->setTickLabels(false);
  ui->customPlot->yAxis2->setTickLabels(false);

  // set axis ranges to show all data:
  ui->customPlot->xAxis->setRange(now, now+24*3600*249);
  ui->customPlot->yAxis->setRange(0, 60);
  // ui->customPlot->rescaleAxes();

  // show legend with slightly transparent background brush:
  ui->customPlot->legend->setVisible(true);
  ui->customPlot->legend->setBrush(QColor(255, 255, 255, 150));
}

MainWindow::~MainWindow()
{
  delete ui;
}

