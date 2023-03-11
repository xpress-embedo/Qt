import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Popup {
    id: popup
    anchors.centerIn: parent
    width: 200
    height: 280
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    Column {
      anchors.fill: parent
      spacing: 25
      Label {
        id: lbl0
        width: 120
        height: 40
        text: "Butter = " + checkBox0.checked
      }
      Label {
        id: lbl1
        width: 120
        height: 40
        text: "Syrup = " + checkBox1.checked
      }
      Label {
        id: lbl2
        width: 120
        height: 40
        text: "Fruit = " + checkBox2.checked
      }
      Button {
        id: closeButton
        width: 120
        height: 40
        text: "Close"
        // onClicked: popup.visible = false
        onClicked: popup.close()
      }
    }
  }

  Frame {
    id: frame
    width: 200
    height: 280
    anchors.verticalCenter: parent.verticalCenter
    spacing: 25
    anchors.horizontalCenter: parent.horizontalCenter

    Column {
      id: column
      anchors.fill: parent
      spacing: 25

      CheckBox {
        id: checkBox0
        width: 120
        height: 40
        text: qsTr("Butter")
      }

      CheckBox {
        id: checkBox1
        width: 120
        height: 40
        text: qsTr("Syrup")
      }

      CheckBox {
        id: checkBox2
        width: 120
        height: 40
        text: qsTr("Fruit")
      }

      Button {
        id: button
        width: 120
        height: 40
        text: qsTr("Save")
        icon.color: "#00000000"
        // onClicked: popup.visible = true
        onClicked: popup.open()
      }
    }
  }
}
