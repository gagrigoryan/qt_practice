

#ifndef ITEM_H
#define ITEM_H
#include <QString>
#include "hero.h"


class Item : public std::enable_shared_from_this<Item>
{
public:
    Item(QString name, QString description, int price);
    ~Item();

    QString getName();
    QString getDescription();
    int getPrice();
    virtual void consume(Hero *hero) = 0;
    virtual bool useOnce();

    virtual void peek(Hero *hero);
private:
    QString _name;
    QString _description;
    int _price = 0;
};

#endif // ITEM_H
