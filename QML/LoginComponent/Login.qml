import QtQuick
import QtQuick.Controls 6.2

Item {
  id: root
  signal login(string username,string password)
  width: 250
  height: 200

  Column {
    id: column
    anchors.fill: parent

    spacing: 10

    Label {
      id: lblUserName
      text: qsTr("Username")
    }

    TextField {
      id: textUserName
      width: parent.width
      height: 40
      placeholderText: qsTr("")
    }

    Label {
      id: lblPassword
      text: qsTr("Password")
    }

    TextField {
      id: textPassword
      width: parent.width
      height: 40
      placeholderText: qsTr("")
      echoMode: TextInput.Password
    }

    Button {
      id: button
      width: parent.width
      height: 40
      // anchors.horizontalCenter: parent
      text: qsTr("Submit")
      onClicked: {
        console.log("Button Clicked");
        root.login( textUserName.text, textPassword.text );
      }
    }
  }
}
