#include "mainwindow.h"
#include "./ui_mainwindow.h"

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

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  // Open the file
  QFile file("D:\\Projects\\Qt Projects\\QT\\QtCharts\\02-SubplotUsingOfflineData\\data.txt");

  if( !file.open(QIODevice::ReadOnly) )
  {
    qDebug() << "Not able to open the files";
  }
  else
  {
    QTextStream stream(&file);
    QLineSeries *adc_data = new QLineSeries();
    QLineSeries *temp_data = new QLineSeries();
    QDateTime datetime = QDateTime::currentDateTime();

    // adc_data->setColor(Qt::red);
    QColor color("red");
    adc_data->setPen( QPen(color) );
    // adc_data->setBrush( QBrush(color) );


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
      // add time and adc counts which are unsigned int to the series
      adc_data->append( datetime.toMSecsSinceEpoch(), values[1].toUInt() );
      // add time and temperature value which is float to the series
      temp_data->append( datetime.toMSecsSinceEpoch(), values[2].toFloat() );
    }
    // now we can close the file as end is reached
    file.close();
    QChart *chartAdc = new QChart();
    QChart *chartTemperature = new QChart();

    QChartView *chartViewAdc = new QChartView(chartAdc);
    QChartView *chartViewTemperature = new QChartView(chartTemperature);

    // ADC Data Plot
    chartAdc->legend()->hide();
    chartAdc->addSeries( adc_data );

    // Since we use QLineSeries, calling createDefaultAxes will create QValueAxis both as X and Y axis.
    // To use QDateTimeAxis we need to set it manually to the chart.
    // First, the instance of QDateTimeAxis is created, then the number of ticks to be shown is set.
    // chartAdc->createDefaultAxes();
    QDateTimeAxis *axisXadc = new QDateTimeAxis;
    axisXadc->setTickCount(10);
    axisXadc->setFormat("hh:mm:ss");
    axisXadc->setTitleText("Time Axis");
    chartAdc->addAxis(axisXadc, Qt::AlignBottom);
    adc_data->attachAxis(axisXadc);

    QValueAxis *axisYadc = new QValueAxis;
    axisYadc->setLabelFormat("%i");
    axisYadc->setTitleText("ADC Value");
    axisYadc->setRange(0, 255);
    chartAdc->addAxis(axisYadc, Qt::AlignLeft);
    adc_data->attachAxis(axisYadc);

    chartAdc->setTitle("ADC Counts");

    // Temperature Data Plot
    chartTemperature->legend()->hide();
    chartTemperature->addSeries( temp_data );

    // chartAdc->createDefaultAxes();
    QDateTimeAxis *axisXtemp = new QDateTimeAxis;
    axisXtemp->setTickCount(10);
    axisXtemp->setFormat("hh:mm:ss");
    axisXtemp->setTitleText("Time Axis");
    chartTemperature->addAxis(axisXtemp, Qt::AlignBottom);
    temp_data->attachAxis(axisXtemp);

    QValueAxis *axisYtemp = new QValueAxis;
    axisYtemp->setLabelFormat("%i");
    axisYtemp->setTitleText("Temperature Value");
    axisYtemp->setRange(0, 100);
    chartTemperature->addAxis(axisYtemp, Qt::AlignLeft);
    temp_data->attachAxis(axisYtemp);

    chartTemperature->setTitle("Temperature Value");

    // QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    QVBoxLayout *layout = new QVBoxLayout(ui->PlotWidget);
    layout->addWidget(chartViewAdc);
    layout->addWidget(chartViewTemperature);

    chartViewAdc->setRenderHint(QPainter::Antialiasing);
    chartViewTemperature->setRenderHint(QPainter::Antialiasing);
    // this->setLayout( layout );
    ui->PlotWidget->setLayout( layout );
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

MainWindow::~MainWindow()
{
  delete ui;
}
