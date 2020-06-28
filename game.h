#ifndef GAME_H
#define GAME_H

#include "hero.h"
#include "maze.h"
#include "enemy.h"
#include "battle.h"


class Game : public QObject
{
    Q_OBJECT
public:
    Game(QString heroName, Maze *maze);

    Hero _hero;
    Maze *_maze;

    void peekItem(Hero *hero, int itemIndex);

    void addEnemy(Room *room, Enemy *enemy);
    void battle(Hero *hero, Enemy *enemy);

    QMap<Room*, Enemy*> Enemies;
public slots:
    void heroMoved(int room);
private:
signals:
    void battle_started(Battle *battle);
    void game_over(bool result);


};

#endif // GAME_H
