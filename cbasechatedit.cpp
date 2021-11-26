#include "cbasechatedit.h"
#include "imagehelper.h"
#include "hashcode.h"
#include "appimagetypehelper.h"
#include "textqjsonhelper.h"

#include <QFileInfo>
#include <QMimeData>
#include <QImageReader>
#include <QMovie>
#include <QMimeDatabase>
#include <QPixmap>
#include <QUrl>
#include <QFrame>
#include <QTextBlock>
#include <QDebug>
#include <QTextDocument>


CBaseChatEdit::CBaseChatEdit(QWidget *parent)
    : QTextEdit (parent)
{
    // this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 取消横向滚动条
}

CBaseChatEdit::~CBaseChatEdit()
{}

/**
 * @brief 设置字体。本来可以用QTextEdit::setFontFamily的，但是它莫名其妙失效了，只能自己再封装了
 * @param fontFamily 字体的名字，如果字体有中文名好像也支持（宋体、微软雅黑......）
 */
void CBaseChatEdit::setFontFamily(const QString &fontFamily)
{
    QFont font = this->font();
    font.setFamily(fontFamily);
    this->setFont(font);
}


/**
 * @brief = 运算符重载
 * @param t
 * @return
 */
CBaseChatEdit& CBaseChatEdit::operator =(const CBaseChatEdit &t)
{
    copyFrom(t);
    return *this;
}

/**
 * @brief CBaseChatEdit::copyTo
 * 对图片绑定Gif也会复制
 * @param t
 */
void CBaseChatEdit::copyFrom(const CBaseChatEdit &t)
{
    this->document()->clear();
    this->m_urlsMap.clear();
    this->m_urlsList.clear();

    this->m_urlsMap = t.m_urlsMap;

    // 一个换行一个块（QTextBlock）！如果没有内容，块的数量为1，初次插入的内容增加块
//    qDebug() << "block num = " << t.document()->blockCount();

    // 按块遍历。TextFrame > TextBlock > TextFrament 。
    // 我们的文本框只会有一个TextFrame（实验得到）
    // 多个TextBlock（实验得到）
    // 其中TextFrament的ChatFormat可以转换为 QTextImageFormat
    QTextBlock block = t.document()->begin();
    // 按块遍历
    for (; block != t.document()->end(); block = block.next()) {

        // 遇到回车前视为一个块，块内包含多个TextFrament，所以还得循环
        QTextBlock::iterator it = block.begin();
        for(; it != block.end(); it++){
            QTextImageFormat imageFormat = it.fragment().charFormat().toImageFormat();
            if(imageFormat.isValid()){
                QString path = imageFormat.name();
                dropImageByUrl(path);
                qDebug() << "CBaseChatEdit::copyFrom" << path;
            }else {
                this->insertPlainText(it.fragment().text());
            }
        }

        // 块结束。遇到回车，由于按块遍历，回车不算入块内容，手动添加
        if(block.next() != t.document()->end()){
            this->insertPlainText("\n");
        }
    }
}

/**
 * @brief 获取动图使用的绑定Map QMap<QMovie*, QString>。
 * @return
 */
QMap<QMovie *, QString> CBaseChatEdit::getUrlsMap()
{
    return this->m_urlsMap;
}

/**
 * @brief 获取图片的链接List(按文本顺序)
 * @return
 */
QList<QString> CBaseChatEdit::getUrlsList()
{
    return this->m_urlsList;
}

void CBaseChatEdit::addStaticQrcEmotion(QString path)
{
    insertHtml(QString("<img src=\"%1\" height=\"30\" width=\"30\"/>").arg(path));
    qDebug() << "addStaticQrcEmotion(QString path):" << path;
}


/**
 * @brief 判断剪贴板的内容时候可以被此控件接受。按块检测。
 * @param source 剪贴板内容
 * @return 剪贴板可以被文本框接受时返回真，反之为假
 */
