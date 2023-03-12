import QtQuick
import QtQuick.Controls 6.2

import com.company.test 1.0

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("QML C++ Integration, Registering C++ Classes")

  Test {
      id: test
      // https://stackoverflow.com/questions/69273910/injection-of-parameters-into-signal-handlers-is-deprecated-use-javascript-funct
      // https://doc-snapshots.qt.io/qt6-dev/qtqml-syntax-signals.html#signal-parameters
      onStatus: function(data) {
        labelStatus.text = data;
      }

//      This is deprecated see above the Qt6 syntax
//      onStatus: {
//        labelStatus.text = data;
//      }
    }

    Column {
      id: column
      width: 200
      height: 200
      anchors.verticalCenter: parent.verticalCenter
      spacing: 15
      anchors.horizontalCenter: parent.horizontalCenter

      Label {
        id: label
        width: parent.width
        height: 40
        color: "#c64600"
        text: qsTr("Register a C++ Class")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 14
        font.bold: true
      }

      Label {
        id: labelStatus
        width: parent.width
        height: 40
        color: "#813d9c"
        text: qsTr("Status")
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
        font.pointSize: 12
      }

      Button {
        id: buttonClickMe
        width: parent.width
        text: qsTr("Click Me!!!")
        onClicked: {
          var num = Math.round( Math.random() * 100 );
          test.work( num );
        }
      }
    }
}
