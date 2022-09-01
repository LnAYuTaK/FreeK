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
            src/ViewPlugin \
            src/AppMsg   \
            src/ViewSetup \
            src/Test  \
            src/Settings
SOURCES += \
    src/AppMsg/AppMsgManager.cpp \
    src/Map/MapEngine.cpp \
    src/Map/MapManager.cpp \
    src/Map/MapTask.cpp \
    src/Map/MapTaskWorker.cpp \
   #src/Map/QGeoCodeReplyFreeK.cpp \
   #src/Map/QGeoCodingManagerEngineFreeK.cpp \
   src/Map/QGeoMapReplyFreeK.cpp \
   src/Map/QGeoServiceProviderPluginFreeK.cpp \
   src/Map/QGeoTileFetcherFreeK.cpp \
   src/Map/QGeoTiledMappingManagerEngineFreeK.cpp \
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
   #src/Map/QGeoCodeReplyFreeK.h \
   #src/Map/QGeoCodingManagerEngineFreeK.h \
   src/Map/QGeoMapReplyFreeK.h \
   src/Map/QGeoServiceProviderPluginFreeK.h \
   src/Map/QGeoTileFetcherFreeK.h \
   src/Map/QGeoTiledMappingManagerEngineFreeK.h \
    src/Module/ModuleBox.h \
    src/ScreenTool.h \
    src/Settings/AppSetting.h \
    src/Settings/SettingsManager.h \
    src/Test/test.h \
    src/ViewPlugin/ViewPluginManager.h \
    src/ViewSetup/ViewSetup.h


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
CONFIG += plugin
 #程序执行使用使用UTF-8
#QMAKE_CXXFLAGS += -execution-charset:utf-8
 #编译器使用UTF-8
#QMAKE_CXXFLAGS += -source-charset:utf-8
#程序版本
VERSION  = 1.0
#===============================
#编译选项
#DEFINES += NOTUSEDMAP
DISTFILES += \
    $$PWD/src/Map/freek_maps_plugin.json


#===============================
#指定编译生成的文件到temp目录 分门别类存储
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj

#指定编译生成的可执行文件到bin目录
DESTDIR     = bin
#TEMPLATE=lib
#CONFIG     += plugin

#===============================
#message(qt version: $$QT_VERSION)
#message($$QT_ARCH)

#===============================
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

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