bool CBaseChatEdit::canInsertFromMimeData(const QMimeData *source) const
{
    return source->hasImage() || source->hasUrls() || QTextEdit::canInsertFromMimeData(source);
}

/**
 * @brief 将剪贴版内容存储到本地路径并展示到文本框
 * @param source 剪贴板内容
 */
void CBaseChatEdit::insertFromMimeData(const QMimeData *source)
{
    if (source->hasImage())
    {
        // 剪贴板中的图片
        // 20位字符的随机文件名字
        QString filePath = "../richOle/" + Hashcode::getHashCode(20) + ".png";
        // 利用子线程保存图片
        ImageHelper *imageHelper = new ImageHelper(filePath, qvariant_cast<QImage>(source->imageData()));
        connect(imageHelper, SIGNAL(imgSaveFinished(QString)), this, SLOT(slotPutImageByLocalFile(QString)));
        imageHelper->start();
    }
    else if (source->hasUrls())
    {
        // 可能剪贴板中不止有一张图片，遍历一次
        foreach (QUrl url, source->urls())
        {
            // [1] 检查是否为Qt支持的图片
            if (isSupportImageFormat(url))
            {
                QString path = url.toLocalFile();
                dropImageByUrl(path);
            }
            else
            {
                dropTextFile(url);
            }
        }

    }else if (source->hasHtml()){
        // 使用QTextDocument辅助我们处理
        QTextDocument d(this);
        d.setHtml(source->html());
        QTextBlock block = d.begin();
        // 按块遍历
        for (; block != d.end(); block = block.next()) {

            // 遇到回车前视为一个块，块内包含多个TextFrament，所以还得循环
            QTextBlock::iterator it = block.begin();
            for(; it != block.end(); it++){
                QTextImageFormat imageFormat = it.fragment().charFormat().toImageFormat();
                if(imageFormat.isValid()){
                    QString path = imageFormat.name();
                    qDebug() << "CBaseChatEdit::insertFromMimeData :" << path;
                    dropImageByUrl(path);
                }else {
                    this->insertPlainText(it.fragment().text());
                }
            }
            // 块结束。遇到回车，由于按块遍历，回车不算入块内容，手动添加
            if(block.next() != d.end()){
                this->insertPlainText("\n");
            }
        }
    }
    else
    {
        QTextEdit::insertFromMimeData(source);
    }

}
/** 学习注解
  * [1]
  * QImageReader::supportedImageFormats 返回Qt支持绘制的图片类型（一个QByteArray链表）
  * 再使用QList的contain函数检查实际图片是否在支持的类型中
  */



/**
 * @brief 根据图片的Url，借助文本框持有的QDocument指针来存储图片，并使用
 * QTextCursor插入图片到文本框。（QDocument 与 QTextCursor 经常配套使用）
 * @param url 图片在文本框中的标识（此图片插入文本框时被赋予的名字，这里直接使用路径作为标识）
 * @param image 图片
 * @param insert 是否插入新图片到文本框。默认为ture，更新动图时需要设置为false.
 */
void CBaseChatEdit::dropImage(const QUrl &url, const QImage &image, bool insert)
{
    // 图片是否为空？
    if (!image.isNull())
    {
        document()->addResource(QTextDocument::ImageResource, url, image);
        // insert为真则插入一张新的图片
        if(insert)
            textCursor().insertImage(url.toString());
    }
}

void CBaseChatEdit::slotPutImageByLocalFile(QString path)
{
    QUrl url(path);
    QImage img(path);
    /* 太大的图片缩放一下 */
    int width = img.width();
    int height = img.height();
    while(height > 600 || width > 600)
    {
        height /= 2;
        width /= 2;
    }

    this->dropImage(url, QImage(path).scaled(width, height));
}

void CBaseChatEdit::addEmojiGif(const QString &path)
{
    insertHtml(QString("<img src=\"%1\" height=\"30\" width=\"30\"/>").arg(path));
    QUrl url(QString("qrc%1").arg(path));
    bindMovieForGif(url, path, QSize(30, 30));
}

