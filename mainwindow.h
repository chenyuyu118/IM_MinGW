#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QStandardItemModel>
#include "communicatedialog.h"
#include "logindialog.h"
#include "registerdialog.h"
#include "mydatabase.h"
#include "addfrienddialog.h"
#include "messagelistdata.h"
#include "messagelistdelegate.h"

#include "mytcpclient.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:

    void on_messageList_doubleClicked(const QModelIndex &index); // 打开聊天框

    void on_settingButton_clicked(); // 设置按钮对应菜单

    void start_register(); // 开始注册菜单

    void initUi(QJsonObject); // 根据服务器传回到json初始化界面

    void clearActiveName(); // 清空活跃列表

    void refreshActiveName(QString); // 更新活跃列表


    void on_addFriendButton_clicked();

    void message_recieve(char *szbuf, int len);
    void dealRegisterRs(QJsonObject object);//处理注册返回包
    void dealLoginRs(QJsonObject object);//处理登录返回包
    void deal_MutiChatRs(QJsonObject object);//处理收到的复杂聊天消息包的函数
    //加好友相关函数⬇
    void deal_ADD_FRI_RQ(QJsonObject object);//处理好友请求申请包
    void deal_ADD_FRI_RQ_BACK(QJsonObject object);//处理好友状态返回包
    void deal_ADD_FRI_RS(QJsonObject object);//处理好友请求是否通过包


private:
    Ui::MainWindow *ui; // 主窗口UI
    CommunicateDialog *com; // 聊天框
    AddFriendDialog *add; // 添加好友框


public:
    LoginDialog *login; // 登陆框
    RegisterDialog *reg; // 注册框
    MyTcpClient *mytcpclient;


private:
    QMultiMap<QString, QString> friends; // 消息和好友的字典
    QMap<QString, QString> groups, meg; // 群组
    QString name; // 自己的名字
    QString id; // 账号
    QPixmap profile; // 头像
    QString signature; // 个性签名
    QStringList activeName; // 已经激活的聊天窗口
    MyDatabase DB; // 本地数据库

    QStandardItemModel *messageList, *friendList, *groupList;
    MessageListDelegate messgeDelegate;

    void closeEvent(QCloseEvent *event) override; // 覆写关闭事件


};

#endif // MAINWINDOW_H
