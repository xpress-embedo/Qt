#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

signals:
  void downloadCompleted();

private slots:
  void on_btnDownload_clicked();
  void readAndPlotData( void );

private:
  Ui::MainWindow *ui;
  QLineSeries *data1 = nullptr;
  QLineSeries *data2 = nullptr;
  void downloadFromFTP( void );
};
#endif // MAINWINDOW_H
