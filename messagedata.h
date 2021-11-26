#ifndef MESSAGEDATA_H
#define MESSAGEDATA_H
#include <QMetaType>
#include <QString>
#include <QImage>
#include <QJsonObject>
#include "cbasechatedit.h"

typedef struct {
    bool isMine; // 是否为本人消息
    QString time; // 时间
    QPixmap profile; //头像
    QJsonObject text;//
    QString name; // 呢称
    QString send_id; // 发送方id
    QString receive_id; // 接收方id
} MessageData; // 自定义数据模型中的项中复杂数据的结构体

Q_DECLARE_METATYPE(MessageData);
#endif // MESSAGEDATA_H
