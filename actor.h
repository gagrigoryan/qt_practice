#ifndef ACTOR_H
#define ACTOR_H

#include <QObject>
#include <QAbstractListModel>

class Actor : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit Actor(QString name, QObject *parent = nullptr);

    QString name;
    int health = 70;

    virtual int getShield() = 0;
    virtual int getDamage() = 0;

    int getHealth();
    void changeHealth(int health_delta);

    bool isAlive();
private:

signals:
    void health_changed(int health);

};

#endif // ACTOR_H
