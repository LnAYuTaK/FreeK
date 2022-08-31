#ifndef APPSETTING_H
#define APPSETTING_H

#include <QObject>
#include <QDir>
class FreeKApplication;
class AppSetting : public QObject
{
    Q_OBJECT
public:


    explicit AppSetting(QObject *parent = nullptr);
    Q_PROPERTY(QString savePath          READ savePath       CONSTANT)
    Q_PROPERTY(QString logSavePath       READ logSavePath    CONSTANT)
    Q_PROPERTY(QString cacheSavePath     READ cacheSavePath   CONSTANT)
    Q_PROPERTY(QString photoSavePath     READ photoSavePath  CONSTANT)

    QString  savePath();
    QString  logSavePath();
    QString  cacheSavePath();
    QString  photoSavePath();
private:
    //RootFilepath
    static const QString _logDirectory;
    static const QString _cacheDirectory;
    static const QString _photoDirectory;

    QString saveDirectoryPath;

    QDir rootDir;

    void _checkSavePathDirectories(void);
signals:
    void savePathsChanged();
};

#endif // APPSETTING_H
