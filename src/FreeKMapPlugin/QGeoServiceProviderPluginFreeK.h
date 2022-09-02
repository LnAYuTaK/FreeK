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

#ifndef QGEOSERVICEPROVIDERFreeK_H
#define QGEOSERVICEPROVIDERFreeK_H

#include <QtCore/QObject>
#include <QtLocation/QGeoServiceProviderFactory>
#include <QtPlugin>
/// \brief The QGeoServiceProviderFactoryFreeK class
///QGeoServiceProviderFactory地图服务插件实现
/// 暂时只实现地图映射
class QGeoServiceProviderFactoryFreeK: public QObject, public QGeoServiceProviderFactory
{
    Q_OBJECT
    //是否生成dll文件
    Q_INTERFACES(QGeoServiceProviderFactory)
    //配置描述文件
    Q_PLUGIN_METADATA(IID "org.qt-project.qt.geoservice.serviceproviderfactory/5.0" FILE "freek_maps_plugin.json")
public:
    //位置搜索引擎,实现位置地理编码
    QGeoCodingManagerEngine*    createGeocodingManagerEngine (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    //地图映射管理器引擎
    QGeoMappingManagerEngine*   createMappingManagerEngine   (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    //路径规划引擎,实现路径规划
    QGeoRoutingManagerEngine*   createRoutingManagerEngine   (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
    //位置搜索引擎,实现位置搜索
    QPlaceManagerEngine*        createPlaceManagerEngine     (const QVariantMap &parameters, QGeoServiceProvider::Error *error, QString *errorString) const;
};

#endif // QGEOSERVICEPROVIDERFreeK_H
