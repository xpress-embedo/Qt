import QtQuick
import QtQuick.Window
import QtQuick.Controls 6.2
import QtCharts 6.2

import com.company.serialmanager 1.0

ApplicationWindow {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("Temperature and Humidity Plot")

  property bool connectStatus: false

  SerialManager {
    id: serialManager
    onConnectStatusChanged: function(status) {
      // Here I used root because if root not use then this class also has a
      // method connectStatus, and hence to differentiate between the two
      root.connectStatus = status;
      console.log("QML Message Status Changed", root.connectStatus);
      if( root.connectStatus == false )
      {
        // Set the text of button as "Connect" and enable ComboBox
        btn_connect_disconnect.text = "Connect";
        cb_com_port.enabled = true;
      }
      else
      {
        // Set the text of button as "Connect" and enable ComboBox
        btn_connect_disconnect.text = "Disconnect";
        cb_com_port.enabled = false;
      }
    }

    onTemperatureChanged: {
      lbl_temperature.text = serialManager.temperature.y + qsTr("\xB0 C")
      /* This this is a real-time plot and for each session we display around
      SECONDS_SHOW_ON_GRAPH seconds on graph, => serialmanager.cpp file
      so it is difficult to predict how many counts we have received and
      how to reset them.
      TODO: this I will try to handle in future, although it's not a problem
      but as we keep of appending this list keeps on growing, which is a kind
      of not a good thing
      if( lineSeriesTemperature.count > 10 )
      {
        lineSeriesTemperature.remove(0);
      }*/

      lineSeriesTemperature.append( serialManager.temperature.x, serialManager.temperature.y );

      /* I am not setting the minimum and maximum range here, because the value
      of time received is in milliseconds, and I don't know hown to convert it
      to datetime, so I used another approach, of adjusting the ranges from
      C++ code, using onMinRangeChanged and onMaxRangeChanged */
      // axisxTemp.min = lineSeriesTemperature.at(0).x
      // axisxTemp.max = lineSeriesTemperature.at( lineSeriesTemperature.count-1).x
    }

    onHumidityChanged: {
      lbl_humidity.text = serialManager.humidity.y + " %";
    }

    onMinRangeChanged: {
      axisxTemp.min = serialManager.minRange;
    }
    onMaxRangeChanged: {
      axisxTemp.max = serialManager.maxRange;
    }
  }

  Button {
    id: btn_connect_disconnect
    x: 20
    y: 20
    width: 100
    height: 30
    text: qsTr("Connect")
    onClicked: {
      console.log("connectStatus = ", connectStatus );
      if( root.connectStatus == false ) {
        console.log("Clicked: true")
        // connectStatus = true;
        // I am not changing the status here, as it miight be possible that port
        // didn't opened, so it will be updated in the emitted signal
        serialManager.setConnectStatus(true);
      }
      else {
        console.log("Clicked: false")
        // connectStatus = false;
        // I am not changing the status here, as it miight be possible that port
        // didn't opened, so it will be updated in the emitted signal
        serialManager.setConnectStatus(false);
      }
    }
  }

  ComboBox {
    id: cb_com_port
    x: 160
    y: 20
    width: 80
    height: 30
    displayText: qsTr("COM1")
    model: ListModel {
      ListElement { text: "COM1" }
      ListElement { text: "COM2" }
      ListElement { text: "COM3" }
      ListElement { text: "COM4" }
      ListElement { text: "COM5" }
      ListElement { text: "COM6" }
      ListElement { text: "COM7" }
      ListElement { text: "COM8" }
    }
  }

  Label {
    id: lbl_temp
    x: 260
    y: 20
    width: 110
    height: 30
    color: "indianred"
    text: qsTr("Temperature:")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }


  Label {
    id: lbl_temperature
    x: 380
    y: 20
    width: 60
    height: 30
    color: "indianred"
    // Both are ways to print degree symbol
    // text: qsTr("0.0") + qsTr("\u2103")
    text: qsTr("0.0") + qsTr("\xB0 C")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }


  Label {
    id: lbl_humid
    x: 450
    y: 20
    width: 80
    height: 30
    color: "indianred"
    text: qsTr("Humidity:")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }

  Label {
    id: lbl_humidity
    x: 530
    y: 20
    width: 60
    height: 30
    color: "indianred"
    text: qsTr("0 %")
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    font.pointSize: 14
  }

  ChartView {
    id: chartViewTemperature
    width: 600
    height: 400
    x: 20
    y: 60
    title: "Temperature Values"
    antialiasing: true
    legend.enabled: false

    ValueAxis {
      id: axisyTemp
      min: 0
      max: 100
      gridVisible: true
      color: "#ffffff"
      labelsColor: "#ffffff"
      labelFormat: "%.0f"
    }

    DateTimeAxis {
      id: axisxTemp
      gridVisible: true
      format: "hh:mm:ss"
      tickCount: 10
      titleText: "Time"
    }

    LineSeries {
      id: lineSeriesTemperature
      name: "Temperature Values"
      axisX: axisxTemp
      axisY: axisyTemp
    }
  }

//  ChartView {
//    id: chartViewHumidity
//    width: chartViewTemperature.width
//    height: chartViewTemperature.height
//    x: chartViewTemperature.x
//    y: chartViewTemperature.y + chartViewTemperature.height
//    title: "Humidity Values"
//    antialiasing: true
//  }
}
