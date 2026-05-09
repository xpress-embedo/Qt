import QtQuick
import QtQuick.Controls
import QtCharts

Window {
  id: window
  width: 640
  height: 840
  visible: true
  title: qsTr("FTP Data Visualizer")

  Button {
    id: btnDownloadFTP
    width: 100
    height: 30
    text: qsTr("Download FTP")
    anchors.horizontalCenter: parent.horizontalCenter
    onClicked: {
      console.log("Download from FTP Started")
    }
  }
}
