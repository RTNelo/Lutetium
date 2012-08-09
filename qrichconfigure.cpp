#include "qrichconfigure.h"

//只需要指定风格(defaultItem)即可初始化
QRichConfigureList::QRichConfigureList(QRichConfigureItem defaultItem) :
    item(),
    defaultItem(defaultItem)
{
//    setDefaultItem(defaultItem);
}

//复制构造函数
QRichConfigureList::QRichConfigureList(const QRichConfigureList &conf) :
    item(conf.item),
    defaultItem(conf.defaultItem)
{
//    this->defaultItem = conf.defaultItem;
//    this->item = conf.item;
}

//设置默认风格(defaultItem)
bool QRichConfigureList::setDefaultItem(const QRichConfigureItem defaultItem)
{
    this->defaultItem = defaultItem;
    return true;
}

//获取默认风格(defaultItem)
QRichConfigureItem QRichConfigureList::getDefaultItem()
{
    return this->defaultItem;
}

//判断某关键字(keyword)是否存在于配置列表(QRichConfigureList)中
inline bool QRichConfigureList::IsIn(const QString keyword)
{
    for (std::vector<QRichConfigureItem>::iterator i = this->item.begin(); i != this->item.end(); ++i)
    {
        if (i->keyword == keyword)
        {
            return true;
        }
    }
    return false;
}

//判断关键字(keyword)是否存在于配置列表(QRichConfigureList)中，
//若存在，item为配置列表(QRichConfigureList)中对应关键字(keyword)的配置(QRichConfigurItem)
inline bool QRichConfigureList::select(const QString keyword, QRichConfigureItem &item)
{
    for (std::vector<QRichConfigureItem>::iterator i = this->item.begin(); i != this->item.end(); ++i)
    {
        if (i->keyword == keyword)
        {
            item = *i;
            return true;
        }
    }
    return false;
}

//增加一个配置(QRichConfigureItem)到配置列表(QRichConfigureList)中
bool QRichConfigureList::AddItem(const QRichConfigureItem item)
{
    if (!IsIn(item.keyword))
    {
        this->item.push_back(item);
        return true;
    }
    else
    {
        return false;
    }
}

//增加一个内容为{keyword, font, color}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)
bool QRichConfigureList::AddItem(const QString keyword, const QFont font, const QColor color)
{
    if (!IsIn(keyword))
    {
        QRichConfigureItem *item = new QRichConfigureItem(keyword, font, color);
        this->item.push_back(*item);
        delete item;
        item = 0;
        return true;
    }
    else
    {
        return false;
    }
}

//增加一个内容为{keyword, font}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)，
//缺少的字体颜色(color)项根据默认配置(defaultItem)的对应项(color)补全
bool QRichConfigureList::AddItem(const QString keyword, const QFont font)
{
    return AddItem(keyword, font, defaultItem.color);
}

//增加一个内容为{keyword, color}的配置(QRichConfigureItem)到配置列表中(QRichConfigureList)，
//缺少的字体(font)项根据默认配置(defaultItem)的对应项(font)补全
bool QRichConfigureList::AddItem(const QString keyword, const QColor color)
{
    return AddItem(keyword, defaultItem.font, color);
}

//获取一个包含所有配置(QRichConfigureItem)的关键字项(keyword)的列表
std::vector<QString> QRichConfigureList::keywords()
{
    std::vector<QString> returnVector;
    for (std::vector<QRichConfigureItem>::iterator i = this->item.begin(); i != this->item.end(); ++i)
    {
        returnVector.push_back(i->keyword);
    }
    return returnVector;
}

