import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  BusyIndicator {
    id: busyIndicator
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
  }

  CheckBox {
    id: checkBox
    y: 25
    text: qsTr("Check Box")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  Button {
    id: button
    y: 72
    text: qsTr("Button")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  DelayButton {
    id: delayButton
    y: 121
    text: qsTr("Delay Button")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  Dial {
    id: dial
    x: 88
    y: 190
  }

  Label {
    id: label
    x: 34
    y: 37
    text: qsTr("This is a label")
  }

  Label {
    id: label1
    x: 34
    y: 60
    width: 189
    height: 37
    text: qsTr("This is a long label text, probably the longest ever.")
    wrapMode: Text.WordWrap
    color: "red"
  }

  Label {
    id: label2
    x: 34
    y: 103
    text: qsTr("This is <font color='blue'><b><i>HTML</i></h></font>")
    font.pointSize: 30
  }
}
