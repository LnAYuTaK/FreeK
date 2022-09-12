import QtQuick                  2.3
import QtQuick.Controls         2.12
import QtQuick.Controls.Styles  1.4
import FreeK.ViewSetup.ScreenTool 1.0
import QtQuick.Layouts 1.12
import "../BasicControl"
//Home界面
Drawer{
     id:root
     visible: false
     edge:Qt.LeftEdge
     opacity : 0.99
     property real  defaultSize  :ScreenTool.defaultFontPointSize
     TabBar {
         id: bar
         width: defaultSize*25
         TabButton {
             id: firstBtn
             text: qsTr("Home")
         }
         TabButton {
             id: secondBtn
             text: qsTr("Discover")
         }
         TabButton {
             id: thirdBtn
             text: qsTr("Activity")
         }
     }

}



