#ifndef EMOTIONWINDOW_H
#define EMOTIONWINDOW_H

#include <QTabWidget>

class EmotionWidget;

/**
 * @brief The EmotionWindow class
 * 显示表情组件的窗口，能够实现分类型显示表情
 */
class EmotionWindow : public QTabWidget
{
    Q_OBJECT
public:
    EmotionWindow(QWidget *parent = nullptr);
    ~EmotionWindow();

private:
    void initEmotionWidget();       // 加载初始表情
    void initUi();  // 初始化界面通过本地表情


signals:
    void emotionClicked(QString &path, bool isStatic);  // 此信号是为了转发表情部件被点击时的信号

public slots:
    void resizeTabWindow(int);
};

#endif // EMOTIONWINDOW_H
