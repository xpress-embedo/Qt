import QtQuick
import QtQuick.Controls 6.2

Item {
  ComboBox {
    id: root
    model: ["red", "green", "blue", "yellow", "orange"]

    delegate: ItemDelegate {
      width: root.width
      highlighted: (root.highlightedIndex === root.index)
      contentItem: Row {
        spacing: 5
        width: root.width
        // Draw the color rectangle
        Rectangle {
          anchors.verticalCenter: parent.verticalCenter
          width: 10
          height: 10
          border.width: 1
          border.color: "black"
          color: modelData
        }
        // Add the text
        Text {
          id: name
          text: modelData
          color: "black"
          elide: Text.ElideRight
          verticalAlignment: Text.AlignVCenter
        }
      }
    }
    background: Rectangle {
      width: root.width
      implicitHeight: 40
      implicitWidth: 100
      border.color: (root.currentIndex === root.index) ? "green" : "white"
      color: (root.currentIndex === root.index) ? "lightgreen" : "white"
    }
  }
}
