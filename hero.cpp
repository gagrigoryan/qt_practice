#include "hero.h"
#include <QDebug>
#include <iostream>
#include "item.h"
#include "shield.h"
#include "weapon.h"


Hero::Hero(Maze *maze, QString name, QObject *parent)
    : Actor(name, parent), maze(maze)
{

}

void Hero::move(Direction direction)
{
    //qDebug() << maze->rooms[currentRoom].name << endl;
    currentRoom = maze->rooms[currentRoom].neighbourRooms[direction];
    emit hero_moved(currentRoom);
}

void Hero::addItem(std::shared_ptr<Item> item)
{
    beginResetModel();
    inventory << item;
    //emit inventory_changed(inventory);
    endResetModel();
}

QList<std::shared_ptr<Item>> Hero::getItems()
{
    return inventory;
}

int Hero::rowCount([[maybe_unused]]const QModelIndex &parent) const
{
    return inventory.count();
}

int Hero::columnCount([[maybe_unused]]const QModelIndex &parent) const
{
    return 3;
}

/*QVariant Hero::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Продукт");
        case 1:
            return tr("Описание");
        default:
            return QVariant();
        }
    } else {
        return QString("%1").arg(section + 1);
    }
}*/

QVariant Hero::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    switch (index.column()) {
    case 0:
        return inventory[index.row()]->getName();
    case 1:
        return QString("%1").arg(inventory[index.row()]->getDescription());
    default:
        return QVariant();
    }

    return QVariant();
}

bool Hero::changeMoney(int delta)
{
    if (money + delta < 0)
        return false;
    money += delta;
    emit money_changed(money);
    return true;
}

int Hero::getMoney()
{
    return money;
}



void Hero::useItem(int index)
{
    auto product = inventory[index];
    product->consume(this);
    if (product->useOnce()){
        beginResetModel();
        inventory.removeAt(index);
        endResetModel();
    }
}

int Hero::getShield()
{
    int maxDef = -1;
    for (auto &item : inventory) {
        try {
            Shield shield = dynamic_cast<Shield&>(*item);
            if (shield.getShield() > maxDef)
                maxDef = shield.getShield();
        } catch (const std::bad_cast& ) {

        }
    }
    if (maxDef > -1)
        return maxDef;
    else
        return 20;
}

int Hero::getDamage()
{
    int maxDam = -1;
    for (auto &item : inventory) {
        try {
            Weapon weapon = dynamic_cast<Weapon&>(*item);
            if (weapon.getDamage() > maxDam)
                maxDam = weapon.getDamage();
        } catch (const std::bad_cast& ) {

        }
    }
    if (maxDam > -1)
        return maxDam;
    else
        return 20;
}







