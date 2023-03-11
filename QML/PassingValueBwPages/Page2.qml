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
    width: 250
    text: qsTr("Label")
    anchors.verticalCenter: parent.verticalCenter
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 25
    font.bold: true
    anchors.horizontalCenter: parent.horizontalCenter
  }
}
