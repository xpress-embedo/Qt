import QtQuick

/*
  QML Lives on Top of C++ Qt
  You Can Expose C++ Classes to QML
  C++ and QML Communicates via Signals and Slots
*/
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Column {
    id: column0
    x: 10
    width: 200
    height: 200
    anchors.verticalCenter: parent.verticalCenter
    spacing: 30

    Label {
      id: label0
      width: column0.width
      height: 40
      color: "#000000"
      text: qsTr("Call a C++ Slot")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      font.pointSize: 16
    }

    Button {
      id: button0
      width: column0.width
      height: 40
      text: qsTr("Button")
      onClicked: {
        // Call a slot, we can only call functions which are public slots
        // and it is not possible to call the normal functions
        testing.bark();
        // var num = testing.number(); --> this will not work as is a normal function
        // print (num)
      }
    }
  }

  Connections {
    target: testing   // this is our C++ object on the root context
    /* This is deprecated and should not be used
    onNotice: {
      console.log("Slot Called from C++");
      labelStatus.text = data   // get this data from the signal
    }*/

    // https://doc.qt.io/qt-6/qml-qtqml-connections.html
    function onNotice(data) {
      console.log("Slot Called from C++");
      labelStatus.text = data   // get this data from the signal
    }

  }

  Column {
    id: column1
    x: parent.width - column1.width - 10
    width: 200
    height: 200
    anchors.verticalCenter: parent.verticalCenter
    spacing: 20

    Label {
      id: label1
      color: "#26a269"
      text: qsTr("Connecting to Signals")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      anchors.horizontalCenter: parent.horizontalCenter
      font.pointSize: 14
    }

    Label {
      id: labelStatus
      color: "#c01c28"
      text: qsTr("Status")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      font.pointSize: 12
      anchors.horizontalCenter: parent.horizontalCenter
    }

    Button {
      id: button1
      width: column0.width
      height: 40
      text: qsTr("Start")
      onClicked: {
        // Callin a slot
        testing.start();
      }
    }

    Button {
      id: button2
      width: column0.width
      height: 40
      text: qsTr("Stop")
      onClicked: {
        // Callin a slot
        testing.stop();
      }
    }
  }
}
