import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Dice Converter")

  function calculate()
  {
    // go through each item
    let model = listView.model;
    let total = 0;

    // Check each dice
    for( let idx=0; idx<model.count; idx++ )
    {
      let item = model.get(idx);
      if( item.value > 0 )
      {
        console.log("Name: ", item.name );    // the model
        console.log("Number: ", item.number );
        console.log("Value: ", item.value );

        // roll each dice
        for( let roll=0; roll<item.value; roll++ )
        {
          let min = 1;
          let max = item.number;
          let subtotal = Math.floor( Math.random() * (max-min+1) + min);
          console.log("Roll: ", subtotal);
          total = total + subtotal;
        }
        console.log("Total: ", total);
      }
      lblTotal.text = "Total: " + total;
    }
  }

  Column {
    id: column
    anchors.fill: parent
    spacing: 10

    ListView {
      id: listView
      width: parent.width
      anchors.left: parent.left
      anchors.top: parent.top
      anchors.bottom: parent.bottom
      anchors.bottomMargin: 100
      anchors.leftMargin: 10
      anchors.topMargin: 10
      focus: true
      model: DiceModel {}
      delegate: DiceDelegate {}
    }

    Row {
      id: row
      width: parent.width
      height: 50
      anchors.bottom: parent.bottom
      anchors.bottomMargin: 0

      Rectangle {
        anchors.fill: parent
        color: "gray"

        Label {
          id: lblTotal
          color: "white"
          text: "Total: 0"
          font.pointSize: 25
          font.bold: true
          anchors.verticalCenter: parent.verticalCenter
          anchors.left: parent.left
          anchors.leftMargin: 10
        }

        Button {
          id: button
          width: 100
          height: 40
          text: "Calculate"
          anchors.verticalCenter: parent.verticalCenter
          anchors.right: parent.right
          anchors.rightMargin: 10
          onClicked: calculate()
        }
      }
    }
  }
}
