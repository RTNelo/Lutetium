#include "qrichconfigureitem.h"

//QRichConfigureItem::QRichConfigureItem()
//{
//    keyword = QString("");
//    font = QFont();
//    color = QColor();
//}

//���ƹ��캯��
QRichConfigureItem::QRichConfigureItem(const QRichConfigureItem &item)
{
    keyword = item.keyword;
    font = item.font;
    color = item.color;
}

//ͨ��{keyword, font, color}�����ʼ��
QRichConfigureItem::QRichConfigureItem(const QString keyword, const QFont font, const QColor color)
{
    this->keyword = keyword;
    this->font = font;
    this->color = color;
}
