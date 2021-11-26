/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include "cbasechatedit.h"

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QToolButton *emojiButton;
    QToolButton *pictureButton;
    QToolButton *voiceButton;
    CBaseChatEdit *textEdit;
    QToolButton *submit;
    QListView *listView;

    void setupUi(QWidget *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(421, 475);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        emojiButton = new QToolButton(Dialog);
        emojiButton->setObjectName(QStringLiteral("emojiButton"));
        sizePolicy.setHeightForWidth(emojiButton->sizePolicy().hasHeightForWidth());
        emojiButton->setSizePolicy(sizePolicy);
        emojiButton->setMinimumSize(QSize(45, 30));
        emojiButton->setStyleSheet(QLatin1String("\n"
"QToolButton{\n"
"background-color:white;\n"
"border-color:white;\n"
"border-width:0px;\n"
"padding:0 0 0 0;\n"
"border:solid;\n"
"}\n"
"\n"
"QToolButton:pressed { \n"
"	background-color:green;\n"
"}"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/\344\270\252\344\272\272\344\270\255\345\277\203.png"), QSize(), QIcon::Normal, QIcon::Off);
        emojiButton->setIcon(icon);
        emojiButton->setIconSize(QSize(45, 30));

        gridLayout->addWidget(emojiButton, 1, 0, 1, 1);

        pictureButton = new QToolButton(Dialog);
        pictureButton->setObjectName(QStringLiteral("pictureButton"));
        sizePolicy.setHeightForWidth(pictureButton->sizePolicy().hasHeightForWidth());
        pictureButton->setSizePolicy(sizePolicy);
        pictureButton->setMinimumSize(QSize(45, 30));
        pictureButton->setStyleSheet(QLatin1String("\n"
"QToolButton{\n"
"background-color:white;\n"
"border-color:white;\n"
"border-width:0px;\n"
"padding:0 0 0 0;\n"
"border:solid;\n"
"}\n"
"\n"
"QToolButton:pressed { \n"
"	background-color:green;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/\345\233\276\347\211\207.png"), QSize(), QIcon::Normal, QIcon::Off);
        pictureButton->setIcon(icon1);
        pictureButton->setIconSize(QSize(45, 30));

        gridLayout->addWidget(pictureButton, 1, 1, 1, 1);

        voiceButton = new QToolButton(Dialog);
        voiceButton->setObjectName(QStringLiteral("voiceButton"));
        voiceButton->setMinimumSize(QSize(45, 30));
        voiceButton->setStyleSheet(QLatin1String("\n"
"QToolButton{\n"
"background-color:white;\n"
"border-color:white;\n"
"border-width:0px;\n"
"padding:0 0 0 0;\n"
"border:solid;\n"
"}\n"
"\n"
"QToolButton:pressed { \n"
"	background-color:green;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/\350\257\255\351\237\263.png"), QSize(), QIcon::Normal, QIcon::Off);
        voiceButton->setIcon(icon2);
        voiceButton->setIconSize(QSize(45, 30));

        gridLayout->addWidget(voiceButton, 1, 2, 1, 1);

        textEdit = new CBaseChatEdit(Dialog);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);

        submit = new QToolButton(Dialog);
        submit->setObjectName(QStringLiteral("submit"));
        submit->setMinimumSize(QSize(80, 0));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/\345\217\221\351\200\201.png"), QSize(), QIcon::Normal, QIcon::Off);
        submit->setIcon(icon3);

        gridLayout->addWidget(submit, 3, 3, 1, 1);

        listView = new QListView(Dialog);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 0, 0, 1, 4);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QWidget *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Form", Q_NULLPTR));
        emojiButton->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
        pictureButton->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
        voiceButton->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
        submit->setText(QApplication::translate("Dialog", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
