import QtQuick
import QtQuick.Controls 6.2

ApplicationWindow {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    Page1 {

    }

    Page2 {

    }
  }

  header: TabBar {
    id: tabBar
    currentIndex: swipeView.currentIndex
    TabButton {
      text: qsTr("Page-1");
    }
    TabButton {
      text: qsTr("Page-2");
    }
  }
}
