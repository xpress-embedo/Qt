import QtQuick
import QtQuick3D
import QtQuick.Window

import com.company.serialmanager 1.0

Window {
  width: 1280
  height: 720
  visible: true
  title: qsTr("FXOS8700 Data Visualizer")

  SerialManager {
    id: serialManager
    onRollChanged: {
      cubeModel.eulerRotation.z = roll
    }
    onPitchChanged: {
      cubeModel.eulerRotation.y = pitch
    }
  }

  Node {
    id: standAloneScene
    PerspectiveCamera {
      position: Qt.vector3d(0, 200, 300)
      eulerRotation.x: -30
    }

    DirectionalLight {
      eulerRotation.x: -30
      eulerRotation.y: -70
    }

    Model {
      id: cubeModel
      position: Qt.vector3d( 0, 0, 0)
      source: "#Cube"
      // scale: Qt.vector3d(1, 1, 0.5)
      materials: [
        DefaultMaterial { diffuseColor: "indianred"}
      ]
//      rotation: {
//        var rollRadians = (roll)*Math.PI/180;
//        var pitchRadians = (pitch)*Math.PI/180;
//        var yawRadians = 0; // No yaw rotation
//        Qt.quaternionFromEulerAngles(rollRadians, pitchRadians, yawRadians)
//      }
//      SequentialAnimation on y {
//        loops: Animation.Infinite
//        NumberAnimation {
//          duration: 3000
//          to: -150
//          from: 150
//          easing.type: Easing.InQuad
//        }
//        NumberAnimation {
//          duration: 3000
//          to: 150
//          from: -150
//          easing.type: Easing.InQuad
//        }
//      }
//      SequentialAnimation on x {
//        loops: Animation.Infinite
//        NumberAnimation {
//          duration: 3000
//          to: -150
//          from: 150
//          easing.type: Easing.InQuad
//        }
//        NumberAnimation {
//          duration: 3000
//          to: 150
//          from: -150
//          easing.type: Easing.InQuad
//        }
//      }
//      SequentialAnimation on z {
//        loops: Animation.Infinite
//        NumberAnimation {
//          duration: 3000
//          to: -150
//          from: 150
//          easing.type: Easing.InQuad
//        }
//        NumberAnimation {
//          duration: 3000
//          to: 150
//          from: -150
//          easing.type: Easing.InQuad
//        }
//      }
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

    MouseArea {
      anchors.fill: parent
      onClicked: {
        // rotate the cube model by 30 degrees in x-direction
        cubeModel.eulerRotation.x += 30
      }
      onDoubleClicked:
      {
        cubeModel.eulerRotation.y += 30
      }
    }
  }
}
