#include "qrichconfigureitem.h"

//QRichConfigureItem::QRichConfigureItem()
//{
//    keyword = QString("");
//    font = QFont();
//    color = QColor();
//}

//复制构造函数
QRichConfigureItem::QRichConfigureItem(const QRichConfigureItem &item)
{
    keyword = item.keyword;
    font = item.font;
    color = item.color;
}

//通过{keyword, font, color}三项初始化
QRichConfigureItem::QRichConfigureItem(const QString keyword, const QFont font, const QColor color)
{
    this->keyword = keyword;
    this->font = font;
    this->color = color;
}
