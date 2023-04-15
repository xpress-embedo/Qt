import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2

import SerialManager 1.0

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
    width: 100
    height: 30
  }

  Label {
    id: lbl_temperature
    x: 300
    y: 20
    width: 50
    height: 30
    text: qsTr("0.0 C")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }

  Label {
    id: lbl_temperature1
    x: 400
    y: 20
    width: 50
    height: 30
    text: qsTr("0 %")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }
}
