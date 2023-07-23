import QtQuick
import QtQuick3D
import QtQuick.Window

import com.company.serialmanager 1.0

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("FXOS8700 Data Visualizer")

  SerialManager {
    id: serialManager
    onRollChanged: {
      cubeModel.eulerRotation.x = roll;
      textRollValue.text = roll.toFixed(2)
    }
    onPitchChanged: {
      cubeModel.eulerRotation.z = (-1.0)*pitch;
      textPitchValue.text = pitch.toFixed(2)
    }
  }

  Node {
    id: standAloneScene
    Model {
      id: cubeModel
      position: Qt.vector3d( 0, 0, 0)
      source: "#Cube"
      materials: [
        // DefaultMaterial { diffuseColor: "indianred"}
        DefaultMaterial {
          diffuseMap: Texture {
            sourceItem: Item {
              anchors.fill: parent
              // layer.enabled: true
              Rectangle {
                anchors.fill: parent
                color: "white"
              }
              Image {
                anchors.fill: parent
                source: "qrc:/image/chip.png"
              }
              Text {
                width: parent.width
                anchors.bottom: parent.bottom
                anchors.left: parent.left
                color: "black"
                font.pixelSize: 50
                font.bold: true
                text: qsTr("Accelerometer Demo")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
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
      clearColor: "white"
      backgroundMode: SceneEnvironment.Color
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
    x: 250
    y: 20
    visible: true
    text: qsTr("Roll:")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
  }

  Text {
    id: textRollValue
    x: textRoll.x + 80
    y: textRoll.y
    visible: true
    text: qsTr("0")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
  }

  Text {
    id: textPitch
    x: 250
    y: 50
    visible: true
    text: qsTr("Pitch:")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
  }

  Text {
    id: textPitchValue
    x: textPitch.x + 80
    y: textPitch.y
    visible: true
    text: qsTr("0")
    font.pixelSize: 20
    horizontalAlignment: Text.AlignLeft
  }
}
