import QtQuick
import QtQuick3D
import QtQuick.Window
import QtQuick.Controls

import com.company.bluetoothmanager 1.0

Window {
  id: root
  width: 300
  height: 600
  visible: true
  title: qsTr("Accelerometer Data Visualizer")

  Node {
    id: standAloneScene
    Model {
      id: cubeModel
      position: Qt.vector3d( 0, 0, 0)
      scale: Qt.vector3d( 1, 0.25, 0.5)
      source: "#Cube"
      materials: [
        // DefaultMaterial { diffuseColor: "indianred"}
        DefaultMaterial {
          diffuseMap: Texture {
            sourceItem: Item {
              anchors.fill: parent
              Rectangle {
                anchors.fill: parent
                color: "white"
              }
              Image {
                anchors.fill: parent
                source: "qrc:/Images/chip.png"
              }
            }
          }
        }
      ]
    }
  }

  View3D {
    id: view
    anchors.fill: parent
    scale: 1
    environment: SceneEnvironment {
      clearColor: "#222222"
      backgroundMode: SceneEnvironment.Color
      // No Antialiasing
      // antialiasingMode: SceneEnvironment.NoAA
      // Super Sample Antialiasing
      antialiasingMode: SceneEnvironment.SSAA
      // Multi Sample Antialiasing
      // antialiasingMode: SceneEnvironment.MSAA

      // Antialiasing Quality (Medium, High, VeryHigh)
      antialiasingQuality: SceneEnvironment.VeryHigh
    }
    importScene: standAloneScene
    PerspectiveCamera {
      position: Qt.vector3d(0, 200, 300)
      eulerRotation.x: -30
    }

    DirectionalLight {
      eulerRotation.x: -30
      eulerRotation.y: -70
    }
  }

  Text {
    id: textRoll
    x: root.width/2 - 60
    y: 200
    width: 60
    height: 25
    visible: true
    text: qsTr("Roll:")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
    color: "white"
  }

  Text {
    id: textRollValue
    x: textRoll.x + 80
    y: textRoll.y
    width: 60
    height: 25
    visible: true
    text: qsTr("0")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
    color: "white"
  }

  Text {
    id: textPitch
    x: root.width/2 - 60
    y: 240
    width: 60
    height: 25
    visible: true
    text: qsTr("Pitch:")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
    color: "white"
  }

  Text {
    id: textPitchValue
    x: textPitch.x + 80
    y: textPitch.y
    width: 60
    height: 25
    visible: true
    text: qsTr("0")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
    color: "white"
  }

  BluetoohManager {
    id: bluetoothManager
    onDetectedDevicesListChanged: {
      cbdeviceName.model = bluetoothManager.detectedDevicesList;
    }
    onSelectedDeviceChanged: {
      console.log("Selected Device Changed");
    }
    onConnStatusChanged: {
      console.log("Connection Status Changed");
      if( bluetoothManager.connStatus == true )
      {
        btnConnect.enabled = false;
        btnDisconnect.enabled = true;
        cbdeviceName.enabled = false;
        btnSearch.enabled = false;
      }
      else
      {
        btnConnect.enabled = true;
        btnDisconnect.enabled = false;
        btnSearch.enabled = true;
        cbdeviceName.enabled = true;
      }
    }
    onRollChanged:
    {
      cubeModel.eulerRotation.x = roll;
      textRollValue.text = roll.toFixed(2)
    }
    onPitchChanged: {
      cubeModel.eulerRotation.z = (-1.0)*pitch;
      textPitchValue.text = pitch.toFixed(2)
    }
  }

  ComboBox {
    id: cbdeviceName
    y: 20
    width: root.width*8/10
    height: 40
    font.pointSize: 14
    anchors.horizontalCenter: parent.horizontalCenter
    model: bluetoothManager.detectedDevices
    background: Rectangle {
      color: "white"
    }
    onCurrentTextChanged: {
      console.log("Device Selected: ", cbdeviceName.currentText );
      // TODO: not able to understand why this is not working, in previous
      // projects it was working, so as a work around using the selectedDevice
      // bluetoothManager.setSelectedDevice(cbdeviceName.currentText);
      bluetoothManager.selectedDevice = cbdeviceName.currentText;
    }
  }

  Button {
    id: btnConnect
    x: 0
    y: cbdeviceName.y + 100
    width: cbdeviceName.width/2.5
    height: 40
    text: qsTr("Connect")
    font.pointSize: 12
    background: Rectangle {
      anchors.fill: parent
    }
    onClicked: {
      bluetoothManager.connStatus = true;
    }
  }

  Button {
    id: btnDisconnect
    anchors.horizontalCenter: cbdeviceName.horizontalCenter
    y: btnConnect.y
    width: btnConnect.width
    height: 40
    text: qsTr("Disconnect")
    font.pointSize: 12
    enabled: false
    background: Rectangle {
      anchors.fill: parent
    }
    onClicked: {
      enabled = false
      bluetoothManager.connStatus = false;
    }
  }

  Button {
    id: btnSearch
    x: root.width - btnSearch.width
    y: btnConnect.y
    width: btnConnect.width
    height: 40
    text: qsTr("Search")
    font.pointSize: 12
    enabled: true
    background: Rectangle {
      anchors.fill: parent
    }
    onClicked: {
      console.log("Triggering Search Again");
      bluetoothManager.searchButtonPressed();
    }
  }
}
