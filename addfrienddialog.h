#ifndef ADDFRIENDDIALOG_H
#define ADDFRIENDDIALOG_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class AddFriendDialog;
}

class AddFriendDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AddFriendDialog(QWidget *parent = nullptr);
    ~AddFriendDialog();
private:
    Ui::AddFriendDialog *ui;

signals:

public slots:
};

#endif // ADDFRIENDDIALOG_H
