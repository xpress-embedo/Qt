import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")
  property string username: "Embedded"
  property string password: "Laboratory"
  property string status: "Failed"

  Popup {
    id: statusPopup
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    anchors.centerIn: parent
    width: 300
    height: 200
    modal: true
    focus: true

    Label {
      id: statusLabel
      anchors.centerIn: parent
      text: status
      font.bold: true
    }
  }

  Column {
    id: column
    width: 450
    height: 150
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter

    Grid {
      id: grid
      width: 520
      height: 100
      anchors.verticalCenter: parent.verticalCenter
      anchors.horizontalCenter: parent.horizontalCenter
      transformOrigin: Item.Center
      spacing: 10
      rows: 2
      columns: 2

      Label {
        id: labelUserName
        x: 0
        y: 0
        width: 200
        height: 40
        text: qsTr("User Name")
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 25
        font.bold: true
      }

      TextField {
        id: textFieldUserName
        width: 300
        height: 40
        font.pointSize: 25
        font.bold: true
        placeholderText: qsTr("Enter User Name")
      }

      Label {
        id: labelPassword
        width: 150
        height: 40
        text: qsTr("Password")
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 25
        font.bold: true
      }

      TextField {
        id: textFieldPassword
        width: 300
        height: 40
        font.pointSize: 25
        font.bold: true
        placeholderText: qsTr("Enter Password")
        echoMode: TextInput.Password
      }
    }
  }

  Button {
    id: buttonLogin
    x: 280
    y: 321
    text: qsTr("Login")
    anchors.horizontalCenterOffset: 0
    anchors.horizontalCenter: parent.horizontalCenter
    onClicked: {
      if( (username === textFieldUserName.text) &&
          (password === textFieldPassword.text) )
      {
        status = "Hello";
      }
      statusPopup.open();
    }
  }
}
