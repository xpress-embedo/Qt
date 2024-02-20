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
    anchors.top: colConnectDisconnect.bottom
    anchors.topMargin: 40
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 10
    Column {
      id: col1
      spacing: 10
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
      spacing: 10
      Label {
        id: lblTemperatureValue
        width: 80
        text: qsTr("0 C")
        anchors.left: parent.left
        font.pixelSize: 20
        anchors.leftMargin: 20
        color: "black"
      }

      Label {
        id: lblHumidityValue
        width: 80
        text: qsTr("0 %")
        anchors.left: parent.left
        font.pixelSize: 20
        anchors.leftMargin: 20
        color: "black"
      }
    }
  }


  CustomSwitch {
    id: switchLed
    width: 100
    height: 40
    anchors.verticalCenter: row1.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    antialiasing: true
    anchors.verticalCenterOffset: 80
    text: qsTr("LED Switch")
  }

  ColorSlider {
    id: redSlider
    width: root.width/2
    height: root.height/15
    sliderColor: "red"
    anchors.verticalCenter: switchLed.verticalCenter
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

  Row {
    id: colConnectDisconnect
    spacing: 40
    width: root.width/2
    anchors.top: parent.top
    bottomPadding: 0
    padding: 10
    leftPadding: 0
    rightPadding: 0
    topPadding: 0
    antialiasing: true
    layoutDirection: Qt.LeftToRight
    anchors.topMargin: 40
    anchors.horizontalCenter: parent.horizontalCenter

    CustomButton {
      id: btnConnect
      width: 100
      height: 40
      buttonText: "Connect"
      onClicked: {
        console.log("Connect Button Clicked")
      }
    }

    CustomButton {
      id: btnDisconnect
      width: 100
      height: 40
      buttonText: "Disconnect"
      onClicked: {
        console.log("Disconnect Button Clicked")
      }
    }
  }

  Component.onCompleted: {
    root.changeRectangleColor();
  }
}
