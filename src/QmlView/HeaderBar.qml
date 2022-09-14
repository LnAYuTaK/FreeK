import QtQuick          2.3
import QtQuick.Controls 2.4
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import FreeK 1.0
import "../BasicControl"
Rectangle {
   property int _defaultSize  :ScreenTool.defaultFontPointSize
   color: Qt.rgba(0,0,0,0)
   RowLayout{
       anchors.fill:parent
        spacing: 0
        FreeKLabelButton{
            id:homeBut
            opacity : 0.8
            Layout.alignment: Qt.AlignLeft
            iconsource:"qrc:/images/ToolBarImage/home_fill_light.svg"
            paletteColor:"#0000000"
            onClicked: {
                    mainWindow.showHomeView()
            }
        }
        Rectangle{
             opacity : 0.8
             Layout.fillHeight: true
             Layout.preferredWidth: 1
             color:"white"
         }
       Rectangle{
            opacity : 0.8
            Layout.fillHeight: true
            Layout.preferredWidth: 260
            color :"black"
        }
       Rectangle{
           Layout.fillHeight: true
           Layout.fillWidth: true
           id:state
           color:"#16c09c"
       }
       FreeKLabelButton{
           id:settingsBut
           opacity : 0.8
           Layout.alignment: Qt.AlignRight
           iconsource:"qrc:/images/ToolBarImage/shezhi.svg"
           paletteColor:"#0000000"
           onClicked: {

           }
       }

   }

}







