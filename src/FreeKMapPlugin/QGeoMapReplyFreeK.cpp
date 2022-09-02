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

#include "MapEngine.h"
#include "QGeoMapReplyFreeK.h"
#include "QGeoTileFetcherFreeK.h"
#include "MapTask.h"
#include <QtLocation/private/qgeotilespec_p.h>
#include <QtNetwork/QNetworkAccessManager>
#include <QFile>
//#include "TerrainTile.h"

int         QGeoTiledMapReplyFreeK::_requestCount = 0;
QByteArray  QGeoTiledMapReplyFreeK::_bingNoTileImage;

//-----------------------------------------------------------------------------
QGeoTiledMapReplyFreeK::QGeoTiledMapReplyFreeK(QNetworkAccessManager *networkManager, const QNetworkRequest &request, const QGeoTileSpec &spec, QObject *parent)
    : QGeoTiledMapReply(spec, parent)
    , _reply(nullptr)
    , _request(request)
    , _networkManager(networkManager)
{

     _reply = networkManager->get(request);
     if (!_reply) {
          setError(UnknownError, QStringLiteral("Null reply"));
          return;
     }
     if(_request.url().isEmpty()) {
          if(!_badMapbox.size()) {
              QFile b(":/images/notile.png");
              if(b.open(QFile::ReadOnly))
                  _badMapbox = b.readAll();
          }
          setMapImageData(_badMapbox);
          setMapImageFormat("png");
          setFinished(true);
          setCached(false);
      }
      connect(_reply, SIGNAL(finished()), this, SLOT(networkReplyFinished()));
}

//-----------------------------------------------------------------------------
QGeoTiledMapReplyFreeK::~QGeoTiledMapReplyFreeK()
{
    _clearReply();
}

//-----------------------------------------------------------------------------
void
QGeoTiledMapReplyFreeK::_clearReply()
{
    _timer.stop();
    if (_reply) {
        _reply->deleteLater();
        _reply = nullptr;
        _requestCount--;
    }
}

//-----------------------------------------------------------------------------
void
QGeoTiledMapReplyFreeK::abort()
{
    _timer.stop();
    if (_reply)
        _reply->abort();
    emit aborted();
}

//-----------------------------------------------------------------------------
void
QGeoTiledMapReplyFreeK::networkReplyFinished()
{
    _timer.stop();
    if (!_reply) {
        emit aborted();
        return;
    }
    if (_reply->error() != QNetworkReply::NoError) {
        emit aborted();
        return;
    }
    QByteArray image  = _reply->readAll();
    setMapImageData(image);
    setFinished(true);
    _clearReply();
}

//-----------------------------------------------------------------------------
void
QGeoTiledMapReplyFreeK::networkReplyError(QNetworkReply::NetworkError error)
{
    _timer.stop();
    if (!_reply) {
        return;
    }
    _clearReply();
}
//-----------------------------------------------------------------------------
///
/// \brief QGeoTiledMapReplyFreeK::timeout
///有bug 大量请求失败会导致强退
void
QGeoTiledMapReplyFreeK::timeout()
{
    if(_reply) {
        _reply->abort();
    }
    emit aborted();
}
