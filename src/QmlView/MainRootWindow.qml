import QtQuick          2.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import QtPositioning 5.4
import QtLocation 5.4
import FreeK 1.0

ApplicationWindow {
    id:mainWindow

    property var _providerList  :FreeK.mapEngineManager.mapProviderList
    property var _mapList  : FreeK.mapEngineManager.mapList
    minimumWidth:   ScreenTool.isAndroid? Screen.width  : Math.min(ScreenTool.defaultFontPixelWidth * 100, Screen.width)
    minimumHeight:  ScreenTool.isAndroid? Screen.height : Math.min(ScreenTool.defaultFontPixelWidth * 50, Screen.height)
    visible: true
//    background: Rectangle {
//        color: "#F7F7F7"
//    }
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

     background: Item {
         id:             rootBackground
         anchors.fill:   parent
     }

    menuBar: HeaderBar{
        id:         headerBar
        height:     ScreenTool.defaultToolBarHeight*2
        visible:    true
//        Column{
//        spacing: 10
//        Label{
//             text: "地图提供商"
//        }
//        ComboBox {
//            id:             mapProviderCombox
//            visible: true

//            model:          FreeK.mapEngineManager.mapProviderList
//            onActivated: {
//                 flyView.map.updateMapType(displayText,mapTypeCombox.displayText)
//            }
//         }
//        Label{
//             text: "地图类型"
//        }
//        ComboBox {
//            id:             mapTypeCombox
//            visible: true

//            model:     FreeK.mapEngineManager.mapTypeList(mapProviderCombox.displayText)
//            onActivated: {
//                // var maps   = flyView.getMap()
//                 flyView.map.updateMapType(mapProviderCombox.displayText,displayText)
//            }
//         }
//        }
     }

     footer: TabBar {
         // ...
     }

     StackView {
         anchors.fill: parent
     }

     FlyView{
             id:             flyView
             anchors.fill:   parent
     }



  }

