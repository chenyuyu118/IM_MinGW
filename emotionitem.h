#ifndef EMOTIONITEM_H
#define EMOTIONITEM_H

#include <QLabel>

/**
 * @brief The EmotionItem class
 * gif表情项，能够显示gif表情。
 */
class EmotionItem : public QLabel
{
    Q_OBJECT
public:
    EmotionItem(QString fileName , QSize emotionMoiveSize, QWidget* parent = nullptr);
    ~EmotionItem();
    QString getFilePath();

protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
};

#endif // EMOTIONITEM_H
