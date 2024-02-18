import QtQuick
import QtQuick.Controls

Item {
  id: root
  property color sliderColor: "#21be2b"
  signal valueChanged(int newValue)

  Column {
    id: column
    Slider {
      id: slider
      width: root.width * 9/10
      // height width and anchors will be controlled from calling functions
      // width: root.width/2
      // height: root.height/15
      // anchors.verticalCenter: row1.verticalCenter
      // anchors.verticalCenterOffset: 80
      // anchors.horizontalCenter: parent.horizontalCenter
      snapMode: RangeSlider.SnapAlways
      stepSize: 1
      to: 255
      value: 128
      background: Rectangle {
        x: slider.leftPadding
        y: slider.topPadding + slider.availableHeight / 2 - height / 2
        implicitWidth: 100
        implicitHeight: 4
        width: slider.availableWidth
        height: implicitHeight
        radius: 2
        color: "#bdbebf"

        Rectangle {
          width: slider.visualPosition * parent.width
          height: parent.height
          // color: "#21be2b"
          color: sliderColor
          radius: 10
        }
      }
      onValueChanged: {
        lblSliderValue.text = slider.value
        // emit the signal
        root.valueChanged(slider.value)
      }
    }

    Label {
      id: lblSliderValue
      width: root.width/10
      text: "128"
      anchors.verticalCenter: slider.verticalCenter
      anchors.left: slider.right
      font.pixelSize: 20
      anchors.leftMargin: 40
      font.bold: true
    }
  }
}
