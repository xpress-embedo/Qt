import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import com.company.serialmanager 1.0

Window {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Temperature and Humidity Plot")

  property bool connectStatus: false

  SerialManager {
    id: serialManager
    onConnectStatusChanged: function(status) {
      // Here I used root because if root not use then this class also has a
      // method connectStatus, and hence to differentiate between the two
      root.connectStatus = status;
      console.log("QML Message Status Changed", root.connectStatus);
      if( root.connectStatus == false )
      {
        // Set the text of button as "Connect" and enable ComboBox
        btn_connect_disconnect.text = "Connect";
        cb_com_port.enabled = true;
      }
      else
      {
        // Set the text of button as "Connect" and enable ComboBox
        btn_connect_disconnect.text = "Disconnect";
        cb_com_port.enabled = false;
      }
    }

    onTemperatureChanged: {
      lbl_temperature.text = serialManager.temperature + qsTr("\xB0 C")
    }

    onHumidityChanged: {
      lbl_humidity.text = serialManager.humidity + " %";
    }
  }

  Button {
    id: btn_connect_disconnect
    x: 20
    y: 20
    width: 100
    height: 30
    text: qsTr("Connect")
    onClicked: {
      console.log("connectStatus = ", connectStatus );
      if( root.connectStatus == false ) {
        console.log("Clicked: true")
        // connectStatus = true;
        // I am not changing the status here, as it miight be possible that port
        // didn't opened, so it will be updated in the emitted signal
        serialManager.setConnectStatus(true);
      }
      else {
        console.log("Clicked: false")
        // connectStatus = false;
        // I am not changing the status here, as it miight be possible that port
        // didn't opened, so it will be updated in the emitted signal
        serialManager.setConnectStatus(false);
      }
    }
  }

  ComboBox {
    id: cb_com_port
    x: 160
    y: 20
    width: 80
    height: 30
    displayText: qsTr("COM1")
    model: ListModel {
      ListElement { text: "COM1" }
      ListElement { text: "COM2" }
      ListElement { text: "COM3" }
      ListElement { text: "COM4" }
      ListElement { text: "COM5" }
      ListElement { text: "COM6" }
      ListElement { text: "COM7" }
      ListElement { text: "COM8" }
    }
  }

  Label {
    id: lbl_temp
    x: 260
    y: 20
    width: 110
    height: 30
    color: "indianred"
    text: qsTr("Temperature:")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }


  Label {
    id: lbl_temperature
    x: 380
    y: 20
    width: 60
    height: 30
    color: "indianred"
    // Both are ways to print degree symbol
    // text: qsTr("0.0") + qsTr("\u2103")
    text: qsTr("0.0") + qsTr("\xB0 C")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }


  Label {
    id: lbl_humid
    x: 450
    y: 20
    width: 80
    height: 30
    color: "indianred"
    text: qsTr("Humidity:")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }

  Label {
    id: lbl_humidity
    x: 530
    y: 20
    width: 60
    height: 30
    color: "indianred"
    text: qsTr("0 %")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }
}
