import QtQuick
import QtQuick.Controls 6.2

Window {
  id: window
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Column {
    id: column
    width: 200
    height: 400
    anchors.verticalCenter: parent.verticalCenter
    spacing: 20
    anchors.horizontalCenter: parent.horizontalCenter

    Label {
      id: lblFood
      color: "red"
      font.pointSize: 12
      font.bold: true
      text: qsTr("Selected Item")
    }

    ComboBox {
      id: cmbFood
      model: ['Pizza', 'Steak', 'Pasta']
      onCurrentTextChanged: {
        lblFood.text = cmbFood.currentText
      }
    }

    Label {
      id: lblPeople
      color: "red"
      font.pointSize: 12
      font.bold: true
      text: qsTr("Selected Item")
    }

    ComboBox {
      id: cmbPeople
      editable: true
      textRole: "text"

      model: ListModel {
        id: listmodel
        ListElement { text: "Bryan"; age: "43" }
        ListElement { text: "Tammy"; age: "49" }
        ListElement { text: "Rango"; age: "15" }
      }

      onCurrentIndexChanged: {
        lblPeople.text = model.get(currentIndex).text + " = " +
                         model.get(currentIndex).age;
      }
      onAccepted: {
        if( find(editText) === -1 )
        {
          model.append( { "text": editText, "age": "0" } )
          currentIndex = find(editText)
        }
      }
    }

  }
}
