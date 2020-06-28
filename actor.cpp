#include "actor.h"

Actor::Actor(QString name, QObject *parent)
    : QAbstractListModel(parent), name(name)
{

}


int Actor::getHealth()
{
    return health;
}

void Actor::changeHealth(int health_delta)
{
    int currHealth = health + health_delta;
    if (currHealth >= 100)
        health = 100;
    else if (currHealth <= 0)
        health = 0;
    else
        health = currHealth;
    emit health_changed(health);
}

bool Actor::isAlive()
{
    return health > 0;
}
