import QtQuick          2.11
import QtQuick.Controls 2.5
import QtQuick.Dialogs  1.3
import QtQuick.Layouts  1.11
import QtQuick.Window   2.11
import FreeK.ViewSetup.ScreenTool 1.0
import FreeK 1.0
import "../BasicControl"
Rectangle {


    Rectangle//底边框
    {
            anchors.left:   parent.left
            anchors.right:  parent.right
            anchors.bottom: parent.bottom
            height:         1
            color:          "black"
    }
    RowLayout{
        anchors.fill :parent
    //    anchors.top:            parent.top
    //    anchors.bottom:         parent.bottom
        //Home
        Button{
            Layout.alignment: Qt.AlignLeft

            onClicked: {

           }
        }
        //底边框

        //
        MainStatusIndicator{

        }
        MainStatusIndicator{
        }

        //Setup
//        Button{
//            height:parent.height
//            background: Rectangle {
//                anchors.fill:parent
//                color:"black"
//            }
//            Layout.alignment: Qt.AlignRight

//            onClicked: {
//                console.log("open")
//            }
//        }
        FreeKLabelButton{
            background: Rectangle{

                color:"white"
            }

            Layout.preferredWidth: ScreenTool.defaultFontPixelWidth*5
            Layout.alignment: Qt.AlignRight
            id:                     currentButton
            icon.source:            "qrc:/images/ToolBarImage/home_1.svg"

        }

 }

}







