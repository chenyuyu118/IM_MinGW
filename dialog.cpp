#include "dialog.h"
#include "ui_dialog.h"
#include "emotionwindow.h"
#include "textqjsonhelper.h"
#include "messagedata.h"
#include <QDebug>
#include <QTime>
#include <QDateTime>

Dialog::Dialog(QWidget *parent) : QWidget(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->resize(600, 700);
    thisMode = new QStandardItemModel;
    ui->listView->setItemDelegate(&messageDelegate);
    emotionWindow = nullptr;
}

Dialog::Dialog(QString id, QWidget *parent):
QWidget(parent), ui(new Ui::Dialog), targetId(id)
{
    ui->setupUi(this);
    this->resize(600, 700);
    thisMode = new QStandardItemModel;
    ui->listView->setItemDelegate(&messageDelegate);
    emotionWindow = nullptr;
}

Dialog::Dialog(QString id, QPixmap profile, QString sendId, QString nickName, QWidget *parent):
    QWidget (parent),
   ui(new Ui::Dialog),
    targetId(id),
  profile(profile),
  sendId(sendId),
  nickName(nickName)
{
    ui->setupUi(this);
    this->resize(600, 700);
    thisMode = new QStandardItemModel;
    ui->listView->setModel(thisMode);
    ui->listView->setItemDelegate(&messageDelegate);
    emotionWindow = nullptr;
}

QString Dialog::getId()
{
    return targetId;
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_emojiButton_clicked()
{
    // 创建表情选择框

    if(!emotionWindow)
    {
        emotionWindow = new EmotionWindow;
        connect(emotionWindow, &EmotionWindow::emotionClicked, [=](QString & path, bool isStatic)
        {
            if(isStatic)
            {
                ui->textEdit->addStaticQrcEmotion(path);
            }
            else {
                ui->textEdit->addEmojiGif(path);
            }

        });
//                ui->textEdit, SLOT(addEmojiGif()));
    }
    int x = ui->emojiButton->rect().right() + this->topLevelWidget()->x();
    int y = ui->emojiButton->y() + this->topLevelWidget()->y() - emotionWindow->height() + 2 * ui->emojiButton->rect().height();

    emotionWindow->setGeometry(x, y, emotionWindow->width(), emotionWindow->height());
    emotionWindow->setWindowFlag(Qt::Popup);
    emotionWindow->show();
}

void Dialog::on_submit_clicked()
{
    // 发送消息
    name = "狗子";
    // 整合消息
    QJsonObject *message = new QJsonObject;
    TextQJsonHelper::textEdit2QJsonObject(ui->textEdit, *message); // 打包信息为json
    ui->textEdit->clear();

//    obj->insert("isMine", true);
//    obj->insert("time", QDateTime::currentDateTime().toString());
//    obj->insert("message", *message);
//    obj->insert("targetId", targetId);
//    obj->insert("sendId", sendId);
//    obj->insert("name", name);

    MessageData *data = new MessageData;
    data->name = name;
    data->time = QTime::currentTime().toString();
    data->isMine = true;
    data->text = *message;
    qDebug() << ui->textEdit->toPlainText();
    // 加入到数据模型
    QStandardItem *item = new QStandardItem();
    item->setData(QVariant::fromValue(*data), Qt::UserRole+1);
    thisMode->appendRow(item);
    ui->listView->openPersistentEditor(thisMode->indexFromItem(item)); // 打开编辑器
    // 发射一个信号
}
