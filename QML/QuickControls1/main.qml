import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  BusyIndicator {
    id: busyIndicator
    width: 124
    height: 132
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
  }

  CheckBox {
    id: checkBox
    y: 25
    text: qsTr("Check Box")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  Button {
    id: button
    y: 72
    text: qsTr("Button")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  DelayButton {
    id: delayButton
    y: 121
    text: qsTr("Delay Button")
    anchors.horizontalCenter: parent.horizontalCenter
  }

  Dial {
    id: dial
    x: 20
    y: 172
    width: 161
    height: 136

    Label {
      id: lblDial
      text: qsTr("0")
      anchors.verticalCenter: parent.verticalCenter
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      anchors.horizontalCenter: parent.horizontalCenter
    }
    onMoved: {
      lblDial.text = Math.round(dial.value*100);
    }
  }

  Label {
    id: label
    x: 34
    y: 37
    text: qsTr("This is a label")
  }

  Label {
    id: label1
    x: 34
    y: 60
    width: 189
    height: 37
    text: qsTr("This is a long label text, probably the longest ever.")
    wrapMode: Text.WordWrap
    color: "red"
  }

  Label {
    id: label2
    x: 34
    y: 103
    text: qsTr("This is <font color='blue'><b><i>HTML</i></h></font>")
    font.pointSize: 30
  }

  Label {
    id: label3
    y: 332
    text: qsTr("Progress = ") + busyIndicator.running
    horizontalAlignment: Text.AlignHCenter
    anchors.horizontalCenter: parent.horizontalCenter

    MouseArea {
      id: mouseArea
      width: 100
      height: 100
      anchors.verticalCenter: parent.verticalCenter
      anchors.horizontalCenter: parent.horizontalCenter
      anchors.fill: parent
      onClicked:
      {
        if( busyIndicator.running )
        {
          console.log("Turning Off");
          busyIndicator.running = false;
        }
        else
        {
          console.log("Turning On");
          busyIndicator.running = true;
        }
      }
    }
  }

  Row {
    id: row
    y: 395
    width: parent.width
    height: 85
    spacing: 25
    anchors.horizontalCenter: parent.horizontalCenter

    DelayButton {
      id: delayButtonDeleteEveryThing
      width: 130
      height: 40
      delay: 1000
      text: qsTr("Delay Everything");
      icon.color: "#ffffff"
      onActivated: {
        lblDelayButton.text = "Done";
        delayButtonDeleteEveryThing.text = "BOOOM";
        console.log("Delay Button Activated");
      }
      onProgressChanged: {
        lblDelayButton.text = Math.round(progress*100)
        console.log("Delay Button Progress Changed");
        if( progress === 0 ) {
          delayButtonDeleteEveryThing.text = "Delete Everything";
          lblDelayButton.text = "Status"
        }
      }
    }

    Label {
      id: lblDelayButton
      width: 130
      height: 40
      color: "black"
      text: qsTr("Status")
      horizontalAlignment: Text.AlignHCenter
      font.bold: true
      font.pointSize: 25
    }
  }
}
