#ifndef MESSAGELISTDATA_H
#define MESSAGELISTDATA_H
#include <QObject>
#include <QString>
#include <QPixmap>


typedef struct {
    QString id;
    QString nickname;
    QPixmap profile;
} MessageListData; // 自定义聊天列表信息

Q_DECLARE_METATYPE(MessageListData);
#endif // MESSAGELISTDATA_H
