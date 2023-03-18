import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  ColorCombo {
    id: cmbColor
    anchors.centerIn: parent
    width: 100
    height: 40
  }
}
