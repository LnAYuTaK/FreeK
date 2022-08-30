import QtQuick          2.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.14
import FreeK.ViewSetup.ScreenTool 1.0
//import FreeK.MapManager 1.0
ApplicationWindow {
    id:mainWindow

    minimumWidth:   ScreenTool.isAndroid? Screen.width  : Math.min(ScreenTool.defaultFontPixelWidth * 100, Screen.width)
    minimumHeight:  ScreenTool.isAndroid? Screen.height : Math.min(ScreenTool.defaultFontPixelWidth * 50, Screen.height)
    visible: true
    background: Rectangle {
        color: "#F7F7F7"
    }
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
         // ...
        id:         headerBar
        height:     ScreenTool.defaultToolBarHeight*2
        visible:    true
     }

     footer: TabBar {
         // ...
     }

     StackView {
         anchors.fill: parent
     }




}
