import QtQuick

Item
{
  id: root
  width: 100
  height: 50
  property color color: "#C0C0C0"
  property color colorClicked: "green"
  property string title: "Click Me"

  Rectangle
  {
    id: myRec
    anchors.fill: parent
    // color: parent.color
    color: root.color

    Text
    {
      id: display
      text: root.title
      anchors.centerIn: parent
    }

    MouseArea
    {
      id: mouseArea
      anchors.fill: parent
      onPressed: parent.color = root.colorClicked
      onReleased: parent.color = root.color
    }
  }
}
