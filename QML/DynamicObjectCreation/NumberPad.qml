import QtQuick
import QtQuick.Controls 6.2

Item {
  id: root

  signal clicked(int value)

  Column {
    id: col
    Grid {
      id: grid
      spacing: 5
      rows: 4
      columns: 3
    }
  }

  function doClicked( value ) {
    console.log( value )
    // emit the signal
    clicked(value)
  }

  Component.onCompleted: {
    console.log("Creating Buttons");
    var num = 0;
    for( var i=0; i<10; i++ )
    {
      // let's translate as per the keyboard layout
      /*
        7 8 9 --> First Row
        4 5 6 --> Second Row
        1 2 3 --> Third Row
        0 0 0 --> Bottom Row
      */
      if( i===0 ) num = 7;    // First Row
      if( i===3 ) num = 4;    // Second Row
      if( i===6 ) num = 1;    // Third Row
      if( i===9 ) num = 0;    // Bottom Row

      var btn = Qt.createQmlObject('import QtQuick;import QtQuick.Controls 6.2; Button{id: btn' + i+ '; onClicked:doClicked('+num+')}',
                                   grid, "DynamicallyLoaded");
      btn.text = num;
      btn.width = 40;
      btn.height = 40;
      num++;
    }

    // Set the last button on the bottom
    // pull the last element from the grid i.e. the 0 and add it to the column
    var obj = grid.children[grid.children.length-1];
    obj.parent = col
    obj.width = (40*grid.columns) + 10

  }
}
