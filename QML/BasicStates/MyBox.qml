import QtQuick

Item {
  id: item1
  Rectangle {
    id: element
    color: "transparent"
    anchors.fill: parent
    property color defaultColor: "#808080"
    property color onColor: "#008000"
    property color offColor: "#ff0000"

    Rectangle {
      id: rectangle
      color: element.defaultColor
      anchors.fill: parent
      radius: width
    }
  }
  states: [
    State {
      name: "on"

      PropertyChanges {
        target: rectangle
        color: element.onColor
        state: ""
      }
    },
    State {
      name: "off"

        PropertyChanges {
          target: rectangle
          color: element.offColor
        }
      }
  ]

}
