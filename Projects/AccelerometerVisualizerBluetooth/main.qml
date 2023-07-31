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

  BluetoohManager {
    id: bluetoothManager
    onDetectedDevicesListChanged: {
      cbdeviceName.model = bluetoothManager.detectedDevicesList;
    }
  }

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

  ComboBox {
    id: cbdeviceName
    y: 20
    width: root.width*8/10
    height: 40
    anchors.horizontalCenter: parent.horizontalCenter
    model: bluetoothManager.detectedDevices
    background: Rectangle {
      color: "white"
    }
  }

  Button {
    id: btnConnect
    x: 0
    y: cbdeviceName.y + 100
    width: cbdeviceName.width/2.5
    height: 40
    text: qsTr("Connect")
  }

  Button {
    id: btnDisconnect
    anchors.horizontalCenter: cbdeviceName.horizontalCenter
    y: btnConnect.y
    width: btnConnect.width
    height: 40
    text: qsTr("Disconnect")
    enabled: false
  }

  Button {
    id: btnSearch
    x: root.width - btnSearch.width
    y: btnConnect.y
    width: btnConnect.width
    height: 40
    text: qsTr("Search")
    enabled: false
  }
}
