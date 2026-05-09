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

  Column {
    anchors.centerIn: parent
    spacing: 18

    ChartView {
      id: chartData1
      width: 560
      height: 220
      title: "Date"
      titleFont.bold: true
      titleFont.pointSize: 12
      antialiasing: false
      ValueAxis {
        id: axisYdata1
        min: 0
        max: 100
        gridVisible: true
        tickCount: 7
        titleText: "Data-1 Values"
        titleFont.bold: true
        titleFont.pointSize: 10
        titleFont.italic: true
      }

      DateTimeAxis {
        id: axisXdata1
        gridVisible: true
        format: "hh:mm:ss"
        tickCount: 10
        titleText: "Time"
        titleFont.bold: true
        titleFont.italic: true
        titleFont.pointSize: 10
      }

      LineSeries {
        id: lineSeriesData1
        name: "Data-1 Values"
        axisX: axisXdata1
        axisY: axisYdata1
      }
    }

    ChartView {
      id: chartData2
      width: 560
      height: 220
      title: "Date"
      titleFont.bold: true
      titleFont.pointSize: 12
      antialiasing: false
      ValueAxis {
        id: axisYdata2
        min: 0
        max: 100
        gridVisible: true
        tickCount: 7
        titleText: "Data-1 Values"
        titleFont.bold: true
        titleFont.pointSize: 10
        titleFont.italic: true
      }

      DateTimeAxis {
        id: axisXdata2
        gridVisible: true
        format: "hh:mm:ss"
        tickCount: 10
        titleText: "Time"
        titleFont.bold: true
        titleFont.italic: true
        titleFont.pointSize: 10
      }

      LineSeries {
        id: lineSeriesData2
        name: "Data-2 Values"
        axisX: axisXdata1
        axisY: axisYdata1
      }
    }

    Basic.Button {
      id: btnDownloadFTP
      width: 220
      height: 44
      text: qsTr("Download FTP Data")
      anchors.horizontalCenter: parent.horizontalCenter
      font.pixelSize: 14
      onClicked: {
        console.log("Download clicked")
        ftpManager.downloadData()
      }
    }
  }
}