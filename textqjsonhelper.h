#ifndef TEXTQJSONHELPER_H
#define TEXTQJSONHELPER_H

#include <QTextEdit>
#include <QJsonObject>
#include <QString>
#include <QTextBlock>

#define TEXT 0
#define APP_GIF 1
#define IMAGE 2
#define STATIC_IMAGE 3


class CBaseChatEdit;

class TextQJsonHelper
{
public:
    TextQJsonHelper();
    void static textEdit2QJsonObject(const CBaseChatEdit *textEdit, QJsonObject &jsonObject);
    void static QJsonObject2TextEdit(CBaseChatEdit *textEdit, QJsonObject &jsonObject);
};

#endif // TEXTQJSONHELPER_H
