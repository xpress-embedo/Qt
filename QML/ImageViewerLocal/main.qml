import QtQuick
import QtQuick.Controls 6.2
import QtQuick.Window 6.2

import DirHelper 1.0

ApplicationWindow {
  width: 640
  height: 480
  visible: true
  title: qsTr("Image Viewer")

  DirHelper {
    id: dirHelper
    path: "/home/xpress_embedo/Pictures/Screenshots/"
  }

  SwipeView {
    id: swipeView
    anchors.fill: parent
    currentIndex: tabBar.currentIndex
    Component.onCompleted: {
      let files = dirHelper.files
      for( let idx=0; idx<files.length; idx++ )
      {
        console.log("Loading: ", files[idx] );
        let component = Qt.createComponent("ImagePage.qml");
        let page = component.createObject( swipeView, { "width": 640, "height" : 480 } );
        page.source = "file://" + files[idx];
      }
    }
  }
}
