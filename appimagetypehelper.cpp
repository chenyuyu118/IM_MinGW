#include "appimagetypehelper.h"
#include <QMimeDatabase>
#include <QMimeType>
#include <QDebug>

AppImageTypeHelper::AppImageTypeHelper()
{

}

/**
 * @brief AppImageTypeHelper::getImageType
 * 根据文件名确定文件类型。需要了解MimeType的知识
 * @param fileName
 * @return
 */
ImageType AppImageTypeHelper::getImageType(QString *fileName)
{
    QMimeDatabase db;
    QMimeType mime = db.mimeTypeForFile(*fileName);
    if (mime.name().startsWith("image/gif")) {
        return ImageType::GIF;
    }
    else{
        //qDebug() << "fileName = " << fileName << " : mimeType = " << mime.name();
        return ImageType::NOT_GIF;
    }

}
