#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QProcess>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QTime>
#include <QtCharts>
#include <QLineSeries>
#include <QChartView>
#include <QDateTimeAxis>
#include <QValueAxis>

MainWindow::MainWindow(QWidget *parent)  : QMainWindow(parent)  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Keep the plot area dominant and button compact.
  ui->verticalLayout->setStretch(0, 1);
  ui->verticalLayout->setStretch(1, 0);
  ui->btnDownload->setFixedHeight(34);
}

MainWindow::~MainWindow()
{
  delete ui;
}


void MainWindow::on_btnDownload_clicked()
{
  this->downloadFromFTP();
}

void MainWindow::downloadFromFTP()
{
  // Download the data from the FTP server
  QString program = "C:/Windows/System32/curl.exe";
  QStringList arguments =
  {
    "--ftp-ssl",
    "--insecure",
    "ftp://xpress:embedo@localhost/ftpserver/logs.txt",
    "-o",
    "logs.txt"
  };

  QProcess process;
  process.start(program, arguments);
  process.waitForFinished();

  qDebug() << "STDOUT:" << process.readAllStandardOutput();
  qDebug() << "STDERR:" << process.readAllStandardError();
  qDebug() << "Exit code:" << process.exitCode();

  if (process.exitCode() == 0)
  {
    qDebug() << "Download successful";
  }
  else
  {
    qDebug() << "Download failed";
  }

  // Plot the data received from the FTP Server
  QFile file("logs.txt");
  if( !file.open(QIODevice::ReadOnly) )
  {
    qDebug() << "Not able to open the files";
  }
  else
  {
    // We are here because file is present
    QTextStream stream(&file);
    QLineSeries *data1 = new QLineSeries();
    QLineSeries *data2 = new QLineSeries();
    QDateTime datetime = QDateTime::currentDateTime();

    // Lets read from the file
    while( !stream.atEnd() )
    {
      QString line = stream.readLine();
      QStringList values = line.split(',');
      qDebug() << values;
      QDateTime parsed = QDateTime::fromString(values[0], "yyyy-MM-dd HH:mm:ss");
      datetime = parsed;
      // add time and data1 to the series
      data1->append( datetime.toMSecsSinceEpoch(), values[1].toUInt() );
      // add time and data2 to the series
      data2->append( datetime.toMSecsSinceEpoch(), values[2].toUInt() );
    }
    // now we can close the file as the file end has reached
    file.close();

    // Plotting Logic
    QChart *chartData1 = new QChart();
    QChart *chartData2 = new QChart();

    QChartView *chartViewData1 = new QChartView(chartData1);
    QChartView *chartViewData2 = new QChartView(chartData2);

    // Data1 Plotting
    chartData1->legend()->hide();
    chartData1->addSeries( data1 );

    // Since we use QLineSeries, calling createDefaultAxes will create QValueAxis both as X and Y axis.
    // To use QDateTimeAxis we need to set it manually to the chart.
    // First, the instance of QDateTimeAxis is created, then the number of ticks to be shown is set.
    // chartAdc->createDefaultAxes();
    QDateTimeAxis *axisXdata1 = new QDateTimeAxis;
    axisXdata1->setTickCount(10);
    axisXdata1->setFormat("yyyy-MM-dd hh:mm:ss");
    axisXdata1->setTitleText("Time Axis");
    chartData1->addAxis(axisXdata1, Qt::AlignBottom);
    data1->attachAxis(axisXdata1);

    QValueAxis *axisYdata1 = new QValueAxis;
    axisYdata1->setLabelFormat("%i");
    axisYdata1->setTitleText("RAW Counts");
    axisYdata1->setRange(0, 255);
    chartData1->addAxis(axisYdata1, Qt::AlignLeft);
    data1->attachAxis(axisYdata1);

    chartData1->setTitle("FTP Server Data-1");

    // Data2 Plotting
    chartData2->legend()->hide();
    chartData2->addSeries( data2 );
    // chartData->createDefaultAxes();
    QDateTimeAxis *axisXdata2 = new QDateTimeAxis;
    axisXdata2->setTickCount(10);
    axisXdata2->setFormat("hh:mm:ss");
    axisXdata2->setTitleText("Time Axis");
    chartData2->addAxis(axisXdata2, Qt::AlignBottom);
    data2->attachAxis(axisXdata2);

    QValueAxis *axisYdata2 = new QValueAxis;
    axisYdata2->setLabelFormat("%i");
    axisYdata2->setTitleText("Temperature Value");
    axisYdata2->setRange(0, 100);
    chartData2->addAxis(axisYdata2, Qt::AlignLeft);
    data2->attachAxis(axisYdata2);

    chartData2->setTitle("FTP Server Data-2");

    // Layout
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->PlotWidget->layout());
    if (!layout)
    {
      layout = new QVBoxLayout(ui->PlotWidget);
      layout->setContentsMargins(0, 0, 0, 0);
      layout->setSpacing(8);
      ui->PlotWidget->setLayout(layout);
    }

    while (QLayoutItem *item = layout->takeAt(0))
    {
      if (item->widget())
      {
        item->widget()->deleteLater();
      }
      delete item;
    }

    chartViewData1->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartViewData2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(chartViewData1, 1);
    layout->addWidget(chartViewData2, 1);
    layout->setStretch(0, 1);
    layout->setStretch(1, 1);
    chartViewData1->setRenderHint(QPainter::Antialiasing);
    chartViewData2->setRenderHint(QPainter::Antialiasing);

    /* Note: why I didn't used
    * QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    * this->setLayout( layout );
    * The reason is simple, if I use the centeral widget then when let's say
    * I added few more widgets to screen, let's say two push button
    * Since these two buttons are also on the centeral widget hence they will
    * hide below this plot, as this plot is covering everything.
    * Hence the better solution is to create a new widget and adjust the layout
    * and use them like this as shown above. */
  }
}

