import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Number Converter Application")

  function convert() {
    let value = txtFrom.text;
    let ret = 0;
    switch (cmbType.currentIndex )
    {
    case 0: // inches to feet
      ret = inchesToFeet( value );
      break;
    case 1: // feet to inches
      ret = feetToInches( value );
      break;
    }

    lblResultStatus.text = ret
  }

  function inchesToFeet( value )
  {
    return value/12;
  }

  function feetToInches( value )
  {
    return value*12;
  }

  Column {
    id: column
    width: 250
    height: 150
    anchors.verticalCenter: parent.verticalCenter
    anchors.horizontalCenter: parent.horizontalCenter
    spacing: 10

    Grid {
      id: grid
      width: 250
      height: 100
      anchors.horizontalCenter: parent.horizontalCenter
      spacing: 10
      columns: 2

      Label {
        id: lblType
        height: 25
        text: qsTr("Type:")
      }

      ComboBox {
        id: cmbType
        width: 150
        model: ListModel {
          id: cbItems
          ListElement { text: "Inches to Feet" }
          ListElement { text: "Feet to Inches" }
        }
      }

      Label {
        id: lblFrom
        height: 25
        text: qsTr("From:")
      }

      TextField {
        id: txtFrom
        width: 150
        placeholderText: qsTr("")
      }

      Label {
        id: lblResult
        height: 25
        text: qsTr("Results:")
      }

      Label {
        id: lblResultStatus
        width: 150
        height: 25
        text: qsTr("Nothing")
      }
    }

    Button {
      id: button
      height: 40
      text: qsTr("Convert")
      anchors.horizontalCenter: parent.horizontalCenter
      onClicked: {
        convert()
      }
    }
  }
}
