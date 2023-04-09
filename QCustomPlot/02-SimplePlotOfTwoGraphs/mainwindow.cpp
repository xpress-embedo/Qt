#include "mainwindow.h"
#include "./ui_mainwindow.h"

/* An Example which creates the image of the decaying cosine function with its
 * exponential envelope.*/

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // add two new graphs and set their look:
  ui->customPlot->addGraph();
  ui->customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
  ui->customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
  ui->customPlot->addGraph();
  ui->customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph

  /* As you can see in the output, applying a fill to a graph is as easy as
   * setting a brush that is not Qt::NoBrush. The fill will go from the graph
   * (here graph 0) to the zero-value-line parallel to the key (here x) axis.
   * If we wanted a channel fill between this and another graph, we would
   * additionally call graph->setChannelFillGraph(otherGraph).
   * To remove the channel fill, just pass 0 as other graph, and the fill will
   * reach all the way to the zero-value-line as before.
   * To remove the fill completely, call graph->setBrush(Qt::NoBrush). */

  // generate some points of data (y0 for first, y1 for second graph):
  QList<double> x(251), y0(251), y1(251);
  for (int i=0; i<251; ++i)
  {
    x[i] = i;
    y0[i] = qExp(-i/150.0)*qCos(i/10.0); // exponentially decaying cosine
    y1[i] = qExp(-i/150.0);              // exponential envelope
  }

  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  ui->customPlot->xAxis2->setVisible(true);
  ui->customPlot->xAxis2->setTickLabels(false);
  ui->customPlot->yAxis2->setVisible(true);
  ui->customPlot->yAxis2->setTickLabels(false);

  // make left and bottom axes always transfer their ranges to right and top axes:
  connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->xAxis2, SLOT(setRange(QCPRange)));
  connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // pass data points to graphs:
  ui->customPlot->graph(0)->setData(x, y0);
  ui->customPlot->graph(1)->setData(x, y1);

  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  ui->customPlot->graph(0)->rescaleAxes();
  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
  ui->customPlot->graph(1)->rescaleAxes(true);
  // Note: we could have also just called customPlot->rescaleAxes(); instead

  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

MainWindow::~MainWindow()
{
  delete ui;
}

