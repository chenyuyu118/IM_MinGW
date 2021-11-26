#include "messagelistdelegate.h"
#include <QLineEdit>
#include "messagelistdata.h"
#include <QPainter>
#include <QDebug>

MessageListDelegate::MessageListDelegate(QObject *parent):
    QStyledItemDelegate (parent)
{

}

QWidget *MessageListDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *editor = new QLineEdit;
    QVariant var = index.data(Qt::UserRole+1);
    MessageListData data = var.value<MessageListData>();
    editor->setText(data.nickname);
    editor->setReadOnly(true);
    return editor;
}

void MessageListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole+1);
        MessageListData itemData = var.value<MessageListData>();

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

       QRectF iconRect = QRect(rect.left(), rect.top(), 50, rect.height());
       QRectF nameRect = QRect(iconRect.right()+5, rect.top(), 100, rect.height());

       QBrush brush;
       brush.setColor(Qt::red);
       painter->setBrush(brush);
       painter->drawImage(iconRect, itemData.profile.toImage()); // 画图片
       painter->setPen(QPen(Qt::black)); // 换黑笔写字
       painter->setFont(QFont("Microsoft Yahei", 10)); // 大字
       painter->drawText(nameRect, itemData.nickname);

       painter->restore();
    }
}

void MessageListDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

}

QSize MessageListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index)
    return QSize(option.rect.width(), 100);
}

void MessageListDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    Q_UNUSED(editor)
    Q_UNUSED(index)
    QVariant var = index.data(Qt::UserRole+1);
    MessageListData itemData = var.value<MessageListData>();
    QLineEdit *textEdit = static_cast<QLineEdit *>(editor);
    textEdit->setText(itemData.nickname);
}

void MessageListDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{

}
