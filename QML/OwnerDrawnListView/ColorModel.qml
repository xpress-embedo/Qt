import QtQuick

// Model Determine what data is in the list

ListModel {
  id: colorModel

  ListElement {
    name: "Black"
    code: "#000000"
  }
  ListElement {
    name: "White"
    code: "#FFFFFF"
  }
  ListElement {
    name: "Red"
    code: "red"
  }
  ListElement {
    name: "Blue"
    code: "blue"
  }
  ListElement {
    name: "Green"
    code: "green"
  }
  ListElement {
    name: "Yellow"
    code: "yellow"
  }
}
