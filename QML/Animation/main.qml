import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")
  id: root

  // Property Animation
  Rectangle
  {

    id: myShape
    color: "limegreen"
    width: 100
    height: 100
    x: 0
    y: (parent.height/2) - (height/2)

    PropertyAnimation
    {
      id: animationRight
      target: myShape
      properties: "x"
      to: root.width - myShape.width
      duration: 500
    }

    PropertyAnimation
    {
      id: animationLeft
      target: myShape
      properties: "x"
      to: 0
      duration: 500
    }

    MouseArea
    {
      anchors.fill: parent
      onClicked:
      {
        if( myShape.x === 0 )
        {
          animationRight.start();
        }
        else
        {
          animationLeft.start();
        }
      }
    }
  }

  // Rotation Animation
  Rectangle
  {
    id: myShape2
    color: "red"
    width: 100
    height: 100
    anchors.centerIn: parent

    Text
    {
      id: title
      text: Math.round(parent.rotation)
      anchors.centerIn: parent
      font.bold: true
      font.pointSize: 30
      color: "darkred"
    }

    RotationAnimation
    {
      id: animation
      target: myShape2
      loops: Animation.Infinite   // Animate Infinite
      from: myShape2.rotation
      to: 360
      // Don't use -360 for changing the direction, infact there is direction
      // property for the direction
      direction: RotationAnimation.Clockwise
      duration: 3000
      running: true   // Starts the animation
    }

    MouseArea
    {
      anchors.fill: parent
      onClicked:
      {
        // paused will return if the animation is paused or not
        // while pause will actually pause the animation
        if( animation.paused )
        {
          animation.resume();
        }
        else
        {
          animation.pause();
        }
      }
    }
  }

  // Scale Animation
  Rectangle
  {
    id: myShape3
    color: "lightsteelblue"
    width: 100
    height: 100
    x: parent.width - 200
    y: 100
    // the text used below, is big and will go out off the rectangle
    // using the property clip to clip the extra text which is out of rectangle
    clip: true

    Text
    {
      id: titleScale
      text: qsTr("SCALE")
      font.bold: true
      font.pointSize: 33
      // here I can use 45, as this is not an animation
      rotation: -45
      anchors.centerIn: parent
    }

    SequentialAnimation
    {
      id: animationScale
      running: true
      loops: Animation.Infinite
      ScaleAnimator
      {
        id: animationShrink
        target: myShape3
        from: 1     // 100%
        to: 0.5     // 50%
        duration: 2000
        running: true
      }
      ScaleAnimator
      {
        id: animationGrow
        target: myShape3
        from: 0.5
        to: 1
        duration: 2000
        running: true
      }
    }
  }

  // The Previously Made Rectangle will not be visible due to this image
  // Comment this out to see them properly
  Image
  {
    id: ghost
    source: "https://raw.githubusercontent.com/voidrealms/qmlb-6-4/master/ghost.jpg"
    anchors.fill: parent
    opacity: 0

    SequentialAnimation
    {
      loops: Animation.Infinite
      running: true
      OpacityAnimator
      {
        target: ghost
        from: 0
        to: 0.8     // Not Setting 1 because old rectangles will not be visible
        duration: 2000
      }
      OpacityAnimator
      {
        target: ghost
        from: 0.8
        to: 0
        duration: 2000
      }
    }
  }
}
