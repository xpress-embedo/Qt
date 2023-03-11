import QtQuick
import QtQuick.Controls 6.2

ApplicationWindow {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  property string name: ""

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex

    // This page is the editor page
    Page1 {
      id: page1
      Component.onCompleted: {
        name = root.name
      }
    }

    // This is the display page
    Page2 {
      id: page2
    }

    onCurrentIndexChanged: {
      console.log(currentIndex)
      // Page-2
      if( currentIndex === 1 )
      {
        root.name = page1.name
        page2.name = root.name
      }
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
