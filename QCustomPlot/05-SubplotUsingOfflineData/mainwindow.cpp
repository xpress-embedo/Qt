#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>

#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTime>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Open the file
  QFile file("D:\\Projects\\Qt Projects\\QT\\QCustomPlot\\05-SubplotUsingOfflineData\\data.txt");

  if( !file.open(QIODevice::ReadOnly) )
  {
    qDebug() << "Not able to open the files";
  }
  else
  {
    QTextStream stream(&file);
    QDateTime datetime = QDateTime::currentDateTime();
    // QList<QCPGraphData> temperatureData;
    QList<double>timeData;
    QList<double>temperatureData;
    QList<double>adcData;
    uint16_t data_idx=0;

    // Lets Read from file now
    while( !stream.atEnd() )
    {
      QString line = stream.readLine();
      QStringList values = line.split(',');
      qDebug() << values;
      // Convert into QTime format
      QTime time = QTime::fromString(values[0], "hh:mm:ss");
      // Now update the time in the datetime variable (basically we don't have date information so we are assuming the date as current date)
      datetime.setTime( time );
      // Append the Temperature and ADC Data into the List for plotting
      temperatureData.append( values[2].toFloat() );
      adcData.append( values[1].toUInt() );
      timeData.append( datetime.toSecsSinceEpoch() );
    }
    // now we can close the file as end is reached
    file.close();

    // Now we have data in temperature and adc list,
    // and it's time to add graph and plot the data
    QColor color(255, 0, 0, 100);
    // QColor color("red");   // I think with this lighter doesn't work as no alpha
    /*
    ui->customPlot->addGraph( );
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->graph(0)->setPen(QPen(color.lighter(20)));
    ui->customPlot->graph(0)->setBrush(QBrush(color));
    // Add Temperature Data to the graph
    ui->customPlot->graph(0)->setData( timeData, temperatureData );

    // Configure the axis to show time instead of values
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker( new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("hh:mm:ss");
    ui->customPlot->xAxis->setTicker( dateTimeTicker );

    // Setting Ranges
    ui->customPlot->yAxis->setRange( 0, 100);
    ui->customPlot->xAxis->setRange( timeData.first(), timeData.last() );
    // Next Step is to update the example
    // https://www.qcustomplot.com/index.php/demos/advancedaxesdemo
    */

    // Creating subplots
    // let's start from scratch and remove the default axis rectanlges
    ui->customPlot->plotLayout()->clear();

    // Adding Title to graphs
    // first we create and prepare a text layout element:
    QCPTextElement *titleTop = new QCPTextElement(ui->customPlot);
    titleTop->setText("ADC Counts Plot Using Offline Data");
    titleTop->setFont(QFont("sans", 10, QFont::Bold));

    QCPTextElement *titleBottom = new QCPTextElement(ui->customPlot);
    titleBottom->setText("Temperature Value Plot Using Offline Data");
    titleBottom->setFont(QFont("sans", 10, QFont::Bold));

    // then we add it to the main plot layout:
    // insert an empty row, this is 1st row (we are starting from 0th row)
    ui->customPlot->plotLayout()->insertRow(0);
    // place the title in the empty cell we've just created
    ui->customPlot->plotLayout()->addElement(0, 0, titleTop);

    // add the axis rect this is basically 2nd row (index=1)
    QCPAxisRect *topAxisRect = new QCPAxisRect(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(1, 0, topAxisRect);

    // insert an empty row this is basically 3rd row (index=2)
    ui->customPlot->plotLayout()->insertRow(2);
    // place the title in the empty cell we've just created
    ui->customPlot->plotLayout()->addElement(2, 0, titleBottom);

    // insert and empty row this is basically 4th row (index=4)
    ui->customPlot->plotLayout()->insertRow(3);
    // add the axis rect in third row (row index 3):
    QCPAxisRect *bottomAxisRect = new QCPAxisRect(ui->customPlot);
    ui->customPlot->plotLayout()->addElement(3, 0, bottomAxisRect);

    QList<QCPAxis*> allAxes;
    allAxes << bottomAxisRect->axes() << topAxisRect->axes();
    foreach (QCPAxis *axis, allAxes)
    {
      axis->setLayer("axes");
      axis->grid()->setLayer("grid");
    }

    QCPGraph *bottomGraph = ui->customPlot->addGraph( bottomAxisRect->axis(QCPAxis::atBottom), bottomAxisRect->axis(QCPAxis::atLeft) );
    bottomGraph->setPen(QPen(QColor(255, 0, 0)));
    bottomGraph->setBrush(QBrush(QColor(255, 120, 120, 50)));

    bottomGraph->setData( timeData, temperatureData );
    // The following methods are for auto rescaling
    // bottomGraph->rescaleValueAxis();
    bottomGraph->rescaleKeyAxis();
    // If want to set ranges manually use the following methods
    bottomGraph->valueAxis()->setRange(0, 100);
    bottomGraph->keyAxis()->setRange( timeData.first(), timeData.last() );

    // Configure the axis to show time instead of values
    QSharedPointer<QCPAxisTickerDateTime> dateTimeTicker( new QCPAxisTickerDateTime);
    dateTimeTicker->setDateTimeFormat("hh:mm:ss");
    bottomGraph->keyAxis()->setTicker( dateTimeTicker );
    // Labelling axis
    bottomGraph->keyAxis()->setLabel( "Time Axis");
    bottomGraph->valueAxis()->setLabel( "Temperature Value" );

    QCPGraph *topGraph = ui->customPlot->addGraph( topAxisRect->axis(QCPAxis::atBottom), topAxisRect->axis(QCPAxis::atLeft) );
    topGraph->setData( timeData, adcData );
    // The following methods are for auto rescaling
    // topGraph->rescaleValueAxis();
    // topGraph->rescaleKeyAxis();
    // If want to set ranges manually use the following methods
    topGraph->valueAxis()->setRange(0, 255);
    topGraph->keyAxis()->setRange( timeData.first(), timeData.last() );
    // Setting the same ticker value as used for bottom axis
    topGraph->keyAxis()->setTicker( dateTimeTicker );
    // Labelling axis
    topGraph->keyAxis()->setLabel( "Time Axis");
    topGraph->valueAxis()->setLabel( "ADC Counts" );
  }
}

MainWindow::~MainWindow()
{
  delete ui;
}
