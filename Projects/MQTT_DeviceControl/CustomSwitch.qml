import QtQuick
import QtQuick.Controls

// note this is not a item, this is a customized switch
// hence we don't need any custom signal and property alias in main file
Switch {
  id: control

  indicator: Rectangle {
    implicitHeight: 30
    implicitWidth: 60
    x: control.leftPadding
    y: parent.height/2 - height/2
    radius: width/2
    // color: control.checked ? "#1d5ffe" : "#333742"
    color: control.checked ? "#14a44d" : "#333742"
    border.width: control.checked ? 1 : 1
    // border.color: control.checked ? "#1d5ffe" : "#333742"
    border.color: control.checked ? "#14a44d" : "#333742"

    Rectangle {
      x: control.checked ? (parent.width-width) - 2 : 2
      width: 20
      height: 20
      radius: height/2
      color: control.checked ? "#332D2D" : "#7A859B"
      // color: control.checked ? "lightgreen" : "grey"
      anchors.verticalCenter: parent.verticalCenter
    }
  }

  contentItem: Label {
    text: control.text
    font.pixelSize: 16
    verticalAlignment: Text.AlignVCenter
    leftPadding: control.indicator.width + control.spacing
  }
}
