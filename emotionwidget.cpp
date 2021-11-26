#include "emotionwidget.h"
#include "emotionitem.h"
#include "staticemotionitem.h"

#include <QFile>
#include <QHeaderView>
#include <QDebug>
#include <QPicture>

EmotionWidget::EmotionWidget(QWidget* parent, int row, int col)
    : QTableWidget (parent),
      m_tableRow(row),
      m_tableColumn(col),
      m_maxRow(row),
      m_emotionSize(QSize(0 , 0)),
      m_emotionMovieSize(QSize(0 , 0))
{
    this->setStyleSheet("EmotionWidget{\n"
                        "border:none;\n"
                        "}"
                        "EmotionWidget::item{\n"
                        "border:none;\n"
                        "}");

    connect(this, SIGNAL(cellClicked(int, int)), this, SLOT(dealCellClicked(int, int)));
}

EmotionWidget::~EmotionWidget()
{

}


// 设置表情窗口的行列数目
void EmotionWidget::setRowAndColumn(int row, int column)
{
    m_tableRow = row;
    m_tableColumn = column;
}

// 设置item表情框大小
void EmotionWidget::setEmotionSize(QSize emotionSize)
{
    m_emotionSize = emotionSize;
}

// 设置表情movie大小
void EmotionWidget::setEmotionMovieSize(QSize emotionMovieSize)
{
    m_emotionMovieSize = emotionMovieSize;
}

// 设置最大行数
void EmotionWidget::setMaxRow(int maxRow)
{
    m_maxRow = maxRow;
}

void EmotionWidget::dealCellClicked(int row, int col)
{
    QWidget *w = cellWidget(row, col);
    if(!w)
    {
        return;
    }
    if (w->metaObject()->className() == QStringLiteral("EmotionItem")) {
        EmotionItem *emotionItem = qobject_cast<EmotionItem *>(w);
        emit emotionClicked(emotionItem->getFilePath(), false);
    } else if (w->metaObject()->className() == QStringLiteral("Staticemotionitem")) {
        Staticemotionitem *emotionItem = qobject_cast<Staticemotionitem *>(w);
//        qDebug() << emotionItem->getFilePath();
        emit emotionClicked(emotionItem->getFilePath(), true);
    }

      // 发射点击信号

}


// 设置完参数后，进行初始化
void EmotionWidget::initTableWidget()
{
    this->setFocusPolicy(Qt::NoFocus);                          // 设置无焦点
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);   // 设置不可编辑
    this->setShowGrid(false);                                   // 去掉网格背景
    this->setRowCount(m_tableRow);                              // 设置行数
    this->setColumnCount(m_tableColumn);                        // 设置列数
    // 设置表头不可见并设置表情item框大小

    this->horizontalHeader()->setVisible(false);
    this->horizontalHeader()->setDefaultSectionSize(m_emotionSize.width());

    this->verticalHeader()->setVisible(false);
    this->verticalHeader()->setDefaultSectionSize(m_emotionSize.height());

    // 设置表情窗口的大小，这里行数超过m_maxRow时作了处理，当行数超过给的最大值，则通过滚动 滚动条显示剩余的表情
    if (m_tableRow > m_maxRow)
    {
        this->setFixedHeight(m_emotionSize.height() * m_maxRow + 2);

        // 这里宽度加30，是因为在这种情况下会tablewidget会显示出横向滚动条，所以为了显示正常，增加一点宽度
        this->setFixedWidth(m_emotionSize.width() * m_tableColumn + 26);
    }
    else
    {
        this->setFixedHeight(m_emotionSize.height()*m_tableRow + 2);
        this->setFixedWidth(m_emotionSize.width()*m_tableColumn + 2);
    }
}

void EmotionWidget::addEmotionItem(QString fileName , QString toolTip)
{
    // 计算表情当前位置(插入最末尾)
        // 末尾行 = 已有行 > 0 ? 表情总数/列数 : 0
    int emotionRow = this->columnCount() > 0
                     ? m_emotionList.size() / this->columnCount()
                     : 0;
        // 末尾列 = 已有行 > 0 ? 表情总数%列数 : 表情总数
    int emotionColumn = this->columnCount() > 0
                        ? m_emotionList.size() % this->columnCount()
                        : m_emotionList.size();


    QTableWidgetItem* tableWidgetItem = new QTableWidgetItem;
    this->setItem(emotionRow, emotionColumn, tableWidgetItem);
    if (fileName.endsWith(".gif")) {
        // 动图
        EmotionItem* emotionIcon = new EmotionItem(fileName , m_emotionMovieSize);
        this->setCellWidget(emotionRow, emotionColumn, emotionIcon);
         emotionIcon->setToolTip(toolTip);
    } else {
        // 非动图
        Staticemotionitem* emotionIcon = new Staticemotionitem(fileName, m_emotionSize);
        emotionIcon->setToolTip(toolTip);
        this->setCellWidget(emotionRow, emotionColumn, emotionIcon);
        // qDebug() << fileName;
    }
    m_emotionList.push_back(fileName);
}
