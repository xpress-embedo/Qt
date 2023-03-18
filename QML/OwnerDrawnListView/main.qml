import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Owner Drawn List View")

  ListView {
    id: listView
    anchors.fill: parent
    anchors.rightMargin: 20
    anchors.leftMargin: 20
    anchors.bottomMargin: 20
    anchors.topMargin: 20
    delegate: ColorDelegate {}
    model: ColorModel {}
  }
}
