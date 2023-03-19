import QtQuick
import QtQuick.Window 6.2
import QtQuick.Controls 6.2

Item {
  property alias source: image.source
  Page {
    Image {
      id: image
      anchors.fill: parent
      fillMode: Image.PreserveAspectFit
      // source: "file"
    }
  }
}
