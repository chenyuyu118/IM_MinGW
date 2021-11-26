#ifndef COMMUNICATEDIALOG_H
#define COMMUNICATEDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include "dialog.h"

namespace Ui {
class CommunicateDialog;
}

class CommunicateDialog : public QDialog
{
    Q_OBJECT
public:
    explicit CommunicateDialog(QWidget *parent = nullptr);

signals:
    void clearActive();
    void refreshActive(QString);

private:
    Ui::CommunicateDialog *ui;
public:
    void add(QString name); // 添加一个聊天框
    void add(QString id, QString name);
    void add(QString id, QPixmap profile, QString sendId, QString nickName); // 初始化聊天框一个Tab
    void setActive(QString name); // 激活某个聊天tab
    QString getId();

public slots:
    void on_CommunicateDialog_rejected();
    void on_tabs_tabCloseRequested(int index);
};

#endif // COMMUNICATEDIALOG_H
