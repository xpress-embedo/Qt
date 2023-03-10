import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Row {
    id: row
    anchors.fill: parent

    Column {
      id: column0
      width: 200
      height: parent.height
      spacing: 10

      CheckBox {
        id: checkBox1
        width: 200
        height: 40
        text: qsTr("Normal")
        onClicked:
        {
          labelCheckboxStatus.text = "CheckBox = " + checkBox1.checkState;
        }
      }


      CheckBox {
        id: checkBox2
        width: 200
        height: 40
        text: qsTr("Not Checkable")
        checkable: false
        onClicked: {
          labelCheckboxStatus.text = "CheckBox = " + checkBox2.checkState;
        }
      }

      CheckBox {
        id: checkBox3
        width: 200
        height: 40
        text: qsTr("Tristate")
        tristate: true
        onClicked: {
          labelCheckboxStatus.text = "CheckBox = " + checkBox3.checkState;
        }
      }

      CheckBox {
        id: checkBox4
        width: 200
        height: 40
        text: qsTr("Exclusive")
        autoExclusive: true
        onClicked: {
          labelCheckboxStatus.text = "CheckBox = " + checkBox4.checkState;
        }
      }

      CheckBox {
        id: checkBox0
        width: 200
        height: 40
        text: qsTr("Repeat")
        autoRepeat: true
        onClicked: {
          labelCheckboxStatus.text = "CheckBox = " + checkBox0.checkState;
        }
      }

      Button {
        id: buttonReset
        width: 200
        height: 40
        text: qsTr("Reset")

        Connections {
          target: buttonReset
          onClicked: {
            checkBox0.checkState = Qt.Unchecked;
            checkBox1.checkState = Qt.Unchecked;
            checkBox2.checkState = Qt.Unchecked;
            checkBox3.checkState = Qt.Unchecked;
            checkBox4.checkState = Qt.Unchecked;
            console.log("Reset Button Clicked");
          }
        }
      }
    }

    Column {
      id: column1
      width: parent.width - x
      height: parent.height

      Label {
        id: labelCheckboxStatus
        text: qsTr("Status Here")
        anchors.verticalCenter: parent.verticalCenter
        horizontalAlignment: Text.AlignHCenter
        font.pointSize: 26
        font.bold: true
        anchors.horizontalCenter: parent.horizontalCenter
      }
    }
  }
}
