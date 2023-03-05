import QtQuick 2.12

Rectangle
{
  color: "gray"
  width: 50
  height: 50

  // JavaScript Function
  function update()
  {
    // console.log(x + " X " + y );
    label.text = Math.round(x) + "," + Math.round(y);
  }

  onXChanged: update()
  onYChanged: update()
  Component.onCompleted: update()

  Text
  {
    id: label
    text: qsTr("text")
    anchors.centerIn: parent
  }

  MouseArea
  {
    anchors.fill: parent
    drag.target: parent
    onClicked: parent.z++
  }
}

