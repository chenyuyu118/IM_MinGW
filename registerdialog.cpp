#include "registerdialog.h"
#include "ui_register.h"
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QListWidget>
#include <QMessageBox>
#include <QBuffer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include "package.h"


RegisterDialog::RegisterDialog(QWidget *parent) : QDialog(parent),
  ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    initUi(); // 初始化界面
    // 信号和槽连接

}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_submitButton_clicked()
{
    // 本地测试注册信息
    QBuffer buffer(&profile);
    buffer.open(QIODevice::WriteOnly);
    const QPixmap *pix =  ui->label_image->pixmap();
    pix->save(&buffer, "PNG", 20);
    QString profileImage = profile.toBase64();
    name = ui->nameLine->text();
    pwd = ui->pwdLine->text();
    pwd_1 = ui->pwd1Line->text();
    gender = ui->genderLine->currentText();
    birthday = ui->birthdayLine->date().toString("yyyyMMdd").toLongLong();
    // qDebug() << birthday;

    QRegExp rex("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z\\W]{8,18}$"); // 密码8-18正则
    QRegExp rex2("^[\\S]{1,15}$"); // 账户名正则
    // qDebug() << rex.indexIn(pwd);

    if (name.isEmpty() || pwd.isEmpty() || pwd_1.isEmpty()) {
        QMessageBox::critical(this, "错误", "请完善信息");
        // qDebug() << "完善信息";
    } else if (pwd != pwd_1) {
        QMessageBox::critical(this, "错误", "两次输入不一致");
        // qDebug() << "两次密码不一致";
    } else if (rex.indexIn(pwd) == -1){
        QMessageBox::critical(this, "错误", "密码格式错误");
    } else if (rex2.indexIn(name) == -1) {
        QMessageBox::critical(this, "错误", "呢称格式错误");
    } else {

        QString bir;
        bir = QString::number(birthday, 10);

        QJsonObject json;
        json.insert("type",PACKET_REG);
        json.insert("nickname", name);
        json.insert("gender",gender);
        json.insert("password",pwd);
        json.insert("birthday",birthday);
        json.insert("profileImage", profileImage);
        qDebug() << json;
        QJsonDocument document;
        document.setObject(json);
        QByteArray *byteArray = new QByteArray();
        *byteArray = document.toJson(QJsonDocument::Compact);
        char* b_array = byteArray->data();
        emit verifyRegister(b_array,byteArray->length()); // 发送信号，连接服务器请求注册

        refresh();
        this->accept();
    }

}


void RegisterDialog::on_chooseImageButton_clicked()
{
    // 选择本地图片做头像
    QString path = QFileDialog::getOpenFileName(this, "选择头像文件", "", "Image(*.jpg *.png *.jpeg)");
    if (!path.isEmpty())
    {
        QStringList temp = path.split("/");
        QString imgName = temp.value(temp.length()-1);
        if (ui->imagePathBox->findText(imgName) == -1)
        {
            ui->imagePathBox->addItem(imgName, path);
            ui->imagePathBox->setCurrentText(imgName);
        }
    }
}

void RegisterDialog::initUi()
{
    setWindowTitle("注册账号");

    // 通过json初始化选择图片
    QFile file(":/json/profile.json");
    file.open(QIODevice::ReadOnly);
    QJsonParseError error;
    QJsonDocument doc;
    doc = doc.fromJson(file.readAll(), &error);
    QJsonObject imageObj = doc.object();
    for (auto x: imageObj.keys()) {
        ui->imagePathBox->addItem(x, imageObj.value(x));
    }
    QPixmap pix(ui->imagePathBox->currentData().toString());

    // 通过最佳适应显示到label上
    double wFit = pix.width() / ui->label_image->width();
    double hFit = pix.height() / ui->label_image->height();
    if (wFit > hFit)
        pix = pix.scaled(int(pix.width()/wFit), int(pix.height()/wFit));
    else
        pix = pix.scaled(int(pix.width()/hFit), int(pix.height()/hFit));
    ui->label_image->setPixmap(pix);
}

void RegisterDialog::refresh()
{
    ui->pwdLine->clear();
    ui->pwd1Line->clear();
    ui->nameLine->clear();
    ui->birthdayLine->clear();
}

void RegisterDialog::on_imagePathBox_currentIndexChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString path = ui->imagePathBox->currentData().toString();
    QPixmap pix(path);
    double wFit = pix.width() / ui->label_image->width();
    double hFit = pix.height() / ui->label_image->height();
    if (wFit > hFit)
        pix = pix.scaled(int(pix.width()/wFit), int(pix.height()/wFit));
    else
        pix = pix.scaled(int(pix.width()/hFit), int(pix.height()/hFit));
    ui->label_image->setPixmap(pix);
}

void RegisterDialog::on_RegisterDialog_rejected()
{
    refresh();
}
