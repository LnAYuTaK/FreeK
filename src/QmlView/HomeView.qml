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
         width: firstBtn.width
         TabButton {
             id: firstBtn
             text: qsTr("Home")
             width: root.width/8
             height: root.height/3
             anchors.horizontalCenter: parent.horizontalCenter
             anchors.top: parent.top
         }
         TabButton {
             id: secondBtn
             text: qsTr("Discover")
             width: root.width/8
             height: root.height/3
             anchors.horizontalCenter: parent.horizontalCenter
             anchors.top: firstBtn.bottom
         }
         TabButton {
             id: thirdBtn
             text: qsTr("Activity")
             width: root.width/8
             height: root.height/3
             anchors.horizontalCenter: parent.horizontalCenter
             anchors.top: secondBtn.bottom
         }
     }
}



