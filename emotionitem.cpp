#include "emotionitem.h"

#include <QMovie>
#include <QDebug>

/**
 * @brief EmotionItem::EmotionItem
 * @param fileName 动图路径
 * @param emotionMoiveSize 表情大小
 * @param parent
 */
EmotionItem::EmotionItem(QString fileName , QSize emotionMoiveSize, QWidget* parent)
    : QLabel (parent)
{
    // 首先构造函数中进行初始化;
    QMovie* iconMovie = new QMovie;
    iconMovie->setFileName(fileName);
    this->setMovie(iconMovie);
    setContentsMargins(3, 3, 3, 3);
    iconMovie->setScaledSize(QSize(emotionMoiveSize.width(), emotionMoiveSize.height()));
    // 为了动态图片正常显示，（不加上start图片不显示，不加上stop图片一种处于动态效果）
    iconMovie->jumpToFrame(0);
    setStyleSheet("QLabel:hover{border: 1px solid rgb(111, 156, 207);\
                  background: rgba(255, 255, 255, 200);}");
}

EmotionItem::~EmotionItem()
{}

QString EmotionItem::getFilePath()
{
    return this->movie()->fileName();
}

/**
 * @brief 鼠标进入，开始QMovie播放。图片位置上移
 * @param event
 */
void EmotionItem::enterEvent(QEvent *event)
{
    QMovie* movie = this->movie();
    movie->start();
    // 当鼠标悬浮在item上时修改margin值达到表情切换效果，见下图（在鼠标从一个表情滑到另一个表情时)
    setContentsMargins(3, 2, 3, 4);
    return QLabel::enterEvent(event);
}

/**
 * @brief 鼠标离开，停止QMovie播放并跳转到第一帧。图片位置回归正常
 * @param event
 */
void EmotionItem::leaveEvent(QEvent *event)
{
    QMovie* movie = this->movie();
    movie->jumpToFrame(0);
    movie->stop();
    // 恢复原来的margin
    setContentsMargins(3, 3, 3, 3);
    return QLabel::leaveEvent(event);
}

