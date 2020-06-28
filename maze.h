#ifndef MAZE_H
#define MAZE_H

#include "room.h"
#include <QObject>
#include <memory>

class Game;

class Maze {
public:
    Maze();

    QList<Room> rooms;

    Room& operator[] (int index);
    void init(Game *game);

private:
    //Game *game;
};

#endif // MAZE_H
