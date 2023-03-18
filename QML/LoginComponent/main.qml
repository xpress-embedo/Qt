import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Login Page Component")

  Popup {
    id: popup
    anchors.centerIn: parent
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

    Label {
      id: lblStatus
      anchors.centerIn: parent
      text: ""
    }
  }

  Login {
    id: login
    width: 250
    height: 200
    anchors.centerIn: parent
    /* now we can't use simply onLogin { ... }
    https://stackoverflow.com/questions/69273910/injection-of-parameters-into-signal-handlers-is-deprecated-use-javascript-funct
    */
    onLogin: function(username, password) {
      lblStatus.text = username
      console.log("Username: ", username, " Password: ", password );
      popup.open()
    }
  }
}
