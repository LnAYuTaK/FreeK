import QtQuick          2.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import QtPositioning 5.4
import QtLocation 5.4

ApplicationWindow {
    id:mainWindow

    minimumWidth:   ScreenTool.isAndroid? Screen.width  : Math.min(ScreenTool.defaultFontPixelWidth * 100, Screen.width)
    minimumHeight:  ScreenTool.isAndroid? Screen.height : Math.min(ScreenTool.defaultFontPixelWidth * 50, Screen.height)
    visible: true
    background: Rectangle {
        color: "#F7F7F7"
    }
    //安卓全屏//
     Component.onCompleted: {
         if(ScreenTool.isAndroid){
            mainWindow.showFullScreen()
         }
         else{
             width   =  Math.min(250 * Screen.pixelDensity, Screen.width)
             height  =  Math.min(150 * Screen.pixelDensity, Screen.height)
         }
     }

    menuBar: HeaderBar{
        id:         headerBar
        height:     ScreenTool.defaultToolBarHeight*3
        visible:    true
     }


     footer: TabBar {
         // ...
     }

     StackView {
         anchors.fill: parent
     }

//     ComboBox {
//         id:             mapTypeCombo
//         model:          QGroundControl.mapEngineManager.mapTypeList(_mapProvider)
//         Layout.preferredWidth:  _comboFieldWidth
//         onActivated: {
//             _mapType = textAt(index)
//             QGroundControl.settingsManager.flightMapSettings.mapType.value=textAt(index)
//         }
//         Component.onCompleted: {
//             var index = mapTypeCombo.find(_mapType)
//             if(index < 0) index = 0
//             mapTypeCombo.currentIndex = index
//         }
//     }


     Map {
         id: testMap
         anchors.fill: parent
         center: QtPositioning.coordinate(37.52, 121.39)
         plugin: Plugin {
             name: "freekmap"
         }
     }
     Button{

         onClicked: console.log(MapEngineManager.mapProviderList)


     }

}
