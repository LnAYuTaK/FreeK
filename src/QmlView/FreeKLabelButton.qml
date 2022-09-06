
import QtQuick          2.3
import QtQuick.Controls 2.4
import FreeK.ViewSetup.ScreenTool 1.0

//图片按钮
Button {
    id:                 button
    checkable:          false
    property bool logo: false
    property string paletteColor: "transparent"
    onCheckedChanged: checkable = false
    property string iconsource: ""
    FreeKImage {
            id:                     _icon
            anchors.fill :parent
            source:                 button.iconsource
            sourceSize.height:      parent.height
            anchors.verticalCenter: parent.verticalCenter
    }
    palette {
         button: paletteColor
    }

}

