import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Window {
  width: 900
  height: 560
  visible: true
  title: qsTr("SampleData Tree View")
  color: "#eef2f8"

  Rectangle {
    anchors.fill: parent
    gradient: Gradient {
      GradientStop { position: 0.0; color: "#f6f9ff" }
      GradientStop { position: 1.0; color: "#edf2fb" }
    }

    ColumnLayout {
      anchors.fill: parent
      anchors.margins: 20
      spacing: 14

      Rectangle {
        Layout.fillWidth: true
        color: "#ffffff"
        radius: 12
        border.color: "#d6deeb"
        border.width: 1
        implicitHeight: 92

        Column {
          anchors.fill: parent
          anchors.margins: 14
          spacing: 6

          Label {
            text: "SampleData"
            font.pixelSize: 34
            font.bold: true
            color: "#16243a"
          }

          Label {
            text: "Folders and files are read in C++, rendered in QML TreeView"
            color: "#42536d"
            font.pixelSize: 14
          }
        }
      }

      Rectangle {
        Layout.fillWidth: true
        Layout.fillHeight: true
        color: "#ffffff"
        radius: 12
        border.color: "#d6deeb"
        border.width: 1

        TreeView {
          id: treeView
          anchors.fill: parent
          anchors.margins: 10
          clip: true
          model: fileTreeModel
          rowSpacing: 4

          delegate: TreeViewDelegate {
            implicitWidth: treeView.width
            implicitHeight: 30

            background: Rectangle {
              radius: 6
              color: row % 2 === 0 ? "#f8fbff" : "#f1f6fd"
              border.color: "#e2e9f5"
            }

            indicator: Label {
              x: leftMargin + (depth * indentation)
              anchors.verticalCenter: parent.verticalCenter
              text: model.isDirectory ? (expanded ? "-" : "+") : ""
              color: "#3b506e"
              font.bold: true
            }

            contentItem: Row {
              spacing: 8
              anchors.verticalCenter: parent.verticalCenter

              Label {
                text: model.isDirectory ? "[DIR]" : "[FILE]"
                color: model.isDirectory ? "#1f5db5" : "#607086"
                font.pixelSize: 11
                font.bold: true
              }

              Label {
                text: model.display
                color: "#1d2b3e"
                elide: Text.ElideRight
                width: treeView.width - 170
                font.pixelSize: 14
              }
            }
          }
        }
      }
    }
  }
}
