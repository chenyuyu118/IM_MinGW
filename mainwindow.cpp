#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "communicatedialog.h"
#include "dialog.h"
#include "imagehelper.h"
#include "package.h"
#include "filehelper.h"
#include "mytcpclient.h"

#include <QDialog>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    reg = new RegisterDialog();
    login = new LoginDialog();
    com = new CommunicateDialog();
    messageList = new QStandardItemModel;
    groupList = new QStandardItemModel;
    friendList = new QStandardItemModel;
    mytcpclient = new MyTcpClient();
    mytcpclient->InitNetWork("192.168.195.133", 9989);

    connect(login, SIGNAL(startRegisterMenu()), this, SLOT(start_register()));
    connect(reg, SIGNAL(acceptRegister(QString)), login, SLOT(updateDB(QString)));
    connect(login, SIGNAL(loginSuccess(QJsonObject)), this, SLOT(initUi(QJsonObject)));
    connect(com, SIGNAL(clearActive()), this, SLOT(clearActiveName()));
    connect(com, SIGNAL(refreshActive(QString)), this, SLOT(refreshActiveName(QString)));
    connect(reg,SIGNAL(verifyRegister(char*,int)),mytcpclient,SLOT(SendData(char*,int)));//注册信息被提交后触发中介者senddata函数
    connect(login,SIGNAL(login_request(char*,int)),mytcpclient,SLOT(SendData(char*,int)));
    connect(mytcpclient,SIGNAL(SIG_ReadyData(char*,int)),this,SLOT(message_recieve(char*,int)));

    ui->messageList->setModel(messageList);
    ui->messageList->setItemDelegate(&messgeDelegate);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_messageList_doubleClicked(const QModelIndex &index)
{
    // 双击消息打开消息框
    QVariant var = index.data(Qt::UserRole+1);
    MessageListData itemData = var.value<MessageListData>();
    QString nickname = itemData.nickname;
    if (activeName.indexOf(nickname) == -1) {
        // 不在激活列表中
        QString name = index.data().toString();
        QString id = meg.key(name);
        com->add(itemData.id, itemData.profile, id, itemData.nickname);
        activeName.append(name);
    } else {
        com->setActive(index.data().toString());
    }
    if (com->isHidden())
        com->show();
}

void MainWindow::on_settingButton_clicked()
{

}

void MainWindow::start_register()
{
    reg->exec();
}

void MainWindow::initUi(QJsonObject obj)
{
    // 通过接受的json包来初始化界面
    QJsonObject fd = obj.value("FriendList").toObject();
    QJsonObject mg = obj.value("MessageList").toObject();
    QJsonObject gp = obj.value("GroupList").toObject();
    QJsonObject myinfo = obj.value("MyInfo").toObject();

    // 初始化聊天
    for (auto x: mg.keys()) {
        QString nickname = mg.value(x).toString();
        QString targetId = x;
        MessageListData data;
        data.id = id;
        data.nickname = nickname;
        qDebug() << "id = " << id << "name = " << nickname;
        QStandardItem *item = new QStandardItem;
        item->setData(QVariant::fromValue(data));
        meg.insert(x, nickname);
        meg.insert(x, name);
        messageList->appendRow(item);
    }

    // 初始化好友
    for (auto x: fd.keys()) {
        QTreeWidgetItem *item = new QTreeWidgetItem(1001);
        item->setText(0, x);
        ui->friendTree->addTopLevelItem(item);
        QJsonObject oneFriend = fd.value(x).toObject();
        for (auto y : oneFriend.keys()) {
            QString nickname = oneFriend.value(y).toArray().at(0).toString();
            QString name = oneFriend.value(y).toArray().at(1).toString();
            friends.insert(y, nickname);
            friends.insert(y, name);
            QTreeWidgetItem *item1 = new QTreeWidgetItem(1002);
            item1->setText(0, nickname);
            item->addChild(item1);
        }
    }

    // 初始化群组
    for (auto x: gp.keys()) {
        QString name = gp.value(x).toString();
        groups.insert(x, name);
        ui->groupList->addItem(name);
    }

    // 初始化个人信息

    id = myinfo.value("id").toString();
    name = myinfo.value("name").toString();
    QByteArray img64 = myinfo.value("profileImage").toVariant().toString().toUtf8();
    QByteArray imgReal = QByteArray::fromBase64(img64);
    profile.loadFromData(QByteArray::fromBase64(img64), "PNG");
    signature = myinfo.value("signature").toString();
    ui->name->setText(name);
    ui->signature->setText(signature);
    ui->profilePhoto->setPixmap(profile);
    ui->profilePhoto->setScaledContents(true);

    login->updateDB(id, imgReal); //跟新数据库

    // 打开用户对应的本地数据库
    if (QDir::setCurrent(id)) {
        qDebug() << QDir::currentPath();
        DB.setFile("message.sqlite");
    } else {
        // 当对应账号文件夹不存在时
        QDir dir;
        dir.mkdir(id);
        QDir::setCurrent(id);
        DB.setFile("message.sqlite");
    }
}

