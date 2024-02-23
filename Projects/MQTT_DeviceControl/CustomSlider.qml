import QtQuick
import QtQuick.Controls.Universal

Slider {
  id: control

  property color sliderColor: "#21be2b"

  width: parent.width
  height: parent.height
  from: 0
  to: 255
  value: 128
  stepSize: 1
  snapMode: Slider.SnapAlways

  background: Rectangle {
    id: bg
    x: control.leftPadding
    y: control.topPadding + control.availableHeight/2 - height/2
    implicitWidth: 80
    implicitHeight: 4
    width: control.availableWidth
    // width: parent.width
    height: implicitHeight
    color: "#bdbebf"

    Rectangle {
      width: control.visualPosition * parent.width
      height: parent.height
      color: sliderColor
      radius: 10
    }
  }

  contentItem: Label {
    id: lbl
    text: parent.value
    font.pixelSize: 20
    font.bold: true
    verticalAlignment: Text.AlignVCenter
    anchors.leftMargin: 10
    anchors.left: bg.right
    anchors.verticalCenter: bg.verticalCenter
  }
}

