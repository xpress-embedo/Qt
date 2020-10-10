import QtQuick 2.12
import QtQuick.Window 2.12

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")
  Text {
    id: name
    text: qsTr("Hello World from QML")
  }
}
