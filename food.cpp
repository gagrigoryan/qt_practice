#include "food.h"

Food::Food(QString name, QString description, int price, int addHealth)
    : Item(name, description, price), addHealth(addHealth)
{

}

void Food::consume(Hero *hero)
{
    hero->changeHealth(addHealth);
}

bool Food::useOnce()
{
    return true;
}
