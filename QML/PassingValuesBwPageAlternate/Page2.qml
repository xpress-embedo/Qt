import QtQuick
import QtQuick.Controls 6.2

Page {
  id: page
  property alias name: myLabel.text
  width: 600
  height: 400
  header: Label {
    text: qsTr("Page-2")
    font.pixelSize: Qt.application.font.pixelSize * 2
    padding: 10
  }

  Label {
    color: "indianred"
    text: qsTr("You are on Page-2");
    anchors.horizontalCenter: parent.horizontalCenter
    font.pointSize: 15
    font.bold: true
  }

  Label {
    id: myLabel
    y: 74
    width: 250
    height: 40
    text: qsTr("Title")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    anchors.horizontalCenter: parent.horizontalCenter
    font.pointSize: 25
  }

  Button {
    id: button
    y: 141
    width: 150
    height: 40
    text: qsTr("Click Me")
    anchors.horizontalCenterOffset: 0
    anchors.horizontalCenter: parent.horizontalCenter
    onClicked: {
      name = "Hello World"
    }
  }

}
