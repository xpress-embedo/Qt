import QtQuick
import QtQuick.Controls
import QtCharts

Window {
  id: window
  width: 640
  height: 840
  visible: true
  title: qsTr("FTP Data Visualizer")
  color: "#f3f6fb"

  Button {
    id: btnDownloadFTP
    width: 220
    height: 52
    text: qsTr("Download FTP")
    anchors.horizontalCenter: parent.horizontalCenter
    anchors.top: parent.top
    anchors.topMargin: 28

    font.pixelSize: 16
    font.family: "Segoe UI"
    font.weight: Font.DemiBold
    hoverEnabled: true

    contentItem: Text {
      text: btnDownloadFTP.text
      font: btnDownloadFTP.font
      color: "#ffffff"
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      elide: Text.ElideRight
    }

    background: Rectangle {
      radius: 14
      border.width: 1
      border.color: btnDownloadFTP.down ? "#0c4a6e" : "#1d4ed8"
      gradient: Gradient {
        GradientStop { position: 0.0; color: btnDownloadFTP.down ? "#2563eb" : (btnDownloadFTP.hovered ? "#3b82f6" : "#2563eb") }
        GradientStop { position: 1.0; color: btnDownloadFTP.down ? "#1d4ed8" : (btnDownloadFTP.hovered ? "#1d4ed8" : "#1e40af") }
      }
    }

    scale: btnDownloadFTP.down ? 0.98 : 1.0
    Behavior on scale {
      NumberAnimation {
        duration: 120
        easing.type: Easing.OutCubic
      }
    }

    onClicked: {
      console.log("Download from FTP Started")
      ftpManager.downloadData()
    }
  }
}
