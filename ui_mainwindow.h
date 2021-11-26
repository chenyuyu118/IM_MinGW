/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action;
    QAction *actiongroup;
    QAction *actionmyself;
    QAction *actionEmoji;
    QAction *actionCommunication;
    QAction *actionmyInfo;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *profilePhoto;
    QLabel *name;
    QLabel *signature;
    QPushButton *addFriendButton;
    QTabWidget *tabWidget;
    QWidget *messageTab;
    QHBoxLayout *horizontalLayout;
    QListView *messageList;
    QWidget *friendTab;
    QHBoxLayout *horizontalLayout_2;
    QTreeWidget *friendTree;
    QWidget *groupTab;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *groupList;
    QPushButton *settingButton;
    QComboBox *searchBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(488, 875);
        MainWindow->setStyleSheet(QStringLiteral("background-color:white;"));
        MainWindow->setAnimated(false);
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        MainWindow->setDockNestingEnabled(false);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::ForceTabbedDocks|QMainWindow::GroupedDragging|QMainWindow::VerticalTabs);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        action = new QAction(MainWindow);
        action->setObjectName(QStringLiteral("action"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/\350\256\276\347\275\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        action->setIcon(icon);
        action->setMenuRole(QAction::ApplicationSpecificRole);
        action->setPriority(QAction::NormalPriority);
        actiongroup = new QAction(MainWindow);
        actiongroup->setObjectName(QStringLiteral("actiongroup"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/\350\264\246\345\217\267.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiongroup->setIcon(icon1);
        actionmyself = new QAction(MainWindow);
        actionmyself->setObjectName(QStringLiteral("actionmyself"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/\344\270\252\344\272\272\344\270\255\345\277\203.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionmyself->setIcon(icon2);
        actionEmoji = new QAction(MainWindow);
        actionEmoji->setObjectName(QStringLiteral("actionEmoji"));
        actionEmoji->setIcon(icon2);
        actionCommunication = new QAction(MainWindow);
        actionCommunication->setObjectName(QStringLiteral("actionCommunication"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/\350\257\204\350\256\272.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommunication->setIcon(icon3);
        actionmyInfo = new QAction(MainWindow);
        actionmyInfo->setObjectName(QStringLiteral("actionmyInfo"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/375345853.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        actionmyInfo->setIcon(icon4);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        profilePhoto = new QLabel(centralWidget);
        profilePhoto->setObjectName(QStringLiteral("profilePhoto"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(profilePhoto->sizePolicy().hasHeightForWidth());
        profilePhoto->setSizePolicy(sizePolicy);
        profilePhoto->setMinimumSize(QSize(111, 64));
        profilePhoto->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(profilePhoto, 0, 0, 2, 1);

        name = new QLabel(centralWidget);
        name->setObjectName(QStringLiteral("name"));

        gridLayout->addWidget(name, 0, 1, 1, 1);

        signature = new QLabel(centralWidget);
        signature->setObjectName(QStringLiteral("signature"));

        gridLayout->addWidget(signature, 1, 1, 1, 2);

        addFriendButton = new QPushButton(centralWidget);
        addFriendButton->setObjectName(QStringLiteral("addFriendButton"));
        sizePolicy.setHeightForWidth(addFriendButton->sizePolicy().hasHeightForWidth());
        addFriendButton->setSizePolicy(sizePolicy);
        addFriendButton->setMinimumSize(QSize(60, 0));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/image/\345\205\263\346\263\250.png"), QSize(), QIcon::Normal, QIcon::Off);
        addFriendButton->setIcon(icon5);

        gridLayout->addWidget(addFriendButton, 2, 2, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        messageTab = new QWidget();
        messageTab->setObjectName(QStringLiteral("messageTab"));
        horizontalLayout = new QHBoxLayout(messageTab);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        messageList = new QListView(messageTab);
        messageList->setObjectName(QStringLiteral("messageList"));

        horizontalLayout->addWidget(messageList);

        tabWidget->addTab(messageTab, QString());
        tabWidget->setTabText(tabWidget->indexOf(messageTab), QString::fromUtf8(" \346\266\210\346\201\257"));
        friendTab = new QWidget();
        friendTab->setObjectName(QStringLiteral("friendTab"));
        horizontalLayout_2 = new QHBoxLayout(friendTab);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        friendTree = new QTreeWidget(friendTab);
        friendTree->setObjectName(QStringLiteral("friendTree"));

        horizontalLayout_2->addWidget(friendTree);

        tabWidget->addTab(friendTab, QString());
        groupTab = new QWidget();
        groupTab->setObjectName(QStringLiteral("groupTab"));
        horizontalLayout_3 = new QHBoxLayout(groupTab);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupList = new QListWidget(groupTab);
        groupList->setObjectName(QStringLiteral("groupList"));

        horizontalLayout_3->addWidget(groupList);

        tabWidget->addTab(groupTab, QString());

        gridLayout->addWidget(tabWidget, 3, 0, 1, 3);

        settingButton = new QPushButton(centralWidget);
        settingButton->setObjectName(QStringLiteral("settingButton"));
        sizePolicy.setHeightForWidth(settingButton->sizePolicy().hasHeightForWidth());
        settingButton->setSizePolicy(sizePolicy);
        settingButton->setIcon(icon);

        gridLayout->addWidget(settingButton, 4, 0, 1, 1);

        searchBox = new QComboBox(centralWidget);
        searchBox->setObjectName(QStringLiteral("searchBox"));
        searchBox->setMinimumSize(QSize(0, 34));

        gridLayout->addWidget(searchBox, 2, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        action->setText(QApplication::translate("MainWindow", "Settings", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action->setToolTip(QApplication::translate("MainWindow", "\350\256\276\347\275\256", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actiongroup->setText(QApplication::translate("MainWindow", "group", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actiongroup->setToolTip(QApplication::translate("MainWindow", "\347\276\244\347\273\204", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionmyself->setText(QApplication::translate("MainWindow", "myself", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionmyself->setToolTip(QApplication::translate("MainWindow", "\344\270\252\344\272\272\344\270\255\345\277\203", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionEmoji->setText(QApplication::translate("MainWindow", "\350\241\250\346\203\205", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionEmoji->setToolTip(QApplication::translate("MainWindow", "\345\217\221\351\200\201\350\241\250\346\203\205", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionCommunication->setText(QApplication::translate("MainWindow", "\350\201\212\345\244\251", Q_NULLPTR));
        actionmyInfo->setText(QApplication::translate("MainWindow", "myInfo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionmyInfo->setToolTip(QApplication::translate("MainWindow", "\346\210\221\347\232\204\350\265\204\346\226\231", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        profilePhoto->setText(QString());
        name->setText(QApplication::translate("MainWindow", "name", Q_NULLPTR));
        signature->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        addFriendButton->setText(QString());
        QTreeWidgetItem *___qtreewidgetitem = friendTree->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("MainWindow", "\345\245\275\345\217\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(friendTab), QApplication::translate("MainWindow", " \345\245\275\345\217\213", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(groupTab), QApplication::translate("MainWindow", "\347\276\244\347\273\204", Q_NULLPTR));
        settingButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