void CBaseChatEdit::dropPixmap(const QUrl &url, const QPixmap &pixmap)
{
    QImage image = pixmap.toImage();
    dropImage(url, image);
}

void CBaseChatEdit::dropPixmap(const QUrl &url, QPixmap &pixmap, int w, int h)
{
    pixmap = pixmap.scaled(w, h, Qt::KeepAspectRatio);
    dropPixmap(url, pixmap);
}

/**
 * @brief 借助QTextCursor将信息插入到文本框
 * @param url 图片在文本框中的标识（此图片插入文本框时被赋予的名字，这里直接使用路径作为标识）
 */
void CBaseChatEdit::dropTextFile(const QUrl &url)
{
    QFile file(url.toLocalFile());
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
        textCursor().insertText(file.readAll());
}

/**
 * @brief CBaseChatEdit::InsertGif
 * @param url 图片在文本框中的标识（此图片插入文本框时被赋予的名字，这里直接使用路径作为标识）
 * @param gifPath gif文件的路径
 */
void CBaseChatEdit::bindMovieForGif(const QUrl &url, const QString &gifPath, QSize movieSize)
{
    // [!重要] 图片url链表
    // 相同路径的gif动图只需要一个QMovie就可以了，否则加入多张相同图片会倍增更新速度
    if(this->m_urlsList.contains(gifPath))
        return;
    else
        this->m_urlsList.insert(0, gifPath);

//    qDebug() << "bind";
    QMovie* movie = new QMovie(this);
    movie->setFileName(gifPath);
    movie->setCacheMode(QMovie::CacheNone);
    // 设置movie大小，如果为参数的默认值则不修改原来的大小
    if(movieSize != QSize(-1, -1)){
        movie->setScaledSize(movieSize);
    }

    // [!重要]保存 movie指针 与 图片标识名。 OnAnimate(int) 中会使用
    this->m_urlsMap[movie] = url.toString();

    // 换帧时刷新
    connect(movie, SIGNAL(frameChanged(int)), this, SLOT(onAnimate(int)));
    movie->start();
}

void CBaseChatEdit::dropImageByUrl(QString &path)
{
    switch (AppImageTypeHelper::getImageType(&path)) {
    case ImageType::GIF:
        addEmojiGif(path);
        break;
    case ImageType::NOT_GIF:
        // 本地的图片文件可以使用Html格式直接贴入，很方便
        qDebug() << "CBaseChatEdit::dropImageByUrl :" << path;
        if(path.contains(":"))
        {
            addStaticQrcEmotion(path);
            break;
        }
        slotPutImageByLocalFile(path);
        break;
    }
}


/**
 * @brief 检测路径是否为编辑框支持的格式
 * @param url
 * @return
 */
bool CBaseChatEdit::isSupportImageFormat(QUrl &url)
{
    QFileInfo info(url.toLocalFile());                    // 图片对应的路径
    return QImageReader::supportedImageFormats().contains(info.suffix().toLower().toLatin1());
}

/**
 * @brief CBaseChatEdit::OnAnimate
 * 所有动图槽函数。通过Map <Movie* : QString> 存储各个动图与图片标识Id的映射关系。
 * 实现了动图更新
 * @param no 帧号
 */
void CBaseChatEdit::onAnimate(int no)
{
    Q_UNUSED(no);
    if (QMovie* movie = qobject_cast<QMovie*>(sender()))
    {
        // 更新图片。注意insert参数置为false
        dropImage(m_urlsMap[movie], movie->currentImage(), false);
        // 刷新显示
        setLineWrapColumnOrWidth(lineWrapColumnOrWidth());
    }
}

/**
 * @brief CBaseChatEdit::setFontSize
 * 设置字体
 * @param size 字体大小
 */
void CBaseChatEdit::setFontSize(int size)
{
    QFont font = this->font();
    font.setPixelSize(size);
    this->setFont(font);
}


void CBaseChatEdit::removeImg(const QUrl & url)
{
    qDebug() << url;
}
