#include "imagehelper.h"
#include <QByteArray>
#include <QBuffer>
#include <QImageReader>
#include <QDebug>

ImageHelper::ImageHelper(QString filePath, QImage image)
    : QThread ()
{
    m_image = image;
    m_filePath = filePath;
    // 此信号可以线程结束后杀死线程，让Qt自己回收资源。qt真的厉害！
    connect(this, SIGNAL(finished()), this, SLOT(deleteLater()));
}


void ImageHelper::run()
{
//    QBuffer buffer(m_data);
//    buffer.open(QBuffer::ReadOnly);
//    QImageReader reader(&buffer);
//    QImage image = reader.read();
//    image.save(m_filePath);
    m_image.save(m_filePath);
    emit imgSaveFinished(m_filePath);
}

