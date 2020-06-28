#ifndef FOOD_H
#define FOOD_H
#include "item.h"

class Food : public Item
{
public:
    Food(QString name, QString description, int price, int addHealth);
    bool useOnce() override;
    void consume(Hero *hero) override;

private:
    int addHealth;
};

#endif // FOOD_H
