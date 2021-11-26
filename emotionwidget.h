#ifndef EMOTIONWIDGET_H
#define EMOTIONWIDGET_H

#include <QTableWidget>
#include <QList>

/**
 * @brief The EmotionWidget class
 * 表情框部件，容纳同类型的表情
 */
class EmotionWidget : public QTableWidget
{
    Q_OBJECT
public:
    EmotionWidget(QWidget* parent = nullptr, int row = 8, int col = 8);
    ~EmotionWidget();
    void initTableWidget(); // 初始化表格
    void addEmotionItem(QString fileName , QString toolTip = QString()); // 通过文件名添加表情
    void setRowAndColumn(int row, int column); // 设置行列
    void setEmotionSize(QSize emotionSize); // 设置表情尺寸
    void setEmotionMovieSize(QSize emotionMovieSize); // 设置动图尺寸
    void setMaxRow(int maxRow); // 设置最大行

private:
    int m_tableRow;                 // 行
    int m_tableColumn;              // 列
    int m_maxRow;                   // 表格最大容纳行 = 部件高/行高
    QSize m_emotionSize;            // 表情大小
    QSize m_emotionMovieSize;       // 表情动图的大小
    QList<QString> m_emotionList;   // 表情路径链表

signals:
    void emotionClicked(QString path, int isStatic);          // 表情被点击后由处理函数发送的信号

private slots:
    void dealCellClicked(int row, int col);        // 表情被点击时处理一下点击的信息


};

#endif // EMOTIONWIDGET_H
