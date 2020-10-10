import QtQuick 2.12
import QtQuick.Window 2.12

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")
  color: "gray"
  Text {
    id: textName
    z: 1
    // This is used to set the stacking order of sibling items
    // Items with higher stacking value are drawn on top of sliblings with a lower stacking order.
    text: qsTr("Hello World from QML")
  }

  Rectangle {
    id: rect1
    x: 0; y: 0; z: 0
    height: Window.height/2
    width: Window.width/2
    color: "lightblue"
  }

  Rectangle {
    id: rect2
    x: rect1.width
    y: rect2.height
    z: 1
    height: Window.height/2
    width: Window.width/2
    color: "green"
    clip: true

    // Child Rectangle-1
    Rectangle {
      id: rect2child1
      x: rect2.width/4
      y: rect2.height/4
      height: rect2.height/2
      width: rect2.width/2
      color: "red"
    }
    // Child Rectangle-2
    // here I created a similar child elemet but with -ve x-axis
    // this is done to demonstrate the usage of clip property
    Rectangle {
      id: rect2child2
      x: -rect2.width/4
      y: rect2.height/4
      height: rect2.height/2
      width: rect2.width/2
      color: "pink"
    }
  }
}
