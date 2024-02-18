import QtQuick
import QtQuick.Window
import QtQuick.Controls

Window {
  id: root
  width: 480
  height: 640
  visible: true
  color: "#ffffff"
  title: qsTr("MQTT Device Control")

  Row {
    id: row1
    width: root.width/2
    height: root.height/10
    anchors.top: parent.top
    anchors.horizontalCenterOffset: 0
    anchors.topMargin: 80
    anchors.horizontalCenter: parent.horizontalCenter
    Column {
      id: col1
      Label {
        id: lblTemperature
        text: qsTr("Temperature:")
        font.pixelSize: 20
        color: "black"
      }

      Label {
        id: lblHumidity
        text: qsTr("Humidity:")
        font.pixelSize: 20
        color: "black"
      }
    }
    Column {
      id: col2
      Label {
        id: lblTemperatureValue
        text: qsTr("0 C")
        anchors.left: parent.left
        font.pixelSize: 20
        anchors.leftMargin: 20
        color: "black"
      }

      Label {
        id: lblHumidityValue
        text: qsTr("0 %")
        anchors.left: parent.left
        font.pixelSize: 20
        anchors.leftMargin: 20
        color: "black"
      }
    }
  }

  ColorSlider {
    id: redSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "red"
    anchors.verticalCenter: row1.verticalCenter
    anchors.verticalCenterOffset: 80
    anchors.horizontalCenter: parent.horizontalCenter
  }

  ColorSlider {
    id: greenSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "green"
    anchors.verticalCenter: redSlider.verticalCenter
    anchors.verticalCenterOffset: 40
    anchors.horizontalCenter: parent.horizontalCenter
  }

  ColorSlider {
    id: blueSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "blue"
    anchors.verticalCenter: greenSlider.verticalCenter
    anchors.verticalCenterOffset: 40
    anchors.horizontalCenter: parent.horizontalCenter
  }
}
