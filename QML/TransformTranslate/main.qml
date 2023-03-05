import QtQuick

Window {
  width: 800
  height: 640
  visible: true
  title: qsTr("Hello World")

  Item
  {
    id: root
    rotation: 0
    anchors.centerIn: parent
    anchors.fill: parent

    Rectangle
    {
      id: yellowRect
      width: 300
      height: 300
      radius: width
      color: "yellow"
      opacity: 0.6
      border.width: 2
      border.color: "black"
      anchors.centerIn: parent
      // Translate or Offset the item without changing it's x and y position
      // We need this because anchor is set, and once anchor is set, changing
      // x and y doesn't have any effect, hence this is needed
      transform: Translate { y: -100 }
    }

    Rectangle
    {
      id: blueRect
      width: 300
      height: 300
      radius: width
      color: "blue"
      opacity: 0.6
      border.width: 2
      border.color: "black"
      anchors.centerIn: parent
      transform: Translate { y: 100; x: -100 }
    }

    Rectangle
    {
      id: redRect
      width: 300
      height: 300
      radius: width
      color: "red"
      opacity: 0.6
      border.width: 2
      border.color: "black"
      anchors.centerIn: parent
      transform: Translate { y: 100; x: 100 }
    }

    Rectangle
    {
      id: centerArea
      width: 50
      height: 50
      radius: width
      color: "white"
      opacity: 1
      border.width: 2
      border.color: "black"
      anchors.centerIn: parent
    }

    Rectangle
    {
      id: centerCircle
      width: 5
      height: 5
      radius: width
      color: "gray"
      opacity: 1
      border.width: 2
      border.color: "black"
      anchors.centerIn: parent
    }

    RotationAnimator
    {
      target: root
      from: 360
      to: 0
      duration: 5000
      direction: RotationAnimator.Counterclockwise
      loops: Animation.Infinite
      running: true
    }
  }
}
