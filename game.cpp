#include "game.h"
#include <memory>
#include "item.h"
#include "food.h"
#include "weapon.h"
#include <QDebug>

Game::Game(QString heroName, Maze *maze)
    :_hero(maze, heroName), _maze(maze)
{
    _hero.addItem(std::make_shared<Food>("Бутерброд", "Увеличивает жизнь на 5", 15, 5));
    _hero.addItem(std::make_shared<Food>("Толма", "Увеличивает жизнь на 6", 20, 6));
    _hero.addItem(std::make_shared<Weapon>("Меч", "Атак 1ур.", 0, 15));

    _maze->init(this);

    connect(&_hero, &Hero::hero_moved, this, &Game::heroMoved);
}

void Game::peekItem(Hero *hero, int itemIndex)
{
    Room *currentRoom = &_maze->rooms[hero->currentRoom];
    currentRoom->peekItem(itemIndex)->peek(hero);
}

void Game::addEnemy(Room *room, Enemy *enemy)
{
    Enemies[room] = enemy;
}

void Game::battle(Hero *hero, Enemy *enemy)
{
    qDebug() << "Fight: " << hero->name << " -vs- " << enemy->name << endl;
    Battle battle(hero, enemy);
    emit battle_started(&battle);
    if (!enemy->isAlive()) {
        Enemies.remove(&hero->maze->rooms[hero->currentRoom]);
    }
    if (!hero->isAlive()) {
        emit game_over(false);
    }
}

void Game::heroMoved(int room)
{
    Room *currentRoom = &_maze->rooms[room];
    if (Enemies.contains(currentRoom))
        battle(&_hero, Enemies[currentRoom]);
    if (currentRoom->isFinish && _hero.health > 0)
        emit game_over(true);
}
