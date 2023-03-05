import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  property string thekey: "special key here"
  property color goalOn: "green"
  property color goalOff: "indianred"
  property color ballOn: "yellow"
  property color ballOff: "orange"

  DropArea
  {
    id: dropZone
    anchors.top: parent.top
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    width: 300
    Drag.keys: [thekey]
    onDropped:
    {
      console.log("dropped")
      goal.color = goalOn
    }

    Rectangle
    {
      id: goal
      anchors.fill: parent
      color: goalOff
      border.color: "black"
      border.width: 2
    }
  }

  Rectangle
  {
    id: ball
    width: 100
    height: 100
    radius: width
    x: 25
    y: parent.height/2 - height/2
    color: ballOff
    border.color: "black"
    border.width: 2

    Drag.active: dragArea.drag.active
    Drag.keys: [thekey]

    Text
    {
      id: title
      anchors.centerIn: parent
      text: Math.round(parent.x) + " x " + Math.round(parent.y)
    }
    MouseArea
    {
      id: dragArea
      anchors.fill: parent
      drag.target: parent
      onPressed:
      {
        parent.color = ballOn
        goal.color = goalOff
      }
      onReleased:
      {
        parent.color = ballOff
        // when we release this we will call the parent drag drop function
        // this drop function will do some internal maths and checks if in
        // a drop area of drop zone, and if yes, then corresponding function
        // is called
        parent.Drag.drop()
      }
    }
  }
}
