import QtQuick
import QtQuick.Controls 6.2

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Hello World")

  Column {
    id: column
    anchors.fill: parent
    spacing: 5
    ScrollView {
      id: scrollView
      width: parent.width
      height: parent.height - (textfield.height+10)
      TextArea {
        id: textarea
        width: parent.width
        // height: parent.height
        text: ""
      }
    }

    TextField {
      id: textfield
      focus: true
      width: parent.width
      text: ""
      Keys.onReturnPressed: {
        textarea.append(textfield.text);
        textfield.clear();
        scrollView.contentItem.contentY = textarea.height -
                                          scrollView.contentItem.height;
      }
    }
  }
}
