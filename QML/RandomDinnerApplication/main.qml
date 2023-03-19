import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Random Dinner Application")

  property variant places: ["Italian", "Mexican", "Asian", "American"];

  MouseArea {
    id: area
    anchors.fill: parent

    onClicked: {
      animation.stop();
      fadeoutanimation.stop();

      // Animate the Selection
      lblPlace.font.pixelSize = 45;
      lblPlace.opacity = 0;
      lblPlace.rotation = 0.0;
      // Animate the Fade Out
      fadeoutanimation.start();
    }

    Label {
      id: lblPlace
      anchors.centerIn: parent
      font.bold: true
      font.pixelSize: 30
      text: "Tap Me!"
    }
  }

  SequentialAnimation {
    id: animation
    running: true
    loops: Animation.Infinite
    NumberAnimation {
      target: lblPlace
      property: "font.pixelSize";
      to: 45;
      duration: 1000;
    }
    NumberAnimation {
      target: lblPlace
      property: "font.pixelSize";
      to: 30;
      duration: 1000;
    }
  }

  OpacityAnimator {
    id: fadeoutanimation
    running: false
    target: lblPlace
    from: 1
    to: 0
    duration: 1000
    onFinished: pick()
  }

  ParallelAnimation {
    id: selectionanimation
    running: false
    NumberAnimation {
      target: lblPlace
      property: "font.pixelSize";
      from: 0
      to: 45;
      duration: 2000;
    }
    OpacityAnimator {
      target: lblPlace
      from: 0
      to: 1
      duration: 2000
    }
    RotationAnimation {
      target: lblPlace
      from: 0
      to: 1
      duration: 2000
      direction: RotationAnimation.Counterclockwise
    }
  }

  function pick()
  {
    let i = Math.floor( Math.random() * places.length );
    lblPlace.text = places[i];
    selectionanimation.start();
  }

}
