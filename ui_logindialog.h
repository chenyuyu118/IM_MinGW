/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QLabel *label;
    QLabel *image_label;
    QComboBox *comboBox;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QLabel *label_3;
    QCheckBox *checkBox_2;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QStringLiteral("LoginDialog"));
        LoginDialog->resize(929, 655);
        LoginDialog->setStyleSheet(QLatin1String("background-color:Lightblue;\n"
""));
        label = new QLabel(LoginDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 0, 451, 633));
        label->setStyleSheet(QStringLiteral("border-left-color: rgb(160, 255, 195);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/\350\223\235\350\211\262\347\272\270\351\243\236\346\234\272.png")));
        image_label = new QLabel(LoginDialog);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(590, 70, 150, 150));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(100);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(image_label->sizePolicy().hasHeightForWidth());
        image_label->setSizePolicy(sizePolicy);
        image_label->setMinimumSize(QSize(63, 60));
        image_label->setStyleSheet(QStringLiteral(""));
        image_label->setPixmap(QPixmap(QString::fromUtf8(":/image/375345853.jpg")));
        comboBox = new QComboBox(LoginDialog);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(522, 280, 290, 35));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy1);
        comboBox->setMinimumSize(QSize(290, 35));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border-top-color:lightBlue;\n"
"	border-left-color:lightBlue;\n"
"	border-right-color:lightBlue;\n"
"	border-bottom-color: rgba(89, 130, 204, 248);\n"
"	border-bottom-width: 0px;\n"
"	border-width: 1px;\n"
"	border-style: solid;\n"
"	padding:1px, 5px, 3px, 3px;\n"
"	font: 12pt \"MS UI Gothic\";\n"
"}\n"
"\n"
"QComboBox::down-arrow{\n"
"	image:url(\":/image/\344\270\213\347\256\255\345\244\264.png\");\n"
"}\n"
"\n"
"QComboBox::down-arrow:pressed{\n"
"	color:red;\n"
"	image:url(:/image/\344\270\212\347\256\255\345\244\264.png);\n"
"}\n"
"\n"
""));
        comboBox->setEditable(true);
        lineEdit = new QLineEdit(LoginDialog);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(522, 350, 290, 36));
        sizePolicy1.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy1);
        lineEdit->setMinimumSize(QSize(290, 36));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit\n"
"{padding: 10px, 10px, 10px, 10px;\n"
"	border-color:lightBlue;\n"
"	\n"
"	border-bottom-color: rgb(36, 112, 211);\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"	font: 12pt \"MS UI Gothic\";\n"
"}"));
        lineEdit->setEchoMode(QLineEdit::Password);
        pushButton = new QPushButton(LoginDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(551, 481, 93, 40));
        pushButton->setMinimumSize(QSize(0, 40));
        pushButton->setStyleSheet(QString::fromUtf8("* {\n"
"	background-color: rgb(90, 78, 221);\n"
"	font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"}"));
        pushButton_2 = new QPushButton(LoginDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(700, 481, 93, 40));
        pushButton_2->setMinimumSize(QSize(0, 40));
        pushButton_2->setStyleSheet(QString::fromUtf8("* {\n"
"	background-color: rgb(90, 78, 221);\n"
"	font: 25 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221 Light\";\n"
"}"));
        checkBox = new QCheckBox(LoginDialog);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(491, 421, 99, 28));
        checkBox->setStyleSheet(QString::fromUtf8("*{\n"
"	color:grey;\n"
"	\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        label_3 = new QLabel(LoginDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(786, 421, 72, 24));
        label_3->setStyleSheet(QString::fromUtf8("*{\n"
"	color:grey;\n"
"	\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));
        checkBox_2 = new QCheckBox(LoginDialog);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));
        checkBox_2->setGeometry(QRect(597, 421, 99, 28));
        checkBox_2->setStyleSheet(QString::fromUtf8("*{\n"
"	color:grey;\n"
"	\n"
"	font: 11pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}"));

        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", Q_NULLPTR));
        label->setText(QString());
        image_label->setText(QString());
        pushButton->setText(QApplication::translate("LoginDialog", "\347\231\273\351\231\206", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("LoginDialog", "\346\263\250\345\206\214", Q_NULLPTR));
        checkBox->setText(QApplication::translate("LoginDialog", "\350\207\252\345\212\250\347\231\273\351\231\206", Q_NULLPTR));
        label_3->setText(QApplication::translate("LoginDialog", "\346\211\276\345\233\236\345\257\206\347\240\201", Q_NULLPTR));
        checkBox_2->setText(QApplication::translate("LoginDialog", "\350\256\260\344\275\217\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
