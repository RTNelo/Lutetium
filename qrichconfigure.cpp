#include "qrichconfigure.h"

//ֻ��Ҫָ�����(defaultItem)���ɳ�ʼ��
QRichConfigureList::QRichConfigureList(QRichConfigureItem defaultItem) :
    item(),
    defaultItem(defaultItem)
{
//    setDefaultItem(defaultItem);
}

//���ƹ��캯��
QRichConfigureList::QRichConfigureList(const QRichConfigureList &conf) :
    item(conf.item),
    defaultItem(conf.defaultItem)
{
//    this->defaultItem = conf.defaultItem;
//    this->item = conf.item;
}

//����Ĭ�Ϸ��(defaultItem)
bool QRichConfigureList::setDefaultItem(const QRichConfigureItem defaultItem)
{
    this->defaultItem = defaultItem;
    return true;
}

//��ȡĬ�Ϸ��(defaultItem)
QRichConfigureItem QRichConfigureList::getDefaultItem()
{
    return this->defaultItem;
}

//�ж�ĳ�ؼ���(keyword)�Ƿ�����������б�(QRichConfigureList)��
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

//�жϹؼ���(keyword)�Ƿ�����������б�(QRichConfigureList)�У�
//�����ڣ�itemΪ�����б�(QRichConfigureList)�ж�Ӧ�ؼ���(keyword)������(QRichConfigurItem)
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

//����һ������(QRichConfigureItem)�������б�(QRichConfigureList)��
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

//����һ������Ϊ{keyword, font, color}������(QRichConfigureItem)�������б���(QRichConfigureList)
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

//����һ������Ϊ{keyword, font}������(QRichConfigureItem)�������б���(QRichConfigureList)��
//ȱ�ٵ�������ɫ(color)�����Ĭ������(defaultItem)�Ķ�Ӧ��(color)��ȫ
bool QRichConfigureList::AddItem(const QString keyword, const QFont font)
{
    return AddItem(keyword, font, defaultItem.color);
}

//����һ������Ϊ{keyword, color}������(QRichConfigureItem)�������б���(QRichConfigureList)��
//ȱ�ٵ�����(font)�����Ĭ������(defaultItem)�Ķ�Ӧ��(font)��ȫ
bool QRichConfigureList::AddItem(const QString keyword, const QColor color)
{
    return AddItem(keyword, defaultItem.font, color);
}

//��ȡһ��������������(QRichConfigureItem)�Ĺؼ�����(keyword)���б�
std::vector<QString> QRichConfigureList::keywords()
{
    std::vector<QString> returnVector;
    for (std::vector<QRichConfigureItem>::iterator i = this->item.begin(); i != this->item.end(); ++i)
    {
        returnVector.push_back(i->keyword);
    }
    return returnVector;
}

