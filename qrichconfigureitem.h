#ifndef QRICHCONFIGUREITEM_H
#define QRICHCONFIGUREITEM_H

#include <QString>
#include <QFont>
#include <QColor>

struct QRichConfigureItem
{
    //�ؼ���(keyword)
    QString keyword;
    //����(font)
    QFont font;
    //������ɫ(color)
    QColor color;
//    QRichConfigureItem();

    //���ƹ��캯��
    QRichConfigureItem(const QString keyword, const QFont font, const QColor color);
    //ͨ��{keyword, font, color}�����ʼ��
    QRichConfigureItem(const QRichConfigureItem &item);
};

#endif // QRICHCONFIGUREITEM_H
