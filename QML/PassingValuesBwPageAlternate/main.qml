import QtQuick
import QtQuick.Controls 6.2

ApplicationWindow {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Passing Values Between Pages Alternate Method")

  property string name: "Embedded Lab."
  property var    page1: ({})   // Empty Object
  property var    page2: ({})   // Empty Object

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex
    // Here the Page formation process is commented out, refer the below link
    // https://doc.qt.io/qt-6.2/qml-var.html#property-value-initialization-semantics
//    // This page is the editor page
//    Page1 {
//      id: page1
//    }

//    // This is the display page
//    Page2 {
//      id: page2
//    }
    Component.onCompleted: {
      var component1 = Qt.createComponent("Page1.qml");
      page1 = component1.createObject( swipeView, {name: root.name});
      addItem(page1);

      var component2 = Qt.createComponent("Page2.qml");
      page1 = component2.createObject( swipeView, {name: root.name});
      addItem(page2);
    }

    onCurrentIndexChanged: {
      console.log(currentIndex);
      if( currentIndex === 0 )
      {
        root.name = page2.name;
        page1.name = root.name;
      }
      if( currentIndex === 1 )
      {
        root.name = page1.name;
        page2.name = root.name;
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
