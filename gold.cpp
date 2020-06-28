#include "gold.h"

Gold::Gold(QString name, QString description, int amount)
    : Item(name, description, 0), amount(amount)
{

}

void Gold::peek(Hero *hero)
{
    hero->changeMoney(amount);
}

void Gold::consume(Hero *hero)
{
    //hero->changeHealth(addHealth);
}

bool Gold::useOnce()
{
    return true;
}
