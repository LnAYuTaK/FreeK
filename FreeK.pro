QT += \
    concurrent \
    gui \
    location \
    network \
    opengl \
    positioning \
    qml \
    quick \
    quickcontrols2 \
    quickwidgets \
    sql \
    svg \
    serialport\
    widgets \
    xml \
    texttospeech \
    core-private \
    location-private \
    testlib \
    positioning-private

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#===============================
# C++ src
INCLUDEPATH += \
            src/       \
            src/Module  \
            src/Map    \
            src/FreeMapPlugin\
            src/ViewPlugin \
            src/AppMsg   \
            src/ViewSetup \
            src/Test  \
            src/Settings \
            src/Position \
            src/LinkCommon

SOURCES += \
    src/AppMsg/AppMsgManager.cpp \
    src/FreeKQmlGlobal.cpp \
    src/LinkCommon/LinkConfig.cpp \
    src/LinkCommon/LinkInterface.cpp \
    src/LinkCommon/LinkManager.cpp \
    src/LinkCommon/MavLinkProtocol.cpp \
    src/LinkCommon/ProtocolManager.cpp \
    src/LinkCommon/SerialLink.cpp \
    src/LinkCommon/TCPLink.cpp \
    src/Map/MapEngine.cpp \
    src/Map/MapEngineManager.cpp \
    src/Map/MapTask.cpp \
    src/Map/MapTaskWorker.cpp \
    src/Position/PositionManager.cpp \
    src/ScreenTool.cpp \
    src/Settings/AppSetting.cpp \
    src/Settings/SettingsManager.cpp \
    src/Test/test.cpp \
    src/ViewPlugin/ViewPluginManager.cpp \
    src/Module/ModuleBox.cpp \
    src/FreekApplication.cpp \
    src/ViewSetup/ViewSetup.cpp \
    src/main.cpp

HEADERS += \
    src/AppMsg/AppMsgManager.h \
    src/FreeKQmlGlobal.h \
    src/FreekApplication.h \
    src/LinkCommon/LinkConfig.h \
    src/LinkCommon/LinkInterface.h \
    src/LinkCommon/LinkManager.h \
    src/LinkCommon/MavLinkProtocol.h \
    src/LinkCommon/ProtocolManager.h \
    src/LinkCommon/SerialLink.h \
    src/LinkCommon/TCPLink.h \
    src/Map/MapEngine.h \
    src/Map/MapEngineManager.h \
    src/Map/MapTask.h \
    src/Map/MapTaskWorker.h \
    src/Module/ModuleBox.h \
    src/Position/PositionManager.h \
    src/ScreenTool.h \
    src/Settings/AppSetting.h \
    src/Settings/SettingsManager.h \
    src/Test/test.h \
    src/ViewPlugin/ViewPluginManager.h \
    src/ViewSetup/ViewSetup.h

#===================================
#Lib  MAVLINK
INCLUDEPATH += \
         libs/mavlink/include/mavlink/v2.0 \
         libs/mavlink/include/mavlink/v2.0/common

#===================================
#地图插件
include($$PWD/src/FreeKMapPlugin/FreeKMapPlugin.pri)
LOCATION_PLUGIN_DESTDIR = $${OUT_PWD}/src/FreeMapPlugin
LOCATION_PLUGIN_NAME    = GeoServiceProviderFactoryFreeK

#
#===================================
#QML
QML_IMPORT_PATH += $$PWD/src/QmlView

#===================================
#Resources
RESOURCES += \
    src/QmlView/qml.qrc

#===============================
#生成Makefile
#TEMPLATE = app
#C11
CONFIG += c++11
 #程序执行使用使用UTF-8
#QMAKE_CXXFLAGS += -execution-charset:utf-8
 #编译器使用UTF-8
#QMAKE_CXXFLAGS += -source-charset:utf-8
#程序版本
VERSION  = 1.0
#===============================
#编译选项
#DEFINES += NOTUSEDMAP





#===============================
#指定编译生成的文件到temp目录 分门别类存储
MOC_DIR     = build/moc
RCC_DIR     = build/rcc
UI_DIR      = build/ui
OBJECTS_DIR = build/obj
DESTDIR     = bin
#指定编译生成的可执行文件到bin目录
#===============================
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#===============================
#ANDROID
DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/gradle.properties \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat \
    android/res/values/libs.xml

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
#===============================





