import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  GridView {
    id: gridview
    anchors.fill: parent

    Slider {
      id: slider
      y: 41
      width: parent.width*2/3
      height: 40
      wheelEnabled: false
      stepSize: 1
      anchors.horizontalCenter: parent.horizontalCenter
      rotation: 0
      value: 50

      Label {
        id: label0
        x: 195
        y: 73
        width: 400
        height: 40
        color: "#000000"
        text: "Slider Value = " + Math.round(slider.value)
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pointSize: 25
        anchors.horizontalCenter: parent.horizontalCenter
      }
      to: 100
    }

    RangeSlider {
      id: rangeSlider
      y: 301
      width: parent.width*2/3
      height: 40
      stepSize: 1
      anchors.horizontalCenter: parent.horizontalCenter
      first.value: 25
      second.value: 75

      Label {
        id: label1
        x: 195
        y: 73
        width: 400
        height: 40
        color: "#000000"
        text: qsTr("Range Slider")
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 25
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
      }
      to: 100
    }

    Connections {
      target: rangeSlider.first
      onValueChanged: {
        label1.text = "Range Slider = " +
                      Math.round(rangeSlider.first.value) + " to " +
                      Math.round(rangeSlider.second.value)
      }
    }
    Connections {
      target: rangeSlider.second
      onValueChanged: {
        label1.text = "Range Slider = " +
                      Math.round(rangeSlider.first.value) + " to " +
                      Math.round(rangeSlider.second.value)
      }
    }
  }
}
