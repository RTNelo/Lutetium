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
    //内部存储的所有配置(QRichConfigureItem)
    std::vector<QRichConfigureItem> item;
    //默认配置(defaultItem)
    QRichConfigureItem defaultItem;
public:
    //只需要指定风格(defaultItem)即可初始化
    QRichConfigureList(QRichConfigureItem defaultItem);
    //复制构造函数
    QRichConfigureList(const QRichConfigureList &conf);
    //设置默认风格(defaultItem)
    bool setDefaultItem(const QRichConfigureItem defaultItem);
    //获取默认风格(defaultItem)
    QRichConfigureItem getDefaultItem();
    //判断某关键字(keyword)是否存在于配置列表(QRichConfigureList)中
    bool IsIn(const QString keyword);
    //增加一个内容为{keyword, font, color}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)
    bool AddItem(const QString keyword, const QFont font, const QColor color);
    //增加一个内容为{keyword, color}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)，
    //缺少的字体(font)项根据默认配置(defaultItem)的对应项(font)补全
    bool AddItem(const QString keyword, const QColor color);
    //增加一个内容为{keyword, font}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)，
    //缺少的字体颜色(color)项根据默认配置(defaultItem)的对应项(color)补全
    bool AddItem(const QString keyword, const QFont font);
    //增加一个配置(QRichConfigureItem)到配置列表(QRichConfigureList)中
    bool AddItem(const QRichConfigureItem item);
    //判断关键字(keyword)是否存在于配置列表(QRichConfigureList)中，
    //若存在，item为配置列表(QRichConfigureList)中对应关键字(keyword)的配置(QRichConfigurItem)
    bool select(const QString keyword, QRichConfigureItem &item);
    //获取一个包含所有配置(QRichConfigureItem)的关键字项(keyword)的列表
    std::vector<QString> keywords();
};

#endif // QRICHCONFIGURE_H
