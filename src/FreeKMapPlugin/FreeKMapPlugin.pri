INCLUDEPATH += $$QT.location.includes
QT -= gui
QT += core
QT += sql
QT += network
QT += concurrent
qtHaveModule(location-private){
    QT += location-private
}else{
    QT += location
}
qtHaveModule(positioning-private){
    QT += positioning-private
}else{
    QT += positioning
}

CONFIG += c++11
HEADERS += \
 #$$PWD/QGeoCodingManagerEngineFreeK.h \
 $$PWD/QGeoMapReplyFreeK.h \
 $$PWD/QGeoServiceProviderPluginFreeK.h \
 $$PWD/QGeoTileFetcherFreeK.h \
 $$PWD/QGeoTiledMappingManagerEngineFreeK.h \
  \
 #$$PWD/QGeoCodeReplyFreeK.h

SOURCES += \
    #$$PWD/QGeoCodeReplyFreeK.cpp \
    #$$PWD/QGeoCodingManagerEngineFreeK.cpp \
    $$PWD/QGeoMapReplyFreeK.cpp \
    $$PWD/QGeoServiceProviderPluginFreeK.cpp \
    $$PWD/QGeoTileFetcherFreeK.cpp \
    $$PWD/QGeoTiledMappingManagerEngineFreeK.cpp

OTHER_FILES += \
    $$PWD/freek_maps_plugin.json
