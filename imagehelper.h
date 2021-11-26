#ifndef IMAGEHELPER_H
#define IMAGEHELPER_H

#include <QThread>
#include <QString>
#include <QImage>

/**
 * @brief The ImageHelper class
 * 开辟子线程保存图像（实际没必要这么做，可以直接用lambda表达式完成的）
 */
class ImageHelper : public QThread
{
    Q_OBJECT
public:
    ImageHelper(QString filePath, QImage image);

protected:
    QString m_filePath;
    QByteArray* m_data;
    QImage m_image;
    void run();

signals:
    void imgSaveFinished(QString path);
};

#endif // IMAGEHELPER_H
