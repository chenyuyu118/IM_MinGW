#include "addfrienddialog.h"
#include "ui_addfriend.h"

AddFriendDialog::AddFriendDialog(QWidget *parent) : QDialog (parent), ui(new Ui::AddFriendDialog)
{
    ui->setupUi(this);
}

AddFriendDialog::~AddFriendDialog()
{

}
