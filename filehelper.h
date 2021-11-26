#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <QString>

/**
 * @brief The FileHelper class
 * 将二进制文件转换为Base64编码
 */
class FileHelper
{
public:
    FileHelper();
    bool file2Base64String(const QString filePath, QString &base64String);
    bool base64String2File(const QString filePath, const QString &base64String);
};

#endif // FILEHELPER_H
