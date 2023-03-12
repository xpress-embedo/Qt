import QtQuick
import QtQuick.Controls 6.2

import com.company.machine 1.0

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("QML and Cpp Integration Example")

  Component.onCompleted: {
    progressBar.value = machine.workLoad;
    buttonStart.enabled = true;
    buttonStop.enabled = false;
    buttonPause.enabled = false;
    buttonResume.enabled = false;
  }

  Machine {
    id: machine
    onStarted: function() {
      buttonStart.enabled = false;
      buttonStop.enabled = true;
      buttonPause.enabled = true;
      buttonResume.enabled = false;
      label.text = "Started";
    }

    onStoped: function() {
      buttonStart.enabled = true;
      buttonStop.enabled = false;
      buttonPause.enabled = false;
      buttonResume.enabled = false;
      label.text = "Stopped";
      progressBar.value = 0.0;
    }

    onResumed: function() {
      buttonStart.enabled = false;
      buttonStop.enabled = true;
      buttonPause.enabled = true;
      buttonResume.enabled = false;
      label.text = "Resumed";
    }

    onPaused: function() {
      buttonStart.enabled = false;
      buttonStop.enabled = false;
      buttonPause.enabled = false;
      buttonResume.enabled = true;
      label.text = "Paused";
    }

    onProgress: function() {
      label.text = "Progress: " + machine.workLoad + "%";
      progressBar.value = (machine.workLoad * 0.01)
    }
  }

  Column {
    id: column
    width: 400
    height: 200
    anchors.verticalCenter: parent.verticalCenter
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      width: parent.width
      height: 40
      text: qsTr("Label")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      font.bold: true
      font.pointSize: 20
      anchors.horizontalCenter: parent.horizontalCenter
    }

    ProgressBar {
      id: progressBar
      width: parent.width
      height: 20
      anchors.horizontalCenter: parent.horizontalCenter
      value: 0.5
    }
  }

  Row {
    id: row
    y: 220
    width: 400
    height: 43
    topPadding: 0
    layoutDirection: Qt.LeftToRight
    leftPadding: 0
    padding: 0
    spacing: 10
    anchors.horizontalCenter: parent.horizontalCenter

    Button {
      id: buttonStart
      width: 90
      height: 30
      text: qsTr("Start")
      onClicked: machine.start()
    }

    Button {
      id: buttonPause
      x: 100
      width: 90
      height: 30
      text: qsTr("Pause")
      onClicked: machine.pause()
    }

    Button {
      id: buttonResume
      x: 200
      width: 90
      height: 30
      text: qsTr("Resume")
      onClicked: machine.resume()
    }

    Button {
      id: buttonStop
      x: 300
      width: 90
      height: 30
      text: qsTr("Stop")
      onClicked: machine.stop()
    }
  }
}
