#ifndef HERO_H
#define HERO_H

#include <QObject>
#include <QAbstractListModel>
#include <memory>
#include "maze.h"
#include "actor.h"

class Item;

class Hero : public Actor
{
    Q_OBJECT
public:
    explicit Hero(Maze *maze, QString name, QObject *parent = nullptr);

    Maze *maze;
    int currentRoom;

    int money = 25;

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    //virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    virtual int getShield() override;
    virtual int getDamage() override;

    void move(Direction direction);

    void addItem(std::shared_ptr<Item>);
    QList<std::shared_ptr<Item>> getItems();

    bool changeMoney(int delta);
    int getMoney();

    void useItem(int index);
private:
     QList<std::shared_ptr<Item>> inventory;
signals:
    void hero_moved(int room);
    void money_changed(int money);

};

#endif // HERO_H