void MainWindow::closeEvent(QCloseEvent *event) {
    // 主窗口关闭，所有都关闭
    Q_UNUSED(event);
    com->accept();
}

void MainWindow::clearActiveName()
{
    // 清空维护的表
    activeName.clear();
}

void MainWindow::refreshActiveName(QString nickname)
{
    // 移除维护的表
    activeName.removeOne(nickname);
}



void MainWindow::on_addFriendButton_clicked()
{
    if (!add)
        add = new AddFriendDialog();
    add->show();
}

void MainWindow::message_recieve(char *szbuf, int len)
{
    QByteArray byteArray;
    byteArray = QByteArray(szbuf);
    qDebug() << szbuf;
    QJsonParseError jsonError;
    QJsonDocument doc = QJsonDocument::fromJson(byteArray,&jsonError);
    qDebug() << "message_recieve 处理业务";
//    qDebug() << byteArray;
    QJsonObject object = doc.object();
    QJsonValue type_value;
    type_value = object.value("type");//用type_value暂存返回包消息类型
    switch(type_value.toInt()){
    case PACKET_REG_BACK:
    //说明收到的这个包是注册回馈包
        dealRegisterRs(object);//调用解决返回注册包函数
        break;
    case PACKET_LOG_BACK:
        qDebug() <<"收到登录反馈包";
        //说明收到的这个包是登录反馈包
        dealLoginRs(object);
        break;
    case PACKET_MULTIPULTEXT:
        //说明收到复杂消息包
        deal_MutiChatRs(object);//调用聊天消息处理包函数进行消息包拆解或激发相应槽函数
        break;
    case PACKET_ADD_FRI_RQ:
        //说明收到了别人的加好友请求，调用函数进行处理
        deal_ADD_FRI_RQ(object);
        break;
    case PACKET_ADD_FRI_RQ_BACK:
        //说明收到了好友状态回馈包
        deal_ADD_FRI_RQ_BACK(object);
        break;
    case PACKET_ADD_FRI_RS:
        //说明收到了好友申请是否通过回馈包
        deal_ADD_FRI_RS(object);
        break;

    }

#if 0
    if(!doc.isNull() && (jsonError.error == QJsonParseError::NoError)){
        if(doc.isObject()){//JSON文档内包含对象
            QJsonObject object = doc.object();//object函数返回document中包含的对象
            qDebug() << "222222222";
            if(object.contains("type")){//包含指定的key
                qDebug() << "3333333333";
                qDebug() <<"进入判断json包";
                    QJsonValue type_value;
                    type_value = object.value("type");//用type_value暂存返回包消息类型
                    switch(type_value.toInt()){
                    case PACKET_REG_BACK:
                    //说明收到的这个包是注册回馈包
                        dealRegisterRs(object);//调用解决返回注册包函数
                        break;
                    case PACKET_LOG_BACK:
                        qDebug() <<"收到登录反馈包";
                        //说明收到的这个包是登录反馈包
                        dealLoginRs(object);
                        break;
                    case PACKET_MULTIPULTEXT:
                        //说明收到复杂消息包
                        deal_MutiChatRs(object);//调用聊天消息处理包函数进行消息包拆解或激发相应槽函数
                        break;
                    case PACKET_ADD_FRI_RQ:
                        //说明收到了别人的加好友请求，调用函数进行处理
                        deal_ADD_FRI_RQ(object);
                        break;
                    case PACKET_ADD_FRI_RQ_BACK:
                        //说明收到了好友状态回馈包
                        deal_ADD_FRI_RQ_BACK(object);
                        break;
                    case PACKET_ADD_FRI_RS:
                        //说明收到了好友申请是否通过回馈包
                        deal_ADD_FRI_RS(object);
                        break;

                    }
            }
        }
    }
    else {
        if(doc.isNull())
        {
            qDebug() << "message_recieve doc is null!";
        }
        if(jsonError.error != QJsonParseError::NoError)
        {
            qDebug() << jsonError.error;
        }
    }
#endif
}



