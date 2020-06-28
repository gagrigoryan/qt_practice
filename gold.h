#ifndef GOLD_H
#define GOLD_H

#include "item.h"


class Gold : public Item
{
public:
    Gold(QString name, QString description, int amount);
    bool useOnce() override;
    void consume(Hero *hero) override;

    virtual void peek(Hero *hero) override;

private:
    int amount;
};

#endif // GOLD_H
