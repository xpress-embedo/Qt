import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  property string lockCode: "777"
  property string status: "Locked"

  Popup {
    id: statusPopup
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    width: 200
    height: 300
    modal: true
    focus: true
    anchors.centerIn: parent
    Label {
      id: lblPopup
      anchors.centerIn: parent
      text: status
      font.bold: true
    }
  }

  Column {
    id: column
    width: 200
    height: 400
    anchors.verticalCenter: parent.verticalCenter
    spacing: 30
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      height: 40
      color: "#000000"
      text: qsTr("000")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignVCenter
      anchors.horizontalCenter: parent.horizontalCenter
      font.bold: true
      font.pointSize: 25
    }

    Row {
      id: row
      width: 200
      height: 200
      spacing: 10

      Tumbler {
        id: tumbler0
        model: 10
        onCurrentIndexChanged: {
          label.text = tumbler0.currentIndex + " " +
                       tumbler1.currentIndex + " " +
                       tumbler2.currentIndex;
        }
      }

      Tumbler {
        id: tumbler1
        model: 10
        onCurrentIndexChanged: {
          label.text = tumbler0.currentIndex + " " +
                       tumbler1.currentIndex + " " +
                       tumbler2.currentIndex;
        }
      }

      Tumbler {
        id: tumbler2
        model: 10
        onCurrentIndexChanged: {
          label.text = tumbler0.currentIndex + " " +
                       tumbler1.currentIndex + " " +
                       tumbler2.currentIndex;
        }
      }
    }

    Button {
      id: button
      text: qsTr("Check")
      highlighted: false
      flat: false
      anchors.horizontalCenter: parent.horizontalCenter
      onClicked: {
        var temp;
        temp = tumbler0.currentIndex + "" + tumbler1.currentIndex + "" +
               tumbler2.currentIndex;
        console.log( temp );
        console.log( typeof(temp) );
        if( temp === lockCode )
        {
          status = "Unlocked"
          console.log( "Unlocked" );
        }
        statusPopup.open();
      }
    }
  }
}
