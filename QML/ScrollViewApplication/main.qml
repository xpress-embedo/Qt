import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Component {
    id: delegate
    Item {
      id: item
      width: 200
      height: 50
      Column {
        anchors.fill: parent
        spacing: 5
        Label {
          text: name
          font.bold: true
        }
        Label {
          text: number
        }
      }
    }
  }

  ListModel {
    id: model
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
    ListElement {
      name: "Embedded Laboratory"
      number: "555 5431"
    }
  }

  ScrollView {
    anchors.fill: parent
    ListView {
      width: parent.width
      model: model
      delegate: delegate
    }
  }
}
