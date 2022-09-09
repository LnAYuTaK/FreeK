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

   RowLayout{
       anchors.fill:parent
        spacing: 0
        FreeKLabelButton{
            id:homeBut
            Layout.alignment: Qt.AlignLeft
            iconsource:"qrc:/images/ToolBarImage/home_fill_light.svg"
            paletteColor:"black"
            onClicked: {

                    mainWindow.showHomeView()
            }
        }
       Rectangle{
           Layout.preferredWidth: _defaultSize*20
           id:toolBargroup
       }
       FreeKLabelButton{
           Layout.fillWidth:true
           id:staeBar
           paletteColor:"#16c09c"
       }
       FreeKLabelButton{
           id:settingsBut
           Layout.alignment: Qt.AlignRight
           iconsource:"qrc:/images/ToolBarImage/shezhi.svg"
           paletteColor:"black"
           onClicked: {

           }
       }

   }

}







