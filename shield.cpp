#include "shield.h"

Shield::Shield(QString name, QString description, int price, int shiledLevel)
    : Item(name, description, price), shiledLevel(shiledLevel)
{

}

int Shield::getShield()
{
    return shiledLevel;
}

void Shield::consume(Hero *hero)
{

}

bool Shield::useOnce()
{
    return false;
}
