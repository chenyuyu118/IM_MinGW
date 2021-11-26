#include "staticemotionitem.h"
#include <QPixmap>
#include <QToolTip>
#include <QDebug>

Staticemotionitem::Staticemotionitem(QWidget *parent):
    QLabel (parent)
{
    filePath = "";
}

Staticemotionitem::Staticemotionitem(QString fileName, QSize size, QWidget *parent):
    QLabel (parent)
{
    QPixmap *pix = new QPixmap;
    pix->load(fileName);
    filePath = fileName;
    this->setPixmap(pix->scaled(size));
    setStyleSheet("QLabel:hover{border: 1px solid rgb(111, 156, 207);\
                  background: rgba(255, 255, 255, 200);}");
}

Staticemotionitem::~Staticemotionitem()
{

}

QString Staticemotionitem::getFilePath()
{
    return filePath;
}

void Staticemotionitem::enterEvent(QEvent *event)
{
    setContentsMargins(3, 2, 3, 4);
    return QLabel::enterEvent(event);

}

void Staticemotionitem::leaveEvent(QEvent *event)
{
    setContentsMargins(3, 3, 3, 3);
    return QLabel::leaveEvent(event);
}
