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
    widgets \
    xml \
    texttospeech \
    core-private \
    location-private \
    positioning-private

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
FreeKName = "FreeKAPP"

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
            src/Position

SOURCES += \
    src/AppMsg/AppMsgManager.cpp \
    src/Map/MapEngine.cpp \
    src/Map/MapManager.cpp \
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
    src/FreekApplication.h \
    src/Map/MapEngine.h \
    src/Map/MapManager.h \
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
#地图插件
include($$PWD/src/FreeKMapPlugin/FreeKMapPlugin.pri)
LOCATION_PLUGIN_DESTDIR = $${OUT_PWD}/src/FreeMapPlugin
LOCATION_PLUGIN_NAME    = GeoServiceProviderFactoryFreeK
#===================================
#QML
QML_IMPORT_PATH += $$PWD/src/QmlView


# Workaround for QTBUG-38735
#QT_FOR_CONFIG += location-private
#qtConfig(geoservices_mapboxgl): QT += sql opengl
#qtConfig(geoservices_osm): QT += concurrent

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
#DISTFILES += \
#    src/FreeKMapPlugin/FreeKMapPlugin.pri \
#    src/FreeKMapPlugin/freek_maps_plugin.json \
#    src/Map/FreeKMapPlugin/FreeKMapPlugin.pri
#===============================
#指定编译生成的文件到temp目录 分门别类存储
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
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





