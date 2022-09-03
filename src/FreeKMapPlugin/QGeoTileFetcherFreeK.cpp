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

//#include "MapEngine.h"
#include "QGeoTileFetcherFreeK.h"

#include <QtCore/QLocale>
#include <QtNetwork/QNetworkRequest>
#include <QtLocation/private/qgeotilespec_p.h>
#include "QGeoMapReplyFreeK.h"

#include <QDebug>
#include <QSize>
#include <QDir>
#include <QUrl>
#include <QUrlQuery>
#include <QTime>
#include <QNetworkProxy>
#include <QtCore/QJsonDocument>
#include <math.h>
#include <QtCore/QJsonObject>
#include <map>
#include "FreekApplication.h"
#include "ModuleBox.h"
#include "MapEngine.h"
#include "FreeKUrlFactory.h"
//-----------------------------------------------------------------------------
QGeoTileFetcherFreeK::QGeoTileFetcherFreeK(QGeoTiledMappingManagerEngine *parent)
    : QGeoTileFetcher(parent)
    , _networkManager(new QNetworkAccessManager(this))
{
    //-- Check internet status every 30 seconds or so
    connect(&_timer, &QTimer::timeout, this, &QGeoTileFetcherFreeK::timeout);
    _timer.setSingleShot(false);
    _timer.start(30000);
}

//-----------------------------------------------------------------------------
QGeoTileFetcherFreeK::~QGeoTileFetcherFreeK()
{

}



//-----------------------------------------------------------------------------
void
QGeoTileFetcherFreeK::_getSecAmapWords(int x,int y,QString &sec1,QString &sec2)
{
    sec1 = ""; // after &x=...
    sec2 = ""; // after &zoom=...
    int seclen = ((x * 3) + y) % 8;
    sec2 = _secAmapWord.left(seclen);
    if (y >= 10000 && y < 100000) {
        sec1 = "&s=";
    }
}
//-----------------------------------------------------------------------------
///Test
QString
QGeoTileFetcherFreeK::_getURl(int type, int x, int y, int zoom)
{
    switch (type) {
    case 0:
    case 1: //Road Map
    {
        QString sec1    = ""; // after &x=...
        QString sec2    = ""; // after &zoom=...
        _getSecAmapWords(x, y, sec1, sec2);

        return QString("http://wprd03.is.autonavi.com/appmaptile?style=7&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
    }
    break;
    case 2: //Satallite Map
    {
        QString sec1    = ""; // after &x=...
        QString sec2    = ""; // after &zoom=...
        _getSecAmapWords(x, y, sec1, sec2);
        return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=7&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
    }
    break;
    case 3: //Terrain Map
    {
        QString sec1    = ""; // after &x=...
        QString sec2    = ""; // after &zoom=...
        _getSecAmapWords(x, y,sec1,sec2);
        return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=6&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
    }
    break;
    case 4: //Hybrid Map
    {
        QString sec1    = ""; // after &x=...
        QString sec2    = ""; // after &zoom=...
        _getSecAmapWords(x, y, sec1, sec2);
        return QString("http://wprd03.is.autonavi.com/appmaptile?lang=zh_cn&size=1&style=8&x=%1&y=%2&z=%3").arg(x).arg(y).arg(zoom);
    }
    break;
    }
    return "";
}

//-----------------------------------------------------------------------------
QGeoTiledMapReply*
QGeoTileFetcherFreeK::getTileImage(const QGeoTileSpec &spec)
{
    QNetworkRequest request =  getMapEngine()->freeKUrlFactory()->getTileURL(spec.mapId(), spec.x(), spec.y(), spec.zoom(), _networkManager);
    if ( ! request.url().isEmpty() ) {
        return new QGeoTiledMapReplyFreeK(_networkManager, request, spec);
    }
    else {
        return nullptr;
    }
}
//-----------------------------------------------------------------------------
void
QGeoTileFetcherFreeK::timeout()
{
    //getQGCMapEngine()->testInternet();
}
