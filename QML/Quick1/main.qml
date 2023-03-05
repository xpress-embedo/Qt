import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Image {
    id: image
    source: "https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg"
    width: 150
    height: 100
    x: 100
    y: 50
    z: 2    // lower the number, lower the layer

    // this rectangle object is the child of the image object
    Rectangle {
      color: "pink"
      width: parent.width/2
      height: parent.height/2
      // x,y are in relation with the parent not with the main window
      // x: 50
      // y: 50
      anchors.centerIn: parent
      opacity: 0.9
    }
  }

  Rectangle {
    color: "red"
    width: 50
    height: 50
    x: 300
    y: 100
    opacity: 0.9
    z: 1
    // Below we see the example of TapHandler which is very basic
    // now will explore the MouseArea
    MouseArea
    {
      id: myMouse
      anchors.fill: parent
      acceptedButtons: Qt.LeftButton | Qt.RightButton
      onClicked:
      {
        console.log("Clicked: " + mouse.button)
        if( mouse.button === Qt.LeftButton )
        {
          parent.color = "green"
        }
        else
        {
          parent.color = "blue"
        }
      }

      onDoubleClicked:
      {
        console.log("Double Click: " + mouse.button)
      }

      // if don't enable the hover on, then the position x and y will be shown on when we press the mouse click and drag
      hoverEnabled: true
      onPositionChanged:
      {
        console.log("Position X: " + mouseX + " Position Y: " + mouseY)
      }

      onEntered: parent.color = "orange"
      onExited: parent.color = "red"
    }
  }

  Rectangle {
    width: 50
    height: 50
    x: 300
    y: 20
    opacity: 0.9
    z: 0
    color: inputHandler.pressed ? "red" : "blue"

    TapHandler {
      id: inputHandler
    }
  }

  // There is no circle in QML, but we can use Rectangle object with radius parameter
  Rectangle {
    width: 100
    height: 100
    x: 400
    y: 100
    color: "pink"
    visible: true

    border.color: "#000000"
    border.width: 2

    radius: 50

    gradient: Gradient {
      GradientStop {position: 0.0; color: "red"; }
      GradientStop {position: 1.0; color: "blue"; }
    }
  }

  Text {
    id: myText
    text: qsTr("<html><b>Hello</b> <i><font color='green'>World</font></i></html>
                <br><font color='#C0C0C0'>This is a test code</font>
                <br><a href='http://www.google.com'</a>my link")
    anchors.centerIn: parent
    font.pointSize: 30
    // font.bold: true
    // font.italic: true
    color: "red"
    linkColor: "lightblue"

    onLinkHovered: {
      console.log("Hover: " + link)
      if( link )
      {
        myText.font.bold = true
      }
      else
      {
        myText.font.bold = false
      }
    }

    onLinkActivated: Qt.openUrlExternally(link)
  }

  MyButton
  {
    id: button1
    x: 50
    y: parent.height - 150
    color: "red"
    colorClicked: "orange"
    title: "Button-1"
  }

  MyButton
  {
    id: button2
    x: parent.width/2 - 50
    y: parent.height - 150
    color: "blue"
    colorClicked: "orange"
    title: "Button-2"
  }

  MyButton
  {
    id: button3
    x: parent.width - 150
    y: parent.height - 150
    color: "green"
    colorClicked: "yellow"
    title: "Button-3<br>Testing"
  }

  MyButton
  {
    id: button4
    x: parent.width/2 - 50
    y: parent.height - 80
    width: parent.width/2
    anchors.horizontalCenter: parent.horizontalCenter
    color: "lightblue"
    colorClicked: "pink"
    title: "<b>Super</b> <i>Long</i><br><u>Button</u>"
  }
}
