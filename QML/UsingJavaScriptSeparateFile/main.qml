import QtQuick

import "code.js" as Code

Window {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Component.onCompleted: {
    Code.startup( root, box);
    // JavaScript Connection
    area.clicked.connect( Code.clicked );
  }

  Rectangle {
    id: box
    color: Code.swapColor(area)
    width: 100
    height: 100
    x: 0
    y: (parent.height/2) - (height/2)

    MouseArea {
      id: area
      anchors.fill: parent
      // Comment because we are using JavaScript QML Connections
      // onClicked: Code.performClick(root, box)
    }
  }
}
