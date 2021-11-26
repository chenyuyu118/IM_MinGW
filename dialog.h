#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>
#include <QJsonObject>
#include <QStandardItemModel>
#include "messagedelegate.h"

class EmotionWindow;

namespace Ui {
class Dialog;
}

class Dialog : public QWidget
{
    // 和一个人聊天的消息框
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    Dialog(QString id, QWidget *parent = nullptr);
    Dialog(QString id, QPixmap profile, QString sendId, QString nickName, QWidget *parent = nullptr);
    QString getId();
    ~Dialog();

signals:
    void sendMessage(QString id, QJsonObject); // 发送消息
public slots:


private slots:

    void on_emojiButton_clicked(); // 打开表情窗口

    void on_submit_clicked(); // 发送信息

private:
    Ui::Dialog *ui;

    QString targetId; // 聊天对方id
    QPixmap profile;// 聊天对方头像
    QString sendId; // 聊天自己id
    QString name; // 自己呢称
    QString nickName; // 聊天对方备注
    EmotionWindow *emotionWindow; // 表情框

    // 消息的模型和代理
    QStandardItemModel *thisMode;
    MessageDelegate messageDelegate;

};

#endif // DIALOG_H
