#ifndef CBASECHATEDIT_H
#define CBASECHATEDIT_H

#include <QTextEdit>
#include <QMap>

class AppImageTypeHelper;
enum class ImageType;

/**
 * @brief The CBaseChatEdit class
 * 文本展示基类
 */
class CBaseChatEdit : public QTextEdit
{
    Q_OBJECT
public:
    CBaseChatEdit(QWidget *parent = nullptr);
    ~CBaseChatEdit();
    void setFontFamily(const QString& fontFamily);
    CBaseChatEdit& operator =(const CBaseChatEdit& t);
    void copyFrom(const CBaseChatEdit& t);
    QMap<QMovie *, QString> getUrlsMap();
    void dropImageByUrl(QString &path);
    QList<QString> getUrlsList();
    void addStaticQrcEmotion(QString path);

protected:
    bool canInsertFromMimeData(const QMimeData* source) const;  // 重写剪贴板检测          (can | can't)
    void insertFromMimeData(const QMimeData* source);           // 重写剪贴板以支持粘贴图片 （QImage）
    void dropPixmap(const QUrl &url, const QPixmap &pixmap);
    void dropPixmap(const QUrl &url, QPixmap &pixmap, int w, int h);
    void dropTextFile(const QUrl& url);                         // 文字加入文本
    void bindMovieForGif(const QUrl& url, const QString& gifPath, QSize movieSize = QSize(-1, -1));// 给动图绑定更新信号
    bool isSupportImageFormat(QUrl& url);

protected:
    QMap<QMovie*, QString> m_urlsMap;                           // Map key:movie* value:url
    QList<QString> m_urlsList;                                  // List urls


signals:
    void fontSizeChanged(int size);

public slots:
    void setFontSize(int size);
    void addEmojiGif(const QString &path);

protected slots:
    void onAnimate(int no);
    void removeImg(const QUrl &url);
    void dropImage(const QUrl& url, const QImage& image, bool insert = true);           // 更新图片到文本框
    void slotPutImageByLocalFile(QString path);

};


/** 留下的坑
  * [1] 使用退格删除动图时它在编辑框内的资源其实没有被释放。因为退格时被删除的东西不知道如何去检测
  * 可能的解决办法:使用智能指针，当退格时检测是否为动图删除....（如果能检测到是动图被删除，其实也可以写函数手动释放了）
  *              但是问题比较小，抓紧做
  *
  */

#endif // CBASECHATEDIT_H
