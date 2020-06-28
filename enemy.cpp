#include "enemy.h"

Enemy::Enemy(QString name, int shieldLevel, int damageLevel, int strikeProbability, QObject *parent)
    : Actor(name, parent), shiledLevel(shieldLevel), damageLevel(damageLevel),
      strikeProbability(strikeProbability)
{

}

int Enemy::getDamage()
{
    return damageLevel;
}

int Enemy::getShield()
{
    return shiledLevel;
}

int Enemy::getProbability()
{
    return strikeProbability;
}

QVariant Enemy::data(const QModelIndex &index, int role) const
{
    return QVariant();
}

int Enemy::rowCount([[maybe_unused]]const QModelIndex &parent) const
{
    return 0;
}