//注册请求返回包解析业务(未完成)
void MainWindow::dealRegisterRs(QJsonObject object)
{
    QJsonValue acc_value;
    acc_value = object.value("account");
    qDebug() << "您的帐号是: "<<acc_value.toString();
    QMessageBox::about(this, "提示", "你的账号为"+acc_value.toString());
    login->updateDB(acc_value.toString());
    //emit Successful_Register(acc_value.toString().toLatin1().data());//把帐号用信号发射出去，后面由尘雨写槽函数弹出一个显示帐号的页面
}

//登录请求返回包解析业务(未完成)
void MainWindow::dealLoginRs(QJsonObject object)
{
    qDebug() << "----------------------flag:"<< object.value("flag");
    if(object.value("flag").toInt() == 0){
        //登陆失败
        qDebug() << "账号或密码错误，登陆失败";
        QMessageBox::critical(login, "错误", "账号或密码错误");
        login->updateDB(login->id);
    }
    else {
        //登录成功
        qDebug() << "登陆成功";
        login->accept();
        initUi(object);

    }
}

//解析收到的复杂消息包函数(未完成)
void MainWindow::deal_MutiChatRs(QJsonObject object)
{
    QJsonValue temp_value;

    QJsonValue base64_image;
    QJsonArray array;
    QJsonObject text_obj;
    QString str;


    qDebug() <<"消息来自:" << object.value("from").toString();
    qDebug() <<"消息发往:" << object.value("to").toString();
    if(object.contains("text_order")){
        text_obj = object.value("text_order").toObject();
        array = text_obj.value("order").toArray();
        for(int i =0 ;i <array.size();i++){
            str = array[i].toString()+"i";
            //如果当前顺序是图片
            if(array[i].toString() == "image"){
                //qDebug() << "图片的文件名是:"<< text_obj.value(str).toString();
                qDebug() << "图片消息(base64编码)---"<<object.value("image_base64").toObject().value(str).toString();
                //emit xxxxxxxxxx
                FileHelper helper;
                helper.base64String2File("C:/Users/hjhkk/Desktop/IM_MinGW/image/chat_test1.jpg",object.value("image_base64").toObject().value(str).toString());
                //发射图片二进制文件名字给界面槽函数，界面利用该文件名去取文件并显示


                //把相关的信息放在信号中传出去，传输给尘雨写的槽函数显示
            }
            //如果当前顺序是其他东西
//            if(array[i].toString() == "text"){
//                qDebug() << "文字消息---" << text_obj.value(str).toString();
//                //emit xxxxxxxxxx
//                //把相关的信息放在信号中传出去，传输给尘雨写的槽函数显示
//            }
//            if(array[i].toString() == "app_gif"){
//                qDebug() << "表情消息---" << text_obj.value(str).toString();
//                //emit xxxxxxxxxx
//                //把相关的信息放在信号中传出去，传输给尘雨写的槽函数显示
//            }
        }
        //emit xxxxxxxxxx
        //发射一个消息包拆解结束信号，触发尘雨的显示槽函数
    }
}

void MainWindow::deal_ADD_FRI_RQ(QJsonObject object)
{
    qDebug() << "帐号--->"<<object.value("src_acc").toString()<<"请求添加您为好友";
}

void MainWindow::deal_ADD_FRI_RQ_BACK(QJsonObject object)
{
    qDebug() << "添加 ->"<<object.value("dst_acc").toString()<<"<-  失败[对方离线中]...请在好友上线后重新添加";
}

void MainWindow::deal_ADD_FRI_RS(QJsonObject object)
{

    if(object.value("accept_status").toBool()){
        //说明对方同意了好友请求
        qDebug() << object.value("dst_acc").toString() <<"同意了您的好友请求~";

    }else{
        qDebug() <<"对方拒绝了您的好友申请";
    }
}
