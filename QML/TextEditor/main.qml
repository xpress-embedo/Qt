import QtQuick
import QtQuick.Controls 6.2
import QtQuick.Window 6.2
import QtQuick.Dialogs 6.2

import BackEnd 1.0

ApplicationWindow {
  width: 640
  height: 480
  visible: true
  title: qsTr("Text Editor")

  Backend {
    id: backend
    onPathChanged: {
      console.log("Path: ", path);
    }
    onDataChanged: {
      console.log("Data: ", data);
    }
  }

  FileDialog {
    id: openDialog
    title: "Please Choose a file!"
    // folder: shortcuts.home
    // selectMultiple: false
    // selectExisting: true

    onAccepted: {
      backend.path = openDialog.fileUrl;
      // update the editor todo
    }
  }

  FileDialog {
    id: saveDialog
    title: "Please Choose a file!"
    // folder: shortcuts.home
    // selectMultiple: false
    // selectExisting: false

    onAccepted: {
      backend.path = openDialog.fileUrl;
      // update the backend todo
    }
  }

  Action {
    id: actionNew
    text: qsTr("New")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oNew.png"

    onTriggered: {

    }
  }

  ScrollView {
    anchors.fill: parent
    TextArea {
      id: editor
      focus: true
      text: "Hello World"
      selectByMouse: true
      persistentSelection: true   // Copt and Paste need this
    }
  }
}
