#ifndef SHIELD_H
#define SHIELD_H

#include "item.h"


class Shield : public Item
{
public:
    Shield(QString name, QString description, int price, int shiledLevel);

    bool useOnce() override;
    void consume(Hero *hero) override;

    int getShield();
private:
    int shiledLevel;
};

#endif // SHIELD_H
