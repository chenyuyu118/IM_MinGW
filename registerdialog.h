#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>

namespace Ui{
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT
public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

signals:
    void verifyRegister(char*,int);
    void verifyLocal();
    void acceptRegister(QString);

public slots:

private slots:
    void on_submitButton_clicked();

    void on_chooseImageButton_clicked();

    void on_imagePathBox_currentIndexChanged(const QString &arg1);

    void on_RegisterDialog_rejected();

private:
    Ui::RegisterDialog *ui;
    QString name;
    QString pwd;
    QString pwd_1;
    QString gender;
    qlonglong birthday;
    QByteArray profile;

    QString id; // 注册成功返回账号


    void initUi(); // 初始化界面
    void refresh(); // 完成一次注册后 刷新信息

};

#endif // REGISTERDIALOG_H
