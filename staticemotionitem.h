#ifndef STATICEMOTIONITEM_H
#define STATICEMOTIONITEM_H
#include <QLabel>


class Staticemotionitem : public QLabel
{
    Q_OBJECT
public:
    Staticemotionitem(QWidget *parent = nullptr);
    Staticemotionitem(QString fileName, QSize size, QWidget *parent = nullptr);
    ~Staticemotionitem();

    QString getFilePath();
protected:
    void enterEvent(QEvent* event);
    void leaveEvent(QEvent* event);
private:
    QString filePath;
};

#endif // STATICEMOTIONITEM_H
