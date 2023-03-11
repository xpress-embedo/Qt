import QtQuick
import QtQuick.Controls 6.2

ApplicationWindow {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Stack View Application")

  header: ToolBar {
    contentHeight: toolButton.implicitHeight

    ToolButton {
      id: toolButton
      text: stackView.depth > 1 ? "\u25C0" : "\u2630"
      font.pixelSize: Qt.application.font.pixelSize * 1.6
      onClicked: {
        if( stackView.depth > 1 )
        {
          stackView.pop();
        }
        else
        {
          drawer.open()
        }
      }
    }
    Label {
      text: stackView.currentItem.title
      anchors.centerIn: parent
    }
  }

  Drawer {
    id: drawer
    width: window.width * 0.66
    height: window.height
    Column {
      anchors.fill: parent
      ItemDelegate {
        text: qsTr("Page 1")
        width: parent.width
        onClicked: {
          stackView.push("Page1.qml")
          drawer.close()
        }
      }

      ItemDelegate {
        text: qsTr("Page 2")
        width: parent.width
        onClicked: {
          stackView.push("Page2.qml")
          drawer.close()
        }
      }

      /*ItemDelegate {
        text: qsTr("Page 3")
        width: parent.width
        onClicked: {
          stackView.push("Page3.qml")
          drawer.close()
        }
      }*/
    }
  }

  StackView {
    id: stackView
    initialItem: "Home.qml"
    anchors.fill: parent
  }
}
