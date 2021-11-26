#include "messagedelegate.h"
#include <QPainter>
#include "cbasechatedit.h"
#include "messagedata.h"
#include "textqjsonhelper.h"
#include <QTextEdit>
#include <QDebug>
#include <QBrush>
#include <QJsonObject>
#include <QListView>

MessageDelegate::MessageDelegate(QObject *parent):
    QStyledItemDelegate (parent)
{

}

QWidget *MessageDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 创建代理的编辑器
    CBaseChatEdit *editor = new CBaseChatEdit(parent);
    editor->setReadOnly(true);
    editor->setStyleSheet("background:transparent;border-width:0;border-style:outset");

    QVariant var = index.data(Qt::UserRole+1);
    MessageData item = var.value<MessageData>();

    // 解析消息数据放入文本框
    TextQJsonHelper::QJsonObject2TextEdit(editor, item.text);
    return editor;
}

void MessageDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 重绘
    if (index.isValid()) {
        painter->save();

        QVariant var = index.data(Qt::UserRole+1);
        MessageData itemData = var.value<MessageData>();

        // item 矩形区域
        QRectF rect = option.rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width()-1);
        rect.setHeight(option.rect.height()-1);

        QPainterPath path;
        path.moveTo(rect.topRight());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(), rect.topLeft());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());

         //鼠标悬停或者选中时改变背景色
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setPen(QPen(QColor("#ebeced")));
            painter->setBrush(QColor("#ebeced"));
            painter->drawPath(path);
        }
        if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setPen(QPen(QColor("#e3e3e5")));
            painter->setBrush(QColor("#e3e3e5"));
            painter->drawPath(path);
        }
        bool isMine = itemData.isMine;
        QRectF iconRect, nameRect, megRect, timeRect;
        // 确定方向
        if (!isMine) {
            iconRect = QRect(rect.left(), rect.top(), 50, rect.height());
            nameRect = QRect(iconRect.right()+5, rect.top(), 100, 10);
            megRect = QRect(iconRect.right()+5, nameRect.bottom(), 100, rect.height()-10);
            timeRect = QRect(rect.right()-100, rect.top()+15, 100, rect.height());
        } else {
            iconRect = QRect(rect.right(), rect.top(), 50, rect.height());
            nameRect = QRect(iconRect.right()-5, rect.top(), 100, 10);
            megRect = QRect(iconRect.right()-5, nameRect.bottom(), 100, rect.height()-10);
            timeRect = QRect(rect.left()+100, rect.top()+15, 100, rect.height());
        }

        painter->drawImage(iconRect, itemData.profile.toImage()); // 头像
        QString time = itemData.time;
        QString name = itemData.name;
        painter->setPen(QPen(Qt::black)); // 换黑笔写字
        painter->setFont(QFont("Microsoft Yahei", 10)); // 大字
        painter->drawText(timeRect, time);
        painter->setPen(QPen(Qt::blue));
        painter->drawRect(megRect);
        painter->setPen(QPen(Qt::black)); // 换黑笔写字
        painter->setFont(QFont("Microsoft Yahei", 5));
        painter->drawText(nameRect, name);

        painter->setPen(QPen(Qt::blue));
        QRect textEditRect = option.rect.adjusted(+200, +10, -50, -7);
        painter->drawRect(textEditRect);

        painter->restore();
    }
}

void MessageDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QRect textEditRect = option.rect.adjusted(+200, +10, -50, -7);
    editor->setGeometry(textEditRect);
}

QSize MessageDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    // 设置框的大小
    Q_UNUSED(index)

    return QSize(option.rect.width(), 100);
}

void MessageDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    Q_UNUSED(editor)
    Q_UNUSED(index)
    QTextEdit *textEdit = static_cast<QTextEdit *>(editor);

    qDebug() << "current size" << textEdit->rect();

}

void MessageDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}
