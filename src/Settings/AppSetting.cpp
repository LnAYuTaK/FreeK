#include "AppSetting.h"
#include "FreekApplication.h"
#include <QDir>
#include <QStandardPaths>
const QString  AppSetting::_logDirectory       = "Log";
const QString  AppSetting::_cacheDirectory     = "Cache";
const QString  AppSetting::_photoDirectory     = "Photo";

AppSetting::AppSetting(QObject *parent)
    : QObject{parent}
{
#ifdef Q_OS_ANDROID
    rootDir = QDir(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation));
#else
    rootDir = QDir(QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation));
#endif
    saveDirectoryPath =  rootDir.absolutePath()+"/"+FreeKApp()->applicationName();
    _checkSavePathDirectories();
}
//-----------------------------------------------------------------------------
QString
AppSetting::savePath()
{
   QDir savePath = QDir(saveDirectoryPath);
   if(!savePath.exists()) {
      rootDir.mkpath(saveDirectoryPath);
   }
   return saveDirectoryPath;
}
//-----------------------------------------------------------------------------
QString
AppSetting::logSavePath()
{

    QString path = saveDirectoryPath;
    if(!path.isEmpty() && QDir(path).exists()) {
        QDir dir(path);
        return dir.filePath(_logDirectory);
    }
    return QString();
}
//-----------------------------------------------------------------------------
QString
AppSetting::cacheSavePath(){
    QString path = saveDirectoryPath;
    if(!path.isEmpty() && QDir(path).exists()) {
        QDir dir(path);
        return dir.filePath(_cacheDirectory);
    }
    return QString();
}
//-----------------------------------------------------------------------------
QString
AppSetting::photoSavePath(){
    QString path = saveDirectoryPath;
    if(!path.isEmpty() && QDir(path).exists()) {
        QDir dir(path);
        return dir.filePath(_photoDirectory);
    }
    return QString();
}
//-----------------------------------------------------------------------------
void
AppSetting::_checkSavePathDirectories(void) {

    QDir savePathDir(savePath());
    if (!savePathDir.exists()) {
        QDir().mkpath(savePathDir.absolutePath());
    }
    if (savePathDir.exists()) {
        savePathDir.mkdir(_logDirectory);
        savePathDir.mkdir(_cacheDirectory);
        savePathDir.mkdir(_photoDirectory);
    }
}
