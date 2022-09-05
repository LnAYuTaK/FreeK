
import QtQuick          2.3
import QtQuick.Controls 2.4
import FreeK.ViewSetup.ScreenTool 1.0

// Important Note: Toolbar buttons must manage their checked state manually in order to support
// view switch prevention. This means they can't be checkable or autoExclusive.

Button {
    id:                 button
    height:             ScreenTool.defaultFontPixelHeight * 3
    leftPadding:        _horizontalMargin
    rightPadding:       _horizontalMargin
    checkable:          false
    property bool logo: false
    property real _horizontalMargin: ScreenTool.defaultFontPixelWidth

    onCheckedChanged: checkable = false
    FreeKImage {
            id:                     _icon
            fillMode:               Image.PreserveAspectFit
            source:                 button.icon.source
            anchors.verticalCenter: parent.verticalCenter
    }
}

