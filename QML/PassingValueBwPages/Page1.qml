import QtQuick
import QtQuick.Controls 6.2

Page {
  id: page
  property alias name: textField.text

  width: 600
  height: 400
  header: Label {
    text: qsTr("Page-1")
    font.pixelSize: Qt.application.font.pixelSize * 2
    padding: 10
  }

  Label {
    color: "indianred"
    text: qsTr("You are on Page-1");
    anchors.horizontalCenter: parent.horizontalCenter
    font.pointSize: 15
    font.bold: true
  }

  Column {
    id: column
    width: 200
    height: 90
    anchors.verticalCenter: parent.verticalCenter
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      width: 250
      height: 30
      text: qsTr("Enter Your Name")
      font.pointSize: 15
    }

    TextField {
      id: textField
      width: 250
      height: 30
      font.pointSize: 15
      placeholderText: qsTr("Embedded Laboratory")
    }
  }
}
