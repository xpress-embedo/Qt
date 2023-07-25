import QtQuick
import QtQuick3D
import QtQuick.Window

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Basic Asset")

//  View3D {
//    anchors.fill: parent
//    environment: SceneEnvironment {
//      clearColor: "#222222"
//      backgroundMode: SceneEnvironment.Color
//    }

//    Monkey {}
//  }

  View3D {
    anchors.fill: parent

    environment: SceneEnvironment {
      clearColor: "#222222"
      backgroundMode: SceneEnvironment.Color
    }

    Model {
      // source: "meshes/suzanne.mesh"
      source: Monkey{}
      scale: Qt.vector3d(2, 2, 2)
      eulerRotation.y: 30
      eulerRotation.x: -80
      materials: [ DefaultMaterial { diffuseColor: "yellow"; } ]
    }

    PerspectiveCamera {
      position: Qt.vector3d(0, 0, 15)
      Component.onCompleted: lookAt(Qt.vector3d(0, 0, 0))
    }

    DirectionalLight {
      eulerRotation.x: -20
      eulerRotation.y: 110
      castsShadow: true
    }
  }
}
