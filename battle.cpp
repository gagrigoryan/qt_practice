#include "battle.h"
#include <QDebug>
#include <QGlobal.h>
#include <QTime>

Battle::Battle(Hero *hero, Enemy *enemy, QObject *parent)
    : QObject(parent), hero(hero), enemy(enemy)
{
    timerID = startTimer(500);
}

Hero* Battle::getHero()
{
    return hero;
}

Enemy* Battle::getEnemy()
{
    return enemy;
}

void Battle::hero_attack()
{
    qDebug() << hero->name << " атакует" << endl;
    attack(hero, enemy);
}

int Battle::hitDamage(int hitLevel, int shieldLevel)
{
    int minHit = 5;
    int threshold = 20;
    int maxHit = (shieldLevel - hitLevel >= threshold) ? shieldLevel - hitLevel : threshold;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    return  qrand() % ((maxHit + 1) - minHit) + minHit;
}

void Battle::attack(Actor *from, Actor *to)
{
    int damage = from->getDamage();
    int shield = to->getShield();
    int hit = hitDamage(damage, shield);
    emit battle_hit(from, to, hit);
    to->changeHealth(-hit);
    if (!to->isAlive()) {
        killTimer(timerID);
        emit battle_finished(from, to);
    }
}

void Battle::timerEvent(QTimerEvent *event)
{
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    int rand = qrand() % ((100 + 1) - 0) + 0;
    if (rand < enemy->getProbability())
        attack(enemy, hero);

}




