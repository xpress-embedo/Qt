import QtQuick
import QtQuick.Controls

Item {
  id: root
  property color colorBorder: "#9fa6b2"     // light gray
  property color colorNormal: "lightgrey"
  property color colorPressed: "darkgrey"
  property color colorHover: "#14a44d"      // greenish
  property string buttonText: "button"

  signal clicked()

  Rectangle {
    id: body
    anchors.fill: parent
    color: root.colorNormal
    border.color: root.colorBorder
    border.width: 0.5
    // radius: width/10
    Label {
      id: lblBody
      // text: "Hello"
      text: root.buttonText
      anchors.fill: parent
      font.pixelSize: 14
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      color: "black"
    }
    MouseArea {
      anchors.fill: parent
      hoverEnabled: true
      onPressed: {
        body.color = root.colorPressed
        // emit signal
        root.clicked()
      }
      onEntered: {
        body.color = root.colorHover
      }
      onExited: {
        body.color = root.colorNormal
      }
    }
  }
}
