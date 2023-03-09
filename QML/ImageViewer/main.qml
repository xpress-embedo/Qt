import QtQuick

Window {
  width: 640
  height: 480
  visible: true
  title: qsTr("Image Viewer")

  id: root

  property color backgroundColor: "#5A6263"
  property color buttonColor: "green"
  property color hoverColor: "limegreen"
  property color clickColor: "yellow"
  property int size: 100

  Rectangle
  {
    id: background
    // color: root.backgroundColor
    color: root.buttonColor
    width: 100
    height: parent.height

    Column
    {
      id: column
      anchors.fill: parent
      HoverButton
      {
        width: 100
        height: 50
        title.text: "CAT"
        color: root.buttonColor
        hoverColor: root.hoverColor
        clickColor: root.clickColor
        area.onPressed:
        {
          image.source = "qrc:/Image/Cat.png"
        }
      }

      HoverButton
      {
        width: 100
        height: 50
        title.text: "DOG"
        color: root.buttonColor
        hoverColor: root.hoverColor
        clickColor: root.clickColor
        area.onPressed:
        {
          image.source = "qrc:/Image/Dog.png"
        }
      }

      HoverButton
      {
        width: 100
        height: 50
        title.text: "FISH"
        color: root.buttonColor
        hoverColor: root.hoverColor
        clickColor: root.clickColor
        area.onPressed:
        {
          image.source = "qrc:/Image/Fish.png"
        }
      }
    }
  }

  // Image Box
  Rectangle
  {
    id: rectangle
    // color: root.backgroundColor
    x: 100
    y: 0
    width: parent.width-x
    height: parent.height

    Image
    {
      id: image
      anchors.margins: 25
      anchors.fill: parent
      fillMode: Image.PreserveAspectFit
      source: "qrc:/Image/Cat.png"
    }
  }
}
