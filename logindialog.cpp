#include "logindialog.h"
#include "ui_logindialog.h"
#include <QJsonArray>
#include "package.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    open_local_DB(); // 打开本地
    setWindowTitle("登陆界面");
   // setWindowFlags(Qt::SplashScreen); // SplashScreen无边框
   // setWindowFlags(Qt::FramelessWindowHint); // 无边框
    this->setAttribute(Qt::WA_DeleteOnClose);
    connectSlotsWithSignal();
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButton_clicked()
{
    // 登陆按钮被按下
    QString user = ui->comboBox->currentText(); // 用户名
    id = user;
    QString password = ui->lineEdit->text(); // 密码
    // QString encrptPSWD = encrypt(password); // 加密
    QRegExp rex("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z\\W]{8,18}$"); // 密码8-18正则
    QRegExp rex1("^[0-9]{8}$"); // 账号正则

    // 正则效验
//    if (rex1.indexIn(user) == -1)
//    {
//        QMessageBox::critical(this, "错误", "账号格式错误");
//        return;
//    } else if(rex.indexIn(password)) {
//        QMessageBox::critical(this, "错误", "密码格式错误");
//        return;
//    }else{
        QJsonObject json;
                json.insert("type",PACKET_LOG);
                json.insert("account",user);
                json.insert("password",password);

                QJsonDocument document;
                document.setObject(json);
                QByteArray byteArray = document.toJson(QJsonDocument::Compact);
                char* b_array = byteArray.data();
                updateDB(user, password);
                emit login_request(b_array,byteArray.length());//发射登录信号 用来绑定发射登录包
//    }
}

void LoginDialog::open_local_DB()
{
    // 打开本地数据库
    DB = DB.addDatabase("QSQLITE", "login");
    DB = DB.database("login");
    DB.setDatabaseName("..\\localdb\\identifier.sqlite");
    if (DB.open())
    {
        qDebug() << "打开";
        readData();

    } else {
        qDebug() << "打不开";
    }
}

void LoginDialog::readData()
{
    // 读取数据 加载到界面上
    tabMode = new QSqlTableModel(this, DB);
    tabMode->setTable("login");
    tabMode->setSort(0, Qt::AscendingOrder);
    tabMode->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord recd;
    qlonglong user;
    QString pwd;
    QByteArray profile;
    if (tabMode->select()) {
        int count = tabMode->rowCount();
        for (int i = 0; i < count; i++) {
            recd = tabMode->record(i);
            user = recd.value(0).toLongLong();
            pwd = recd.value(1).toString();
            profile = recd.value(2).toByteArray();
            ui->comboBox->addItem(QString::number(user), profile);
            localData.insert(user, pwd);
            if (i == 0) {
                // 显示第一个数据
                if (!pwd.isEmpty())
                {
                    ui->lineEdit->setText(pwd);
                    ui->checkBox_2->setCheckState(Qt::Checked);
                } else {
                    ui->checkBox_2->setCheckState(Qt::Unchecked);
                }
                QPixmap pix;
                pix.loadFromData(profile);
                ui->image_label->setPixmap(pix);
                ui->image_label->setScaledContents(true);
                ui->image_label->setStyleSheet("QLabel{border:5px solid white;}");
            }
          }
    } else {
        qDebug() << "2222";
    }
}

QString LoginDialog::encrypt(const QString &str)
{
    // 加密密码函数
    QByteArray btArray;
    btArray.append(str);
    QCryptographicHash hash(QCryptographicHash::Md5);
    hash.addData(btArray);
    QByteArray result = hash.result();
    QString md5 = result.toHex();
    return md5;
}

void LoginDialog::connectSlotsWithSignal()
{
    // 连接需要的信号和槽

}

void LoginDialog::on_comboBox_currentIndexChanged(const QString &arg1)
{
    // 更换了账号
    Q_UNUSED(arg1);
    qlonglong str = ui->comboBox->currentText().toLongLong();
    QString pwd = localData.value(str);
    if (pwd.isEmpty() || pwd.isNull()) {
        ui->checkBox_2->setCheckState(Qt::Unchecked);
        ui->lineEdit->clear();
    } else {
        ui->checkBox_2->setCheckState(Qt::Checked);
        ui->lineEdit->setText(pwd);
    }
    QPixmap pix;
    pix.loadFromData(ui->comboBox->currentData().toByteArray());
    ui->image_label->setPixmap(pix);
}

void LoginDialog::on_pushButton_2_clicked()
{
    // 注册按钮
    emit startRegisterMenu();
}

void LoginDialog::updateDB(QString id)
{
    // 新的注册id添加到数据库
    ui->comboBox->addItem(id);
    bool flag = true;
    for (int i = 0; i < tabMode->rowCount(); i++) {
        QSqlRecord recd = tabMode->record(i);
        if (recd.value(0).toString() == id) {
            recd.setNull(1);
            tabMode->setRecord(i, recd);

            tabMode->submitAll();
            flag = false;
            break;
        }
    }
    if (flag) {
        QSqlRecord recd = tabMode->record();
        recd.setValue(0, id);
        tabMode->setRecord(tabMode->rowCount(), recd);
        tabMode->submitAll();
    }
}

void LoginDialog::updateDB(QString id, QString pwd)
{
    // 一次登陆成功后更新数据库
    if (localData.keys().indexOf(id.toLongLong()) == -1)
    {
        // 这是个本机新用户
        QSqlRecord record = tabMode->record();
        record.setValue(0, id);
        if (ui->checkBox_2->checkState() == Qt::Checked)
            record.setValue(1, pwd);
        tabMode->insertRecord(1, record);
        tabMode->submitAll();
    } else {
        for (int i = 0; i < tabMode->rowCount(); i++) {
            QSqlRecord recd = tabMode->record(i);
            if (recd.value(0).toString() == id) {
                if (ui->checkBox_2->checkState() == Qt::Checked)
                    recd.setValue(1, pwd);
                else {
                    recd.setNull(1);
                }
                tabMode->setRecord(i, recd);
                tabMode->submitAll();
                break;
            }
        }
    }
    tabMode->setTable("login");
    tabMode->select();
}

void LoginDialog::updateDB(QString id, QByteArray profile)
{
    // 更新图片
    qDebug() << "by Imgae";
    for (int i = 0; i < tabMode->rowCount(); i++) {
        QSqlRecord recd = tabMode->record(i);
        if (recd.value(0).toString() == id) {
            recd.setValue(2, profile);
            tabMode->setRecord(i, recd);
            tabMode->submitAll();
            break;
        }
    }
}





