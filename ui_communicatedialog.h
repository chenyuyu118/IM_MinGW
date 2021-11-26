/********************************************************************************
** Form generated from reading UI file 'communicatedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMUNICATEDIALOG_H
#define UI_COMMUNICATEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>

QT_BEGIN_NAMESPACE

class Ui_CommunicateDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabs;

    void setupUi(QDialog *CommunicateDialog)
    {
        if (CommunicateDialog->objectName().isEmpty())
            CommunicateDialog->setObjectName(QStringLiteral("CommunicateDialog"));
        CommunicateDialog->resize(830, 734);
        horizontalLayout = new QHBoxLayout(CommunicateDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabs = new QTabWidget(CommunicateDialog);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setElideMode(Qt::ElideNone);
        tabs->setDocumentMode(false);
        tabs->setTabsClosable(true);
        tabs->setMovable(true);
        tabs->setTabBarAutoHide(false);

        horizontalLayout->addWidget(tabs);


        retranslateUi(CommunicateDialog);

        tabs->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(CommunicateDialog);
    } // setupUi

    void retranslateUi(QDialog *CommunicateDialog)
    {
        CommunicateDialog->setWindowTitle(QApplication::translate("CommunicateDialog", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommunicateDialog: public Ui_CommunicateDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMUNICATEDIALOG_H
