#ifndef LoginDialog_H
#define LoginDialog_H

#include <QDialog>
#include <QSettings>
#include <QCryptographicHash>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>
#include "registerdialog.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pushButton_clicked(); // 登陆按钮
    void on_comboBox_currentIndexChanged(const QString &arg1); // 选择的账号改变后改变密码
    void on_pushButton_2_clicked(); // 注册按钮

    void open_local_DB(); // 打开本地数据库
    void readData(); // 读取数据库数据到界面中
public slots:
    void updateDB(QString); // 更新本地数据库

public:
    void updateDB(QString id, QByteArray profile); // 更新图片

    void updateDB(QString id, QString pwd);// 新的登陆更新数据库
    QString id;

private:
    Ui::LoginDialog *ui; // 界面
    int m_tryCount = 0; // 尝试次数
    QSqlDatabase DB; // 数据库
    QSqlTableModel *tabMode; // 数据表默认
    QMap<qlonglong, QString> localData; // 表中简单的数据


    QString encrypt(const QString &str); // 加密
    void connectSlotsWithSignal();

signals:
    void startRegisterMenu();
    void loginSuccess(QJsonObject);
    void login_request(char* szbuf,int len);
};

#endif // LoginDialog_H
