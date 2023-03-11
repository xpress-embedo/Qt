import QtQuick
import QtQuick.Controls 6.2
import QtQuick.Layouts 1.0

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Row {
    id: row
    width: 450
    height: 300
    anchors.verticalCenter: parent.verticalCenter
    spacing: 25
    anchors.horizontalCenter: parent.horizontalCenter

    GroupBox {
      id: groupBox0
      width: 200
      height: 200
      title: qsTr("Food")

      Column {
        id: columnFood
        width: 200
        height: 160
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        anchors.horizontalCenter: parent.horizontalCenter

        RadioButton {
          id: rbFish
          text: qsTr("Fish")
        }

        RadioButton {
          id: rbSteak
          text: qsTr("Steak")
        }

        RadioButton {
          id: rbVegan
          text: qsTr("Vegan")
        }
      }
    }

    GroupBox {
      id: groupBox1
      width: 200
      height: 200
      title: qsTr("Drinks")
      Column {
        id: columnDrink
        width: 200
        height: 160
        anchors.verticalCenter: parent.verticalCenter
        spacing: 20
        RadioButton {
          id: rbWater
          text: qsTr("Water")
        }

        RadioButton {
          id: rbWine
          text: qsTr("Wine")
        }

        RadioButton {
          id: rbSoda
          text: qsTr("Soda")
        }
        anchors.horizontalCenter: parent.horizontalCenter
      }
    }
  }

  Button {
    id: button
    y: 340
    text: qsTr("Click Me")
    anchors.horizontalCenter: parent.horizontalCenter
    onClicked: {
      var idx = 0;
      var radioButton;
      for( idx=0; idx<columnFood.children.length; idx++ )
      {
        radioButton = columnFood.children[idx];
        if( radioButton.checked )
        {
          console.log( radioButton.text + " is checked");
        }
      }
      for( idx=0; idx<columnDrink.children.length; idx++ )
      {
        radioButton = columnDrink.children[idx];
        if( radioButton.checked )
        {
          console.log( radioButton.text + " is checked");
        }
      }
    }
  }
}
