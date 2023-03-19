import QtQuick
import QtQuick.Controls
import QtQuick.Window
import QtQuick.Dialogs
import Qt.labs.platform as Platform

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
      console.log("Path: ", path);
    }
  }

  FileDialog {
    id: openDialog
    title: "Please Choose a file!"
    fileMode: FileDialog.OpenFile

    onAccepted: {
      backend.path = openDialog.selectedFile;
      editor.text = backend.data;
    }
  }

  FileDialog {
    id: saveDialog
    title: "Please Choose a file!"
    fileMode: FileDialog.SaveFile

    onAccepted: {
      backend.path = openDialog.selectedFile;
      backend.data = editor.text;
    }
  }

  Action {
    id: actionNew
    text: qsTr("New")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oNew.png"

    onTriggered: {
      editor.clear();
    }
  }

  Action {
    id: actionOpen
    text: qsTr("Open")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oOpen.png"

    onTriggered: {
      openDialog.open();
    }
  }

  Action {
    id: actionSave
    text: qsTr("Save")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oSave.png"

    onTriggered: {
      saveDialog.open();
    }
  }

  Action {
    id: actionCopy
    text: qsTr("Copy")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oCopy.png"

    onTriggered: {
      editor.copy();
    }
  }

  Action {
    id: actionCut
    text: qsTr("Cut")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oCut.png"

    onTriggered: {
      editor.cut();
    }
  }

  Action {
    id: actionPaste
    text: qsTr("Paste")
    icon.color: "transparent"
    icon.source: "qrc:/images/images/oPaste.png"

    onTriggered: {
      editor.paste();
    }
  }



  menuBar: MenuBar {
    Menu {
      id: menuFile
      title: qsTr("&File")
      Action { text: qsTr("&New") }
      Action { text: qsTr("&Open") }
      Action { text: qsTr("&Save") }
      MenuSeparator {}
      Action { text: qsTr("&Quit") }
    }
    Menu {
      id: menuEdit
      title: qsTr("Edit")
      Action { text: qsTr("C&ut") }
      Action { text: qsTr("&Copy") }
      Action { text: qsTr("&Paste") }
    }
    Menu {
      title: qsTr("&Help")
      Action { text: qsTr("&About") }
    }
  }

  header: ToolBar {
    Row {
      ToolButton { display: AbstractButton.IconOnly; action: actionNew }
      ToolButton { display: AbstractButton.IconOnly; action: actionOpen }
      ToolButton { display: AbstractButton.IconOnly; action: actionSave }
      ToolButton { display: AbstractButton.IconOnly; action: actionCopy }
      ToolButton { display: AbstractButton.IconOnly; action: actionCut }
      ToolButton { display: AbstractButton.IconOnly; action: actionPaste }
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
