#include "weapon.h"

Weapon::Weapon(QString name, QString description, int price, int damageLevel)
    : Item(name, description, price), damageLevel(damageLevel)
{

}

int Weapon::getDamage()
{
    return damageLevel;
}

void Weapon::consume(Hero *hero)
{

}

bool Weapon::useOnce()
{
    return false;
}
