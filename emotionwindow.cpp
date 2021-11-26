#include "emotionwindow.h"
#include "emotionwidget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonParseError>
#include <QJsonObject>
#include <QDir>
#include <QJsonArray>
#include <QApplication>


EmotionWindow::EmotionWindow(QWidget *parent)
    : QTabWidget(parent)
{
    QTabWidget::setTabPosition(QTabWidget::South); // 选项卡在下面（默认为上面）
//    initEmotionWidget();
    initUi();
    connect(this, SIGNAL(currentChanged(int)), this, SLOT(resizeTabWindow(int)));
}

EmotionWindow::~EmotionWindow()
{

}


void EmotionWindow::initEmotionWidget()
{
//    // 设置选卡布局第一项页面的容器
//    m_pQFaceWidget = new QWidget(this);
//    QLabel* title = new QLabel("经典表情", m_pQFaceWidget);
//    QVBoxLayout* VBoxLayout = new QVBoxLayout();
//    m_pQFaceWidget->setLayout(VBoxLayout);

//    // 设置第一项页面里表情部件
//        // 基本信息设置。这里可以调节表情部件中每个表情的大小
//    this->m_pQFace = new EmotionWidget(m_pQFaceWidget);
//    connect(m_pQFace, &EmotionWidget::emotionClicked, [=](QString path){
//        emit emotionClicked(path);
//        this->hide();
//    });

//    this->m_pQFace->setRowAndColumn(12, 12);
//    this->m_pQFace->setEmotionSize(QSize(40, 40));
//    this->m_pQFace->setEmotionMovieSize(QSize(65, 65));
//    this->m_pQFace->initTableWidget();

//        // 载入表情到表情部件
//    QFileInfo file;
//    QString path;
//    for(int i = 1; i < 142; i++){
//        path = QString(":/resource/emojis/qq/%1@2x.gif").arg(i);
//        // 检测表情是否存在再载入
//        file.setFile(path);
//        if(file.exists()){
//            m_pQFace->addEmotionItem(path);
//        }
//    }

//    VBoxLayout->setSpacing(10);
//    VBoxLayout->setContentsMargins(0, 10, 0, 0);
//    VBoxLayout->addWidget(title);
//    VBoxLayout->addWidget(m_pQFace);
//    this->addTab(m_pQFaceWidget, QIcon(":/resource/icon/QFace_icon.png"), "经典表情");

    //使用json添加表情,新增


//    QFile jsFile("../json//vx.json");
//    jsFile.open(QIODevice::ReadOnly);
//    QJsonDocument doc;
//    QJsonParseError err;
//    doc = doc.fromJson(jsFile.readAll(), &err);

//        qDebug() << err.error;
//        QJsonObject obj;
//        obj = doc.object();
//        faceWidget = new QWidget(this);
//        QLabel *label = new QLabel(obj.value("label").toString(), faceWidget);
//        QVBoxLayout* VBoxLayout1 = new QVBoxLayout();
//        faceWidget->setLayout(VBoxLayout1);
//        emotion2 = new EmotionWidget();
////        QTableWidget *emotion2 = new QTableWidget;
//        QJsonArray tempArr = obj.value("row-column").toArray();
////        emotion2->setRowCount(tempArr.at(0).toInt());
////        emotion2->setColumnCount(tempArr.at(1).toInt());
//         emotion2->setRowAndColumn(tempArr.at(0).toInt(), tempArr.at(1).toInt());
//        tempArr = obj.value("size").toArray();
//        emotion2->setEmotionSize(QSize(tempArr.at(0).toInt(), tempArr.at(1).toInt()));
//        tempArr = obj.value("movie-size").toArray();
//        emotion2->setEmotionMovieSize(QSize(tempArr.at(0).toInt(), tempArr.at(1).toInt()));

//        emotion2->initTableWidget();
//        obj = obj.value("image").toObject();
//        //emotion2->addEmotionItem(":/resource/emojis/qq/0@2x.gif");
//        for (auto x:obj.keys()) {
//            QFile tempFile(x);
//            if (tempFile.exists()) {
//                 emotion2->addEmotionItem(x);
//            }
//        }

//        VBoxLayout1->setSpacing(10);
//        VBoxLayout1->setContentsMargins(0, 10, 0, 0);
//        VBoxLayout1->addWidget(label);
//        VBoxLayout1->addWidget(emotion2);
//        this->addTab(faceWidget, QIcon(":/emoji/vx/Addoil.png"), label->text());


//    connect(emotion2, &EmotionWidget::emotionClicked, [=](QString path){
//        emit emotionClicked(path);
//        this->hide();
//    });
//    // 为了测试，加了一句适应界面大小

//    this->setFixedSize(emotion2->size());


}

void EmotionWindow::initUi()
{
    // 初始化表情界面

    // 加载json配置文件

    QFile jsFile(":/json/vx.json");
    jsFile.open(QIODevice::ReadOnly);
    QJsonDocument doc;
    QJsonParseError err;
    doc = doc.fromJson(jsFile.readAll(), &err);

    qDebug() << err.error;
    QJsonArray array = doc.array();
    for (int i = 0; i < array.count(); ++i) {
        QJsonObject obj = array.at(i).toObject();
        QWidget* faceWidget = new QWidget(this);
        QLabel *label = new QLabel(obj.value("label").toString(), faceWidget);
        QVBoxLayout* VBoxLayout1 = new QVBoxLayout();
        faceWidget->setLayout(VBoxLayout1);
        EmotionWidget* emotion2 = new EmotionWidget();

        QJsonArray tempArr = obj.value("row-column").toArray();
         emotion2->setRowAndColumn(tempArr.at(0).toInt(), tempArr.at(1).toInt());
        tempArr = obj.value("size").toArray();
        emotion2->setEmotionSize(QSize(tempArr.at(0).toInt(), tempArr.at(1).toInt()));
        tempArr = obj.value("movie-size").toArray();
        emotion2->setEmotionMovieSize(QSize(tempArr.at(0).toInt(), tempArr.at(1).toInt()));

        emotion2->initTableWidget();
        obj = obj.value("image").toObject();
        //emotion2->addEmotionItem(":/resource/emojis/qq/0@2x.gif");
        for (auto x:obj.keys()) {
            QFile tempFile(x);
            if (tempFile.exists()) {
                 emotion2->addEmotionItem(x, obj.value(x).toString());
            }
        }

        VBoxLayout1->setSpacing(10);
        VBoxLayout1->setContentsMargins(0, 10, 0, 0);
        VBoxLayout1->addWidget(label);
        VBoxLayout1->addWidget(emotion2);

        this->addTab(faceWidget, QIcon(":/emoji/vx/Addoil.png"), label->text());


        connect(emotion2, &EmotionWidget::emotionClicked, [=](QString path, bool isStatic){
            emit emotionClicked(path, isStatic);
            this->hide();
        });
        this->setFixedSize(emotion2->size());
    }
}

void EmotionWindow::resizeTabWindow(int index)
{
     // this->setFixedSize(this->tabBar()->size());
}
