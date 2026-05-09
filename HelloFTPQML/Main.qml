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

  Basic.Button {
    id: btnDownloadFTP
    width: 150
    height: 40
    text: qsTr("Download FTP")
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: parent.top
    anchors.topMargin: 40

    font.pixelSize: 14
    font.family: "Segoe UI"
    // font.weight: Font.Bold

    contentItem: Text {
      text: btnDownloadFTP.text
      font: btnDownloadFTP.font
      color: "white"
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      elide: Text.ElideRight
    }

    onClicked: {
      console.log("Download from FTP Started")
      ftpManager.downloadData()
    }
  }
}
