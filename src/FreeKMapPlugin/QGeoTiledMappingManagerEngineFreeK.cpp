/****************************************************************************
**
** Copyright (C) 2013 Aaron McCarthy <mccarthy.aaron@gmail.com>
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtLocation module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
** 2015.4.4
** Adapted for use with QGroundControl
**
** Gus Grubba <gus@auterion.com>
**
****************************************************************************/

#include "QGeoTiledMappingManagerEngineFreeK.h"
#include "QGeoTileFetcherFreeK.h"

#include <QtLocation/private/qgeocameracapabilities_p.h>
#include <QtLocation/private/qgeomaptype_p.h>
#include <QtLocation/private/qgeotiledmap_p.h>
#include <QtLocation/private/qgeofiletilecache_p.h>

#include "SettingsManager.h"
#include <QStandardPaths>
#include "AppSetting.h"

//-----------------------------------------------------------------------------
QGeoTiledMapFreeK::QGeoTiledMapFreeK(QGeoTiledMappingManagerEngine *engine, QObject *parent)
    : QGeoTiledMap(engine, parent)
{

}

//-----------------------------------------------------------------------------
QGeoTiledMappingManagerEngineFreeK::
QGeoTiledMappingManagerEngineFreeK(
        const QVariantMap &parameters
        ,QGeoServiceProvider::Error *error
        ,QString *errorString)
        :QGeoTiledMappingManagerEngine()
{
     //parameters 就是QML中设置的 PluginParameter
     //地图视角相关设置，对应到 QML Map 类型的属性
     QGeoCameraCapabilities capabilities;
     capabilities.setMinimumZoomLevel(1.96);
     capabilities.setMaximumZoomLevel(20.88);
     capabilities.setSupportsBearing(true);
     capabilities.setSupportsTilting(true);
     capabilities.setMinimumTilt(0);
     capabilities.setMaximumTilt(80);
     capabilities.setMinimumFieldOfView(20.0);
     capabilities.setMaximumFieldOfView(120.0);
     capabilities.setOverzoomEnabled(true);
     setCameraCapabilities(capabilities);
     //瓦片大小
     setTileSize(QSize(256, 256));
     //支持地图样式
     QList<QGeoMapType> types;
     //QGeoCameraCapabilities cameraCapabilities;
     types << QGeoMapType(QGeoMapType::StreetMap, tr("Road Map"), tr("Normal map view in daylight mode"), false,false, 1, "freeKMap", capabilities);
     types << QGeoMapType(QGeoMapType::TerrainMap, tr("Terrain"), tr("Terrain map view in daylight mode"), false, false, 2, "freeKMap", capabilities);
     types << QGeoMapType(QGeoMapType::SatelliteMapDay, tr("Satellite"), tr("Satellite map view in daylight mode"), false, false, 3, "freeKMap", capabilities);
     types << QGeoMapType(QGeoMapType::HybridMap, tr("Hybrid"), tr("Satellite map view with streets in daylight mode"), false, false, 4, "freeKMap", capabilities);
     setSupportedMapTypes(types);
     //设置瓦片地图获取
     setTileFetcher(new QGeoTileFetcherFreeK(this));
     //设置瓦片缓存
     QString cacheDirctory = FreeKApp()->moduleBox()->settingsManager()->appSetting()->cacheSavePath();
     QAbstractGeoTileCache *tileCache = new QGeoFileTileCache(cacheDirctory);
     tileCache->setMaxDiskUsage(100 * 1024 * 1024);
     setTileCache(tileCache);
     //ERROR处理
     *error = QGeoServiceProvider::NoError;
     errorString->clear();
}

//-----------------------------------------------------------------------------
QGeoTiledMappingManagerEngineFreeK::~QGeoTiledMappingManagerEngineFreeK()
{
}

//-----------------------------------------------------------------------------
QGeoMap*
QGeoTiledMappingManagerEngineFreeK::createMap()
{
    return new QGeoTiledMapFreeK(this);
}

//-----------------------------------------------------------------------------
//void
//QGeoTiledMappingManagerEngineQGC::_setCache(const QVariantMap &parameters)
//{
//    QString cacheDir;
//    if (parameters.contains(QStringLiteral("mapping.cache.directory")))
//        cacheDir = parameters.value(QStringLiteral("mapping.cache.directory")).toString();
//    else {
//        cacheDir = getQGCMapEngine()->getCachePath();
//        if(!QFileInfo::exists(cacheDir)) {
//            if(!QDir::root().mkpath(cacheDir)) {
//                qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
//                cacheDir = QDir::homePath() + QStringLiteral("/.qgcmapscache/");
//            }
//        }
//    }
//    if(!QFileInfo::exists(cacheDir)) {
//        if(!QDir::root().mkpath(cacheDir)) {
//            qWarning() << "Could not create mapping disk cache directory: " << cacheDir;
//            cacheDir.clear();
//        }
//    }
//    //-- Memory Cache
//    uint32_t memLimit = 0;
//    if (parameters.contains(QStringLiteral("mapping.cache.memory.size"))) {
//      bool ok = false;
//      memLimit = parameters.value(QStringLiteral("mapping.cache.memory.size")).toString().toUInt(&ok);
//      if (!ok)
//          memLimit = 0;
//    }
//    if(!memLimit)
//    {
//        //-- Value saved in MB
//        memLimit = getQGCMapEngine()->getMaxMemCache() * (1024 * 1024);
//    }
//    //-- It won't work with less than 1M of memory cache
//    if(memLimit < 1024 * 1024)
//        memLimit = 1024 * 1024;
//    //-- On the other hand, Qt uses signed 32-bit integers. Limit to 1G to round it down (you don't need more than that).
//    if(memLimit > 1024 * 1024 * 1024)
//        memLimit = 1024 * 1024 * 1024;
//    //-- Disable Qt's disk cache (sort of)
//    QAbstractGeoTileCache *pTileCache = new QGeoFileTileCache(cacheDir);
//    setTileCache(pTileCache);
//    if(pTileCache)
//    {
//        //-- We're basically telling it to use 100k of disk for cache. It doesn't like
//        //   values smaller than that and I could not find a way to make it NOT cache.
//        //   We handle our own disk caching elsewhere.
//        pTileCache->setMaxDiskUsage(1024 * 100);
//        pTileCache->setMaxMemoryUsage(memLimit);
//    }
//}
