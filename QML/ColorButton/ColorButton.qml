import QtQuick

Item {
  id: root
  property color colorBorder: "darkred"
  property color colorNormal: "indianred"
  property color colorPressed: "yellow"
  property color colorHover: "orange"
  property string source: ""

  // What is this??? This is a signal which will be emitted by this QML code
  // Here I am emitting this signal when button is pressed
  signal clicked()

  Rectangle {
    id: body
    radius: width
    color: root.colorNormal
    border.color: root.colorBorder
    border.width: 2
    anchors.fill: parent

    MouseArea {
      id: area
      anchors.fill: parent
      hoverEnabled: true
      onPressed: {
        body.color = root.colorPressed
        // emit the signal
        root.clicked();
      }
      onReleased: {
        body.color = root.colorHover
      }
      onEntered: {
        body.color = root.colorHover
      }
      onExited: {
        body.color = root.colorNormal
      }
    }

    Image {
      id: image
      anchors.fill: parent
      fillMode: Image.PreserveAspectFit
      source: root.source
    }
  }
}
