#include "item.h"
#include <QDebug>

Item::Item(QString name, QString description, int price)
    :_name(name), _description(description), _price(price)
{

}

QString Item::getName()
{
    return _name;
}

QString Item::getDescription()
{
    return _description;
}

int Item::getPrice()
{
    return _price;
}

bool Item::useOnce()
{
    return false;
}

void Item::peek(Hero *hero)
{
    hero->addItem(shared_from_this());
}

Item::~Item()
{

}



