import QtQuick
import QtQuick.Controls
import QtQuick.Controls.Basic as Basic
import QtCharts

Window {
  id: window
  width: 640
  height: 840
  visible: true
  title: qsTr("FTP Data Visualizer")
  color: "#f3f6fb"

  Connections {
    target: ftpManager
    function onDataReady() {
      // Clear the old data
      lineSeriesData1.clear()
      lineSeriesData2.clear()

      // Push each point from C++ list into QML LineSeries
      for (var i = 0; i < ftpManager.series1.length; i++) {
        lineSeriesData1.append(ftpManager.series1[i].x, ftpManager.series1[i].y)
        lineSeriesData2.append(ftpManager.series2[i].x, ftpManager.series2[i].y)
      }

      // Update the time axis range to fit the data
      axisXdata1.min = new Date(ftpManager.series1[0].x)
      axisXdata1.max = new Date(ftpManager.series1[ftpManager.series1.length - 1].x)
      axisXdata2.min = new Date(ftpManager.series2[0].x)
      axisXdata2.max = new Date(ftpManager.series2[ftpManager.series2.length - 1].x)
    }
  }

  Column {
    anchors.centerIn: parent
    anchors.margins: 5
    spacing: 5

    ChartView {
      id: chartData1
      width: window.width - 40
      height: (window.height - anchors.margins * 2 - btnDownloadFTP.height - 30) / 2
      title: "Date"
      titleFont.bold: true
      titleFont.pointSize: 14
      antialiasing: true
      ValueAxis {
        id: axisYdata1
        min: 0
        max: 100
        gridVisible: true
        tickCount: 10
        titleText: "Data-1 Values"
        titleFont.bold: true
        titleFont.pointSize: 10
        titleFont.italic: false
      }

      DateTimeAxis {
        id: axisXdata1
        gridVisible: true
        format: "hh:mm:ss"
        tickCount: 10
        titleText: "Time"
        titleFont.bold: true
        titleFont.italic: false
        titleFont.pointSize: 10
      }

      LineSeries {
        id: lineSeriesData1
        color: "#2563eb"
        width: 2
        name: "Data-1 Values"
        axisX: axisXdata1
        axisY: axisYdata1
      }
    }

    ChartView {
      id: chartData2
      width: window.width - 40
      height: (window.height - anchors.margins * 2 - btnDownloadFTP.height - 30) / 2
      title: "Date"
      titleFont.bold: true
      titleFont.pointSize: 12
      antialiasing: true
      ValueAxis {
        id: axisYdata2
        min: 0
        max: 100
        gridVisible: true
        tickCount: 10
        titleText: "Data-2 Values"
        titleFont.bold: true
        titleFont.pointSize: 10
        titleFont.italic: false
      }

      DateTimeAxis {
        id: axisXdata2
        gridVisible: true
        format: "hh:mm:ss"
        tickCount: 10
        titleText: "Time"
        titleFont.bold: true
        titleFont.italic: false
        titleFont.pointSize: 10
      }

      LineSeries {
        id: lineSeriesData2
        color: "#dc2626"
        name: "Data-2 Values"
        width: 2
        axisX: axisXdata2
        axisY: axisYdata2
      }
    }

    Basic.Button {
      id: btnDownloadFTP
      width: 220
      height: 44
      text: qsTr("Download FTP Data")
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.topMargin: 10
      font.pixelSize: 14
      onClicked: {
        console.log("Download clicked")
        ftpManager.downloadFTPData()
      }
    }
  }
}