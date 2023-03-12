import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Dynamically Creating Number Pad")

  Column {
    id: column
    width: 200
    height: 250
    anchors.verticalCenter: parent.verticalCenter
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      width: 200
      height: 40
      color: "#1a5fb4"
      text: qsTr("Status")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      font.bold: true
      font.pointSize: 25
      anchors.horizontalCenter: parent.horizontalCenter
    }

    NumberPad {
      id: numberPad
      width: 200
      height: 200
      anchors.horizontalCenter: parent.horizontalCenter
      onClicked: function(value) {
        label.text = value
      }
//      This is deprecated
//      onClicked: {
//        label.text = value
//      }
    }
  }
}
