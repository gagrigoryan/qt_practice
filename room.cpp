#include "room.h"
#include "item.h"
#include "hero.h"

Room::Room(QString roomName, QString roomDescr, int n, int e, int s, int w, bool isFinish)
    : name(roomName), description(roomDescr), isFinish(isFinish)
{
    neighbourRooms[Direction::North]=n;
    neighbourRooms[Direction::East]=e;
    neighbourRooms[Direction::South]=s;
    neighbourRooms[Direction::West]=w;
}

void Room::putItem(std::shared_ptr<Item> item)
{
    items << item;
}

QList<std::shared_ptr<Item>> Room::visibleItems(Hero *hero)
{
    return items;
}

std::shared_ptr<Item> Room::peekItem(int index)
{
    auto item = items[index];
    items.removeOne(item);
    return item;
}

QVector<Direction> Room::canMoved()
{
    QVector<Direction> result;
    if (neighbourRooms[Direction::North] != -1)
        result << Direction::North;
    if (neighbourRooms[Direction::East] != -1)
        result << Direction::East;
    if (neighbourRooms[Direction::West] != -1)
        result << Direction::West;
    if (neighbourRooms[Direction::South] != -1)
        result << Direction::South;

    return result;
}

