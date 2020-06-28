#ifndef BATTLE_H
#define BATTLE_H

#include <QObject>
#include "hero.h"
#include "enemy.h"

class Battle : public QObject
{
    Q_OBJECT
public:
    explicit Battle(Hero *hero, Enemy *enemy, QObject *parent = nullptr);

    Hero *getHero();
    Enemy *getEnemy();

    int hitDamage(int hitLevel, int shieldLevel);

    void attack(Actor *from, Actor *to);
    void timerEvent(QTimerEvent *event);
    int timerID;
public slots:
    void hero_attack();

private:
    Hero *hero;
    Enemy *enemy;

signals:
    void battle_hit(Actor *from, Actor *to, int damage);
    void battle_finished(Actor *winner, Actor *looser);

};

#endif // BATTLE_H
