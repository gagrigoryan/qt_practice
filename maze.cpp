#include "maze.h"
#include "food.h"
#include "item.h"
#include "gold.h"
#include <QDebug>
#include "game.h"

Maze::Maze()
{
    //init();
}

void Maze::init(Game *game)
{
    rooms.append(Room(QObject::tr("Крыльцо"),
                      QObject::tr("Вы стоите на крыльце. Перед Вами находится совершенно загадочная дверь."),
                      1, -1, -1, -1));
    rooms.append(Room(QObject::tr("Гостиная"),
                      QObject::tr("Вы попали в гостиную. В камине сидит страшный жирный паук."),
                      -1, -1, 0, 2));
    rooms.append(Room(QObject::tr("Кабинет"),
                      QObject::tr("Вы стоите в кабинете. Книжный шкаф полон старинных книг."),
                      -1, 1, -1, -1, true));

    rooms[0].putItem(std::make_shared<Food>("ХотДог", "Описание ХотДога", 0, 15));
    rooms[0].putItem(std::make_shared<Food>("Роллы", "Описание Ролл", 0, 25));
    rooms[1].putItem(std::make_shared<Food>("Хлеб", "Описание Хлеба", 0, 15));

    rooms[0].putItem(std::make_shared<Gold>("Золото", "+17", 17));
    rooms[2].putItem(std::make_shared<Gold>("Золото", "+10", 10));

    game->addEnemy(&rooms[1], new Enemy("Bell", 15, 30, 50, game));
}

Room& Maze::operator[](int index)
{
    return rooms[index];
}
