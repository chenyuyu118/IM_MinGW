#include "communicatedialog.h"
#include "ui_communicatedialog.h"


CommunicateDialog::CommunicateDialog(QWidget *parent) : QDialog (parent),
    ui(new Ui::CommunicateDialog)
{
    ui->setupUi(this);

}

void CommunicateDialog::add(QString name)
{
    // 添加一个聊天框
    bool flag = true;
    for (int i = 0; i < ui->tabs->count(); ++i) {
        if (ui->tabs->tabText(i) == name) {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        Dialog *d = new Dialog();
        QWidget *wd = qobject_cast<QWidget *>(d);
        ui->tabs->addTab(wd, name);
    }
}

void CommunicateDialog::add(QString id, QString name)
{
    Dialog *d = new Dialog(id);
    QWidget *wd = qobject_cast<QWidget *>(d);
    ui->tabs->addTab(wd, name);
    ui->tabs->setCurrentWidget(wd);
}

void CommunicateDialog::add(QString id, QPixmap profile, QString sendId, QString nickName)
{
    Dialog *d = new Dialog(id, profile, sendId, nickName);
    QWidget *wd = qobject_cast<QWidget *>(d);
    ui->tabs->addTab(wd, nickName);
    ui->tabs->setCurrentWidget(wd);
}

void CommunicateDialog::setActive(QString name)
{
    // 指定激活某个窗口
    for (int i = 0; i < ui->tabs->tabBar()->count(); i++) {
        if (ui->tabs->tabBar()->tabText(i) == name) {
            ui->tabs->setCurrentIndex(i);
            break;
        }
    }
}

QString CommunicateDialog::getId()
{
    // 获得某个窗口的id
    QWidget *w =  ui->tabs->currentWidget();
    Dialog *d = dynamic_cast<Dialog *>(w);
    return d->getId();
}

void CommunicateDialog::on_CommunicateDialog_rejected()
{
    // qDebug() << "窗口关闭1";
    this->ui->tabs->clear();
    emit clearActive();
}

void CommunicateDialog::on_tabs_tabCloseRequested(int index)
{
    // qDebug() << "close";
    QString nickname = ui->tabs->tabBar()->tabText(index);
    if (ui->tabs->tabBar()->count() != 1) {
        // 关闭一个页面
        qDebug() << ui->tabs->tabBar()->count();
        ui->tabs->tabBar()->removeTab(index);
        emit refreshActive(nickname);
    } else {
        // 最后一个页面关闭所有页面都关闭
        this->reject();
    }
}
