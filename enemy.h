#ifndef ENEMY_H
#define ENEMY_H

#include "actor.h"


class Enemy : public Actor
{
    Q_OBJECT
public:
    Enemy(QString name, int shieldLevel, int damageLevel, int strikeProbability, QObject *parent = nullptr);

    int getShield() override;
    int getDamage() override;
    int getProbability();

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
private:
    int shiledLevel;
    int damageLevel;
    int strikeProbability;
};

#endif // ENEMY_H
