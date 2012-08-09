#ifndef QRICHCONFIGURE_H
#define QRICHCONFIGURE_H

#include <QObject>
#include <QString>
#include <QFont>
#include <QColor>
#include <vector>
#include "qrichconfigureitem.h"



class QRichConfigureList
{
private:
    //�ڲ��洢����������(QRichConfigureItem)
    std::vector<QRichConfigureItem> item;
    //Ĭ������(defaultItem)
    QRichConfigureItem defaultItem;
public:
    //ֻ��Ҫָ�����(defaultItem)���ɳ�ʼ��
    QRichConfigureList(QRichConfigureItem defaultItem);
    //���ƹ��캯��
    QRichConfigureList(const QRichConfigureList &conf);
    //����Ĭ�Ϸ��(defaultItem)
    bool setDefaultItem(const QRichConfigureItem defaultItem);
    //��ȡĬ�Ϸ��(defaultItem)
    QRichConfigureItem getDefaultItem();
    //�ж�ĳ�ؼ���(keyword)�Ƿ�����������б�(QRichConfigureList)��
    bool IsIn(const QString keyword);
    //����һ������Ϊ{keyword, font, color}������(QRichConfigureItem)�������б���(QRichConfigureList)
    bool AddItem(const QString keyword, const QFont font, const QColor color);
    //����һ������Ϊ{keyword, color}������(QRichConfigureItem)�������б���(QRichConfigureList)��
    //ȱ�ٵ�����(font)�����Ĭ������(defaultItem)�Ķ�Ӧ��(font)��ȫ
    bool AddItem(const QString keyword, const QColor color);
    //����һ������Ϊ{keyword, font}������(QRichConfigureItem)�������б���(QRichConfigureList)��
    //ȱ�ٵ�������ɫ(color)�����Ĭ������(defaultItem)�Ķ�Ӧ��(color)��ȫ
    bool AddItem(const QString keyword, const QFont font);
    //����һ������(QRichConfigureItem)�������б�(QRichConfigureList)��
    bool AddItem(const QRichConfigureItem item);
    //�жϹؼ���(keyword)�Ƿ�����������б�(QRichConfigureList)�У�
    //�����ڣ�itemΪ�����б�(QRichConfigureList)�ж�Ӧ�ؼ���(keyword)������(QRichConfigurItem)
    bool select(const QString keyword, QRichConfigureItem &item);
    //��ȡһ��������������(QRichConfigureItem)�Ĺؼ�����(keyword)���б�
    std::vector<QString> keywords();
};

#endif // QRICHCONFIGURE_H
