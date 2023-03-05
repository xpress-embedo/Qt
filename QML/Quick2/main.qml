import QtQuick 2.12
import QtQuick.Window 2.12

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Rectangle
  {
    id: myShape
    width: 100
    height: 100
    color: "pink"

    // JavaScript Function
    function update()
    {
      console.log(x + " X " + y );
      label.text = Math.round(x) + " X " + Math.round(y);
    }

    x: 100
    y: 100

    // anchors.centerIn: parent
    /* I want to load something when this component is loaded
    in this case if don't use this, we will get text on the rectangle
    but if this is not commented, update function is called, and it will
    update the x and y position on the rectangle */
    // Also I don't know why QT Creator is giving M16 error here, but
    // this is doing it task
    Component.onCompleted: update()
    onXChanged: update()
    onYChanged: update()

    Text
    {
      id: label
      text: qsTr("text")
      anchors.centerIn: parent
    }

    MouseArea
    {
      anchors.fill: parent
      // what we are doing when dragging, here we are dragging the parent i.e. Rectangle
      drag.target: parent
    }
  }

  // Row --> row and column are relatable
  Column
  {
    // anchors.centerIn: parent
    spacing: 2
    MyShape
    {
      color: "red"
    }

    MyShape
    {
      color: "lightgreen"
    }

    MyShape
    {
      color: "lightblue"
    }
  }

  Grid
  {
    anchors.centerIn: parent
    spacing: 2
    rows: -1    // specify -1 for auto alignment
    columns: 5
    Rectangle { color: "gray"; width: 50; height: 50}
    Rectangle { color: "blue"; width: 50; height: 50}
    Rectangle { color: "magenta"; width: 50; height: 50}
    Rectangle { color: "black"; width: 50; height: 50}
    Rectangle { color: "teal"; width: 50; height: 50}
    Rectangle { color: "orange"; width: 50; height: 50}
  }

  Rectangle
  {
    color: "pink"
    x: 250
    y: 250
    width: 200
    height: 200

    clip: false

    Flow
    {
      anchors.centerIn: parent
      /* Flow.LeftToRight (default)
      */
      flow: Flow.TopToBottom
      spacing: 2

      MyShape { color: "red" }
      MyShape { color: "blue" }
      MyShape { color: "lightblue" }
      MyShape { color: "yellow" }
      MyShape { color: "orange" }
      MyShape { color: "black" }
      MyShape { color: "teal" }
      MyShape { color: "grey" }
    }
  }
}
