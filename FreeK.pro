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

SOURCES += \
    src/FreekApplication.cpp \
    src/Module/Module.cpp \
    src/main.cpp

#生成Makefile
TEMPLATE = app

#C11
CONFIG += c++11
 #程序执行使用使用UTF-8
QMAKE_CXXFLAGS += -execution-charset:utf-8
 #编译器使用UTF-8
QMAKE_CXXFLAGS += -source-charset:utf-8
#禁止未使用变量警告


# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/FreekApplication.h \
    src/Module/Module.h
