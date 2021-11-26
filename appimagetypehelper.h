#ifndef APPIMAGETYPEHELPER_H
#define APPIMAGETYPEHELPER_H

#include <QString>

/**
 * @brief The ImageType enum
 * 用于判断是否为app内支持的GIF动图（存在qrc的资源文件就支持，非资源文件内的一律认为是图片）。
 */
enum class ImageType{
    GIF,        // 资源内GIF
    NOT_GIF,     // 普通图片
};

class AppImageTypeHelper
{
public:
    AppImageTypeHelper();
    static ImageType getImageType(QString *fileName);
};

#endif // APPIMAGETYPEHELPER_H
