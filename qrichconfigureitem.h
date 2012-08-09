#ifndef QRICHCONFIGUREITEM_H
#define QRICHCONFIGUREITEM_H

#include <QString>
#include <QFont>
#include <QColor>

struct QRichConfigureItem
{
    //关键字(keyword)
    QString keyword;
    //字体(font)
    QFont font;
    //字体颜色(color)
    QColor color;
//    QRichConfigureItem();

    //复制构造函数
    QRichConfigureItem(const QString keyword, const QFont font, const QColor color);
    //通过{keyword, font, color}三项初始化
    QRichConfigureItem(const QRichConfigureItem &item);
};

#endif // QRICHCONFIGUREITEM_H
