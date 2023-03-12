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
    id: column
    width: 200
    height: 200
    anchors.verticalCenter: parent.verticalCenter
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      width: column.width
      height: 40
      text: qsTr("Call a C++ Slot")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      font.pointSize: 16
    }

    Button {
      id: button
      width: column.width
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
}
