import QtQuick
import QtQuick.Controls 6.2

Page {
  width: 600
  height: 400

  title: qsTr("Home")

  Label {
    color: "#f91b02"
    text: qsTr("This is Page-2")
    font.pointSize: 15
    font.bold: true
    styleColor: "#f95030"
    anchors.centerIn: parent
  }
}
