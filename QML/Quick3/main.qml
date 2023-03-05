import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  MyShape
  {
    id: shareCentral
    anchors.centerIn: parent
    color: "lightsteelblue"
    text: "Center"

//    Test Code to Check, if child is moving with parent or not
//    Rectangle
//    {
//      width: 25
//      height: 25
//      color: "darkgreen"
//      anchors.centerIn: parent
//    }
  }

  MyShape
  {
    id: shareTop
    text: "Top"
    color: "aquamarine"
    anchors.bottom: shareCentral.top
    anchors.left: shareCentral.left
  }

  MyShape
  {
    id: shareBottom
    text: "Bottom"
    color: "brown"
    anchors.top: shareCentral.bottom
    anchors.left: shareCentral.left
  }

  MyShape
  {
    id: shareLeft
    text: "Left"
    color: "darksalmon"
    anchors.top: shareCentral.top
    anchors.right: shareCentral.left
  }

  MyShape
  {
    id: shareRight
    text: "Right"
    color: "indianred"
    anchors.top: shareCentral.top
    anchors.left: shareCentral.right
  }
}
