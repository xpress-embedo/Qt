import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Column {
    id: column
    y: 0
    width: 200
    height: 400
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: label
      height: 40
      text: qsTr("Selected Here")
      horizontalAlignment: Text.AlignHCenter
      verticalAlignment: Text.AlignTop
      font.bold: true
      font.pointSize: 22
      anchors.horizontalCenter: parent.horizontalCenter
    }

    ListView {
      width: 200
      height: 200
      model: ["Option A", "Option B", "Option C"];
      delegate: CheckDelegate {
        text: modelData
        onCheckStateChanged: {
          label.text = index + " - " + modelData + " = " + checked;
        }
      }
    }
  }
}
