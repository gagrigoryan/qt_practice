#ifndef WEAPON_H
#define WEAPON_H

#include "item.h"


class Weapon : public Item
{
public:
    Weapon(QString name, QString description, int price, int damageLevel);

    bool useOnce() override;
    void consume(Hero *hero) override;

    int getDamage();

private:
    int damageLevel;
};

#endif // WEAPON_H
