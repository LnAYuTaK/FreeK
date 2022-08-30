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
    core-private

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
            src/Test
SOURCES += \
    src/AppMsg/AppMsgManager.cpp \
    src/Map/MapManager.cpp \
    src/ScreenTool.cpp \
    src/Test/test.cpp \
    src/ViewPlugin/ViewPluginManager.cpp \
    src/Module/ModuleBox.cpp \
    src/FreekApplication.cpp \
    src/ViewSetup/ViewSetup.cpp \
    src/main.cpp
HEADERS += \
    src/AppMsg/AppMsgManager.h \
    src/FreekApplication.h \
    src/Map/MapManager.h \
    src/Module/ModuleBox.h \
    src/ScreenTool.h \
    src/Test/test.h \
    src/ViewPlugin/ViewPluginManager.h \
    src/ViewSetup/ViewSetup.h

#===================================
#QML
QML_IMPORT_PATH += $$PWD/src/QmlView







#===================================
#Resources
RESOURCES += \
    src/QmlView/qml.qrc

#===============================
#生成Makefile
TEMPLATE = app
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
MOC_DIR     = temp/moc
RCC_DIR     = temp/rcc
UI_DIR      = temp/ui
OBJECTS_DIR = temp/obj
#指定编译生成的可执行文件到bin目录
DESTDIR     = bin
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





