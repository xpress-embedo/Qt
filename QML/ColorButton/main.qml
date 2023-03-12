import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Color Button Example")

  Column {
    id: column
    width: 200
    height: 230
    anchors.verticalCenter: parent.verticalCenter
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    ColorButton {
      id: colorButtonUp
      width: 100
      height: 100
      source: "qrc:/Images/up.png"
      anchors.horizontalCenter: parent.horizontalCenter
      onClicked: console.log("Up Clicked")
    }

    ColorButton {
      id: colorButtonDown
      width: 100
      height: 100
      source: "qrc:/Images/down.png"
      anchors.horizontalCenter: parent.horizontalCenter
      onClicked: console.log("Down Clicked")
    }
  }
}
