import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  MyBox {
    id: myBox
    x: 220
    y: 140
    width: 200
    height: 200

    MouseArea {
      id: mouseArea
      anchors.fill: parent
      onClicked:
      {
        console.log("clicked")
        if( parent.state === "on" )
        {
          parent.state = "off";
        }
        else
        {
          parent.state = "on"
        }
      }
    }
  }

  Image {
    id: image
    anchors.fill: parent
    // source: "images/Dog.jpg"
    source: "https://upload.wikimedia.org/wikipedia/commons/9/99/Brooks_Chase_Ranger_of_Jolly_Dogs_Jack_Russell.jpg"
    fillMode: Image.PreserveAspectFit
    // Wanted to show image below MyBox
    z: myBox.z++
  }
}
