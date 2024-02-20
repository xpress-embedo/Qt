import QtQuick
import QtQuick.Controls

Switch {
  id: control
  indicator: Rectangle {
    implicitHeight: 40
    implicitWidth: 80
    x: control.leftPadding
    y: parent.height/2 - height/2
    radius: width/2
    color: control.checked ? "#1d5ffe" : "#333742"
    // color: control.checked ? "#14a44d" : "#333742"
    border.width: control.checked ? 2 : 1
    border.color: control.checked ? "#1d5ffe" : "#333742"

    Rectangle {
      x: control.checked ? (parent.width-width) - 2 : 2
      width: 30
      height: 30
      radius: height/2
      color: control.checked ? "#332D2D" : "#7A859B"
      anchors.verticalCenter: parent.verticalCenter
    }
  }

  contentItem: Label {
    text: control.text
    font.pixelSize: 20
    verticalAlignment: Text.AlignVCenter
    leftPadding: control.indicator.width + control.spacing
  }
}
