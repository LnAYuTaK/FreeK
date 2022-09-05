import QtQuick                  2.3
import QtQuick.Controls         2.12
import QtQuick.Controls.Styles  1.4
import FreeK.ViewSetup.ScreenTool 1.0
//自定义的标准按键
Button {
    id:             control
    hoverEnabled:   true
    topPadding:     _verticalPadding
    bottomPadding:  _verticalPadding
    leftPadding:    _horizontalPadding
    rightPadding:   _horizontalPadding
    focusPolicy:    Qt.ClickFocus

    property bool   primary:        false                               ///< primary button for a group of buttons
    property real   pointSize:      ScreenTool.defaultFontPointSize   ///< Point size for button text
    property bool   iconLeft:       false
    property real   backRadius:     0
    property real   heightFactor:   0.3
    property string iconSource

    property alias  wrapMode:            text.wrapMode
    property alias  horizontalAlignment: text.horizontalAlignment

    property bool   _showHighlight:     pressed | hovered | checked

    property int    _horizontalPadding:    ScreenTool.defaultFontPixelWidth
    property int    _verticalPadding:      Math.round(ScreenTool.defaultFontPixelWeight * heightFactor)


    background: Rectangle {
        id:             backRect
        radius:         backRadius
        color:"white"
        implicitWidth:   Math.round(ScreenTool.defaultFontPixelWidth *  (ScreenTool.isAndroid ? 7.0 : 5.0))
        implicitHeight:  Math.round(ScreenTool.defaultFontPixelWidth * (ScreenTool.isAndroid ? 2.0 : 1.6))
    }

    contentItem: Item {
        implicitWidth:  text.implicitWidth + icon.width
        implicitHeight: text.implicitHeight
        baselineOffset: text.y + text.baselineOffset

        FreeKImage {
            id:                     icon
            source:                 control.iconSource
            height:                 source === "" ? 0 : text.height
            width:                  height
            color:                  text.color
            fillMode:               Image.PreserveAspectFit
            sourceSize.height:      height
            anchors.left:           control.iconLeft ? parent.left : undefined
            anchors.leftMargin:     control.iconLeft ? ScreenTool.defaultFontPixelWidth : undefined
            anchors.right:          !control.iconLeft ? parent.right : undefined
            anchors.rightMargin:    !control.iconLeft ? ScreenTool.defaultFontPixelWidth : undefined
            anchors.verticalCenter: parent.verticalCenter
        }

        Text {
            id:                     text
            anchors.centerIn:       parent
            antialiasing:           true
            text:                   control.text
            font.pointSize:         pointSize
        }
    }
}
