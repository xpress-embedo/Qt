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

  property int redValue: 128
  property int greenValue: 128
  property int blueValue: 128

  function changeRectangleColor() {
    colorRectangle.color = Qt.rgba(redValue/255, greenValue/255, blueValue/255, 1)
  }

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
    onValueChanged: function(newValue) {
      console.log("Red Value: ", newValue);
      redValue = newValue;
      root.changeRectangleColor();
    }
    // the following method is deprecated, we need to use the above one
    /*
    onValueChanged: {
      console.log("New Value:", newValue)
    }
    */
  }

  ColorSlider {
    id: greenSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "green"
    anchors.verticalCenter: redSlider.verticalCenter
    anchors.verticalCenterOffset: 40
    anchors.horizontalCenter: parent.horizontalCenter
    onValueChanged: function(newValue) {
      console.log("Green Value: ", newValue);
      greenValue = newValue;
      root.changeRectangleColor();
    }
  }

  ColorSlider {
    id: blueSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "blue"
    anchors.verticalCenter: greenSlider.verticalCenter
    anchors.verticalCenterOffset: 40
    anchors.horizontalCenter: parent.horizontalCenter
    onValueChanged: function(newValue) {
      console.log("Blue Value: ", newValue);
      blueValue = newValue;
      root.changeRectangleColor();
    }
  }

  Rectangle {
    id: colorRectangle
    width: root.width/2
    height: root.height/8
    anchors.verticalCenter: blueSlider.verticalCenter
    anchors.verticalCenterOffset: 80
    anchors.horizontalCenter: parent.horizontalCenter
    border.color: "black"
  }

  Component.onCompleted: {
    root.changeRectangleColor();
  }
}
