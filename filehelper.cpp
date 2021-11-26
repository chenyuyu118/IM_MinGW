#include "filehelper.h"
#include <QFile>
#include <QDebug>
#include <QCoreApplication>

FileHelper::FileHelper()
{

}

bool FileHelper::file2Base64String(const QString filePath, QString &base64String)
{
    QFile f(filePath);
    qDebug() << filePath;
    if(!f.open(QIODevice::ReadOnly)){
        qDebug() << "file open error";
        return false;
    }

    QByteArray byteArray = f.readAll();
    base64String = byteArray.toBase64();

    f.close();
    return true;
}

bool FileHelper::base64String2File(const QString filePath, const QString &base64String)
{
    QByteArray byteArray;
    byteArray = QByteArray::fromBase64(base64String.toUtf8());

    QFile f(filePath);
    if(!f.open(QIODevice::WriteOnly)){
        qDebug() << "file open error";
        return false;
    }

    f.write(byteArray);
    f.close();

    return true;
}
