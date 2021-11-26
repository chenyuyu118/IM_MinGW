/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QLabel *label_image;
    QLabel *label_6;
    QPushButton *chooseImageButton;
    QLabel *label;
    QLineEdit *nameLine;
    QLabel *label_2;
    QLineEdit *pwdLine;
    QLabel *label_3;
    QLineEdit *pwd1Line;
    QLabel *label_4;
    QComboBox *genderLine;
    QDateEdit *birthdayLine;
    QLabel *label_5;
    QComboBox *imagePathBox;
    QPushButton *submitButton;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName(QStringLiteral("RegisterDialog"));
        RegisterDialog->resize(488, 456);
        label_image = new QLabel(RegisterDialog);
        label_image->setObjectName(QStringLiteral("label_image"));
        label_image->setGeometry(QRect(90, 30, 86, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_image->sizePolicy().hasHeightForWidth());
        label_image->setSizePolicy(sizePolicy);
        label_image->setMinimumSize(QSize(86, 71));
        label_image->setMaximumSize(QSize(0, 16777215));
        label_6 = new QLabel(RegisterDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(49, 64, 24, 16));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);
        chooseImageButton = new QPushButton(RegisterDialog);
        chooseImageButton->setObjectName(QStringLiteral("chooseImageButton"));
        chooseImageButton->setGeometry(QRect(410, 50, 36, 32));
        sizePolicy.setHeightForWidth(chooseImageButton->sizePolicy().hasHeightForWidth());
        chooseImageButton->setSizePolicy(sizePolicy);
        chooseImageButton->setMinimumSize(QSize(6, 0));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/\345\233\276\347\211\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        chooseImageButton->setIcon(icon);
        chooseImageButton->setIconSize(QSize(24, 24));
        label = new QLabel(RegisterDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(49, 138, 24, 16));
        nameLine = new QLineEdit(RegisterDialog);
        nameLine->setObjectName(QStringLiteral("nameLine"));
        nameLine->setGeometry(QRect(142, 138, 300, 20));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(nameLine->sizePolicy().hasHeightForWidth());
        nameLine->setSizePolicy(sizePolicy2);
        nameLine->setMinimumSize(QSize(300, 0));
        nameLine->setEchoMode(QLineEdit::Normal);
        label_2 = new QLabel(RegisterDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(49, 190, 24, 16));
        pwdLine = new QLineEdit(RegisterDialog);
        pwdLine->setObjectName(QStringLiteral("pwdLine"));
        pwdLine->setGeometry(QRect(142, 190, 300, 20));
        sizePolicy.setHeightForWidth(pwdLine->sizePolicy().hasHeightForWidth());
        pwdLine->setSizePolicy(sizePolicy);
        pwdLine->setMinimumSize(QSize(300, 0));
        pwdLine->setEchoMode(QLineEdit::Password);
        label_3 = new QLabel(RegisterDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(49, 242, 48, 16));
        pwd1Line = new QLineEdit(RegisterDialog);
        pwd1Line->setObjectName(QStringLiteral("pwd1Line"));
        pwd1Line->setGeometry(QRect(142, 242, 300, 20));
        sizePolicy.setHeightForWidth(pwd1Line->sizePolicy().hasHeightForWidth());
        pwd1Line->setSizePolicy(sizePolicy);
        pwd1Line->setMinimumSize(QSize(300, 0));
        pwd1Line->setEchoMode(QLineEdit::Password);
        label_4 = new QLabel(RegisterDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(49, 294, 24, 16));
        genderLine = new QComboBox(RegisterDialog);
        genderLine->setObjectName(QStringLiteral("genderLine"));
        genderLine->setGeometry(QRect(142, 294, 50, 20));
        sizePolicy.setHeightForWidth(genderLine->sizePolicy().hasHeightForWidth());
        genderLine->setSizePolicy(sizePolicy);
        genderLine->setMinimumSize(QSize(50, 0));
        birthdayLine = new QDateEdit(RegisterDialog);
        birthdayLine->setObjectName(QStringLiteral("birthdayLine"));
        birthdayLine->setGeometry(QRect(142, 346, 88, 20));
        sizePolicy.setHeightForWidth(birthdayLine->sizePolicy().hasHeightForWidth());
        birthdayLine->setSizePolicy(sizePolicy);
        label_5 = new QLabel(RegisterDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(49, 346, 24, 16));
        imagePathBox = new QComboBox(RegisterDialog);
        imagePathBox->setObjectName(QStringLiteral("imagePathBox"));
        imagePathBox->setGeometry(QRect(200, 60, 200, 20));
        sizePolicy.setHeightForWidth(imagePathBox->sizePolicy().hasHeightForWidth());
        imagePathBox->setSizePolicy(sizePolicy);
        imagePathBox->setMinimumSize(QSize(200, 0));
        submitButton = new QPushButton(RegisterDialog);
        submitButton->setObjectName(QStringLiteral("submitButton"));
        submitButton->setGeometry(QRect(240, 400, 75, 23));
        sizePolicy.setHeightForWidth(submitButton->sizePolicy().hasHeightForWidth());
        submitButton->setSizePolicy(sizePolicy);

        retranslateUi(RegisterDialog);

        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QApplication::translate("RegisterDialog", "Dialog", Q_NULLPTR));
        label_image->setText(QApplication::translate("RegisterDialog", "11111111", Q_NULLPTR));
        label_6->setText(QApplication::translate("RegisterDialog", "\345\244\264\345\203\217", Q_NULLPTR));
        chooseImageButton->setText(QString());
        label->setText(QApplication::translate("RegisterDialog", "\345\221\242\347\247\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("RegisterDialog", "\345\257\206\347\240\201", Q_NULLPTR));
        label_3->setText(QApplication::translate("RegisterDialog", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        label_4->setText(QApplication::translate("RegisterDialog", "\346\200\247\345\210\253", Q_NULLPTR));
        genderLine->clear();
        genderLine->insertItems(0, QStringList()
         << QApplication::translate("RegisterDialog", "\347\224\267", Q_NULLPTR)
         << QApplication::translate("RegisterDialog", "\345\245\263", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("RegisterDialog", "\347\224\237\346\227\245", Q_NULLPTR));
        submitButton->setText(QApplication::translate("RegisterDialog", "\346\217\220\344\272\244", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        submitButton->setShortcut(QApplication::translate("RegisterDialog", "Return", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
