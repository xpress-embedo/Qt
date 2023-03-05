import QtQuick

Item
{
  id: root
  property color color: "darkgreen"
  property color hoverColor: "green"
  property color textColor: "white"
  property color textHoverColor: "black"
  property color clickColor: "orange"
  property alias title: display
  property alias area: mousearea

  Rectangle
  {
    height: root.height
    width: root.width
    color: root.color
    clip: true

    Text
    {
      id: display
      text: "Hello World"
      anchors.centerIn: parent
      color: root.textColor
      font.bold: true
    }

    MouseArea
    {
      id: mousearea
      anchors.fill: parent
      hoverEnabled: true

      onEntered:
      {
        parent.color = root.hoverColor
        display.color = root.textHoverColor
      }

      onExited:
      {
        parent.color = root.color
        display.color = root.textColor
      }

      onPressed:
      {
        parent.color = root.clickColor
      }

      onReleased:
      {
        parent.color = root.hoverColor
      }
    }
  }
}
