import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  color: "#ffffff"
  title: qsTr("Hello World")

  Row {
    id: row
    x: 0
    y: 0
    width: 640
    height: 45
    spacing: 5

    Button {
      id: btnCat
      width: 120
      height: 40
      text: qsTr("Cat")

      Connections {
        target: btnCat
        onClicked: {
          console.log("btnCat.clicked")
          image.source = "qrc:/Images/Cat.png";
        }
      }
    }

    Button {
      id: btnDog
      width: 120
      height: 40
      text: qsTr("Dog")

      Connections {
        target: btnDog
        onClicked: {
          console.log("btnDog.clicked")
          image.source = "qrc:/Images/Dog.png";
        }
      }
    }

    Button {
      id: btnFish
      width: 120
      height: 40
      text: qsTr("Fish")

      Connections {
        target: btnFish
        onClicked: {
          console.log("btnFish.clicked")
          image.source = "qrc:/Images/Fish.png";
        }
      }
    }

    Button {
      id: btnPenguin
      width: 120
      height: 40
      text: qsTr("Penguin")
      flat: false

      Connections {
        target: btnPenguin
        onClicked: {
          console.log("btnPenguin.clicked")
          image.source = "qrc:/Images/penguin.jpeg";
        }
      }
    }
  }

  Image {
    id: image
    x: 0
    y: 51
    width: 640
    height: 429
    source: "qrc:/Images/Cat.png"
    fillMode: Image.PreserveAspectFit
  }
}
