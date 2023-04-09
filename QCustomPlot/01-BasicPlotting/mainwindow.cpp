
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // generate some data:
  QList<double> x(101), y(101); // initialize with entries 0..100
  for (int i=0; i<101; ++i)
  {
    x[i] = i/50.0 - 1; // x goes from -1 to 1
    y[i] = x[i]*x[i]; // let's plot a quadratic function
  }

  // Changing the Look of the Graph
  // Line Style (QCPGraph::lsLine, QCPGraph::lsStepLeft etc..)
  ui->customPlot->graph(0)->setLineStyle( QCPGraph::lsLine );
  // Line Pen (All pens the QFainter-framework provides are available, e.g
  // solid, dashed
  ui->customPlot->graph(0)->setPen( QPen(Qt::darkCyan) );
  // Fills under graph or between two graphs
  ui->customPlot->graph(0)->setBrush( QBrush(QColor(0, 0x8B, 0x8B, 50) ) );   // dark cyan color with 20 value for alpha channel

  // ui->customPlot is the pointer to the QCustomPlot instance
  // create graph and assign data to it:
  ui->customPlot->addGraph();
  ui->customPlot->graph(0)->setData(x, y);

  // give the axes some labels:
  ui->customPlot->xAxis->setLabel("x");
  ui->customPlot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  ui->customPlot->xAxis->setRange(-1, 1);
  ui->customPlot->yAxis->setRange(0, 1);

  /* The tick step & labeling is chosen automatically, by the axis ticker that
   * is currently used by the axis. This is an instance of type QCPAxisTicker,
   * and is accessible e.g. via xAxis->ticker(). You can adjust the approximate
   * number of ticks that the ticker tries to create via
   * xAxis->ticker()->setTickCount(6). The default axis ticker is well suited
   * for simple numerical displays, however there are specialized classes e.g.
   * for time spans, calendar dates, categories, pi (or other symbolic units) &
   * logarithmic axes. See the QCPAxisTicker documentation for details.*/
  ui->customPlot->xAxis->ticker()->setTickCount(6);

  // Setting margins for tick labels
  // By default margins are calculated automatically, to display use the following line
  // ui->customPlot->axisRect()->setAutoMargins( QCP::msNone );
  // and then to adjust margins manually, we can use below
  // ui->customPlot->axisRect()->setMargins(QMargins(10, 10, 10, 10));


  // call the below method to make any kind of changes to the plot appear on screen
  ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
  delete ui;
}


