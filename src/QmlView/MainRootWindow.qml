import QtQuick          2.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import QtPositioning 5.4
import QtLocation 5.4
import FreeK 1.0
import "../control"
ApplicationWindow {
    id:mainWindow

    property var _providerList  :FreeK.mapEngineManager.mapProviderList
    property var _mapList  : FreeK.mapEngineManager.mapList
    minimumWidth:   ScreenTool.isAndroid? Screen.width  : Math.min(ScreenTool.defaultFontPixelWidth * 100, Screen.width)
    minimumHeight:  ScreenTool.isAndroid? Screen.height : Math.min(ScreenTool.defaultFontPixelWidth * 50, Screen.height)
    visible: true

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
     HomeView{
         id:homeView
         height:parent.height
         width: parent.height
     }
     function showHomeView(){
      if(!homeView.visible){
        homeView.visible = true
      }
        //msgBoxAnyks.open(this);
     }




     function closeFreeKProcess(){
        //close Video
        //close Link
        mainWindow.close()
     }
     FreeKMessageBox {
             id:		msgBoxAnyks
             title:	"是否退出"
             text:	"是否要在为保存的情况下退出."
             onButtonClick: {
               (index == 0)? closeFreeKProcess():console.log("error")
             }
             Component.onCompleted:  msgBoxAnyks.addButtons([{ "text": "OK",},
                                                    {"text":"Cancel",}])
     }



}




