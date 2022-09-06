import QtQuick          2.3
import QtQuick.Controls 2.4
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import FreeK 1.0
import "../BasicControl"
Rectangle {
    color:"#000000"
    Rectangle//底边框
    {
            anchors.left:   parent.left
            anchors.right:  parent.right
            anchors.bottom: parent.bottom
            height:         1
            color:          "#2f271d"
    }
    RowLayout{
        anchors.fill :parent
        FreeKLabelButton{
            id:homeButton
            Layout.alignment: Qt.AlignLeft
            iconsource: "qrc:/images/ToolBarImage/home_fill_light.svg"
            paletteColor:"black"
            onClicked: {
                //mainWindow
            }
        }

        Rectangle
        {
             width:20
             palette{
                 color: "green"
             }

        }
        MainStatusIndicator{


        }
        FreeKLabelButton{
            id:settingsButton
            Layout.alignment: Qt.AlignRight
            iconsource:"qrc:/images/ToolBarImage/shezhi.svg"
            paletteColor:"black"
            onClicked: {
                //mainWindow
            }
        }
 }

}







