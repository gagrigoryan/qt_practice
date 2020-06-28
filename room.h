#ifndef ROOM_H
#define ROOM_H

#include <QString>
#include <QMap>
#include <memory>

class Item;
class Hero;

enum class Direction {North=0, East, South, West};

class Room
{
public:
    Room(QString roomName, QString roomDescr, int n, int e, int s, int w, bool isFinish=false);

    QString name;
    QString description;

    QMap<Direction,int> neighbourRooms;

    void putItem(std::shared_ptr<Item> item);
    std::shared_ptr<Item> peekItem(int index);
    QList<std::shared_ptr<Item>> visibleItems(Hero *hero);

    bool isFinish;
    QVector<Direction> canMoved();
private:
    QList<std::shared_ptr<Item>> items;

};

#endif // ROOM_H
