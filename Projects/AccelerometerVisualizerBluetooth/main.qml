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
    y: 100
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
    y: 150
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
    x: 10
    y: 10
    width: root.width*2/3
    height: 50
    model: bluetoothManager.detectedDevices

  }
}
