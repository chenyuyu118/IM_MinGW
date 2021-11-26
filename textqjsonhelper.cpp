#include "textqjsonhelper.h"
#include "appimagetypehelper.h"
#include "filehelper.h"
#include "cbasechatedit.h"

#include <QMimeData>
#include <QDebug>
#include <QJsonArray>
#include <QFileInfo>
#include <QJsonDocument>

TextQJsonHelper::TextQJsonHelper()
{

}

void TextQJsonHelper::textEdit2QJsonObject(const CBaseChatEdit *textEdit, QJsonObject &jsonObject)
{
    QJsonObject imageObject;               // 图片名:Base64编码
    QJsonObject textOrderObject;           // 序号:内容
    QJsonArray order;                      // 序号对应的类型

    QFileInfo fileInfo;                    // 探查文件信息
    FileHelper fileHelper;                 // 获取文件的Base64

    int num = 0;
    int lastBlockType = -1;
    QTextDocument *doc = textEdit->document();
    QTextBlock block = doc->begin();
    // 按块遍历
    for (; block != doc->end(); block = block.next())
    {
        // 遇到回车前视为一个块，块内包含多个TextFrament，所以还得循环
        QTextBlock::iterator it = block.begin();
        for(; it != block.end(); it++)
        {
            // 图片
            QTextImageFormat imageFormat = it.fragment().charFormat().toImageFormat();
            if(imageFormat.isValid())
            {
                QString path = imageFormat.name();
                switch (AppImageTypeHelper::getImageType(&path))
                {
                case ImageType::GIF:
                    // 内部资源文件，存全路径 （":/resource/..."）
                    order.push_back(APP_GIF);
                    textOrderObject.insert(QString("app_gif%1").arg(num++), path);
                    break;
                case ImageType::NOT_GIF:
                    // 外部图片文件，只存名字就好了 （"fileName.jpg"...）
                    // (key:value) -> (image%d:fileName)
                    if(path.contains(":"))
                    {
                        // 内部资源文件，存全路径 （":/resource/..."）
                        order.push_back(APP_GIF);
                        textOrderObject.insert(QString("app_gif%1").arg(num++), path);
                        break;
                    }
                    order.push_back(IMAGE);
                    fileInfo.setFile(path);
                    textOrderObject.insert(QString("image%1").arg(num++), fileInfo.fileName());

                    // 存储
                    // (key:value) -> (fileName:base64String)
                    QString base64;
                    fileHelper.file2Base64String(path, base64);
                    imageObject.insert(fileInfo.fileName(), base64);
                    break;
                }
            }
            // 文字
            else
            {
                order.push_back(TEXT);
                // 如果是最后一行，不用+"\n"
                textOrderObject.insert(QString("text%1").arg(num++), it.fragment().text());
            }
        }
        if(block != doc->end())
        {
            order.push_back(TEXT);
            textOrderObject.insert(QString("text%1").arg(num++), "\n");
        }
    }
    // order 数组插入 textOrderObject Json
    textOrderObject.insert("order", order);

    // 插入大的Json
    jsonObject.insert("image_base64", imageObject);
    jsonObject.insert("text_order", textOrderObject);

}

void TextQJsonHelper::QJsonObject2TextEdit(CBaseChatEdit *textEdit, QJsonObject &jsonObject)
{
    QJsonObject textOrderObject =  jsonObject.value("text_order").toObject();
    QJsonArray order = textOrderObject.value("order").toArray();

    QJsonValue value;
    QString path;
    for(int i = 0; i < order.size(); i++)
    {
        /* 文本 */
        if(order[i].toInt() == TEXT)
        {
            value = textOrderObject.value(QString("text%1").arg(i));
            textEdit->insertPlainText(value.toString());
        }
        else if(order[i].toInt() == APP_GIF)
        {
            value = textOrderObject.value(QString("app_gif%1").arg(i));
            path = value.toString();
            textEdit->dropImageByUrl(path);
        }
        else if(order[i].toInt() == IMAGE)
        {
            value = textOrderObject.value(QString("image%1").arg(i));
            QString path = "../richOle/" +  value.toString();
            textEdit->dropImageByUrl(path);
        }
    }
}
