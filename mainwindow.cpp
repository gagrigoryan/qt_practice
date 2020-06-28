#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "hero.h"
#include "item.h"
#include <QAbstractItemView>
#include <QDebug>
#include "shopwindow.h"


MainWindow::MainWindow(Game *game, QWidget *parent)
    : QMainWindow(parent)
    , _game(game), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->heroName->setText(_game->_hero.name);
    ui->healthLevel->setValue(_game->_hero.health);
    ui->money->setValue(_game->_hero.money);
    _game->_hero.currentRoom = 0;
    ui->subjectsList->setModel(&_game->_hero);
    enterRoom(0);
    connect(&_game->_hero, SIGNAL(hero_moved(int)), this, SLOT(enterRoom(int)));
    connect(&_game->_hero, SIGNAL(money_changed(int)), ui->money, SLOT(setValue(int)));
    connect(&_game->_hero, SIGNAL(health_changed(int)), ui->healthLevel, SLOT(setValue(int)));

    connect(_game, SIGNAL(battle_started(Battle*)), this, SLOT(battleStarted(Battle*)));
    connect(_game, SIGNAL(game_over(bool)), this, SLOT(gameOver(bool)));
}

void MainWindow::enterRoom(int room)
{
    QString roomName = _game->_maze->rooms[room].name;
    QString roomDesc = _game->_maze->rooms[room].description;
    QMap<Direction,int> roomNeighbour = _game->_maze->rooms[room].neighbourRooms;

    QList<std::shared_ptr<Item>> roomItems = _game->_maze->rooms[room].visibleItems(&_game->_hero);
    ui->roomItems->clear();
    ui->peekItem->setEnabled(!roomItems.isEmpty());
    for (int row = 0; row < roomItems.count(); ++row) {
        QListWidgetItem *nameItem = new QListWidgetItem(roomItems[row]->getName(), ui->roomItems);
        //qDebug() << roomItems[row]->getName() << endl;
        nameItem->setFlags(nameItem->flags() & ~ Qt::ItemIsEditable);
    }

    ui->roomName->setText(tr("Комната: ") + roomName);
    ui->roomDescription->setText(roomDesc);

    ui->north->setEnabled(roomNeighbour[Direction::North] != -1);
    ui->south->setEnabled(roomNeighbour[Direction::South] != -1);
    ui->east->setEnabled(roomNeighbour[Direction::East] != -1);
    ui->west->setEnabled(roomNeighbour[Direction::West] != -1);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_north_clicked()
{
    _game->_hero.move(Direction::North);
    //qDebug() << _game->_hero.getShield() << endl;
}

void MainWindow::on_east_clicked()
{
    _game->_hero.move(Direction::East);
}

void MainWindow::on_west_clicked()
{
     _game->_hero.move(Direction::West);
}

void MainWindow::on_south_clicked()
{
     _game->_hero.move(Direction::South);
}

void MainWindow::on_openShop_clicked()
{
    ShopWindow shop(&_game->_hero, this);
    shop.exec();
}

void MainWindow::on_useItem_clicked()
{
    QModelIndex currentIndex = ui->subjectsList->currentIndex();
    if (!currentIndex.isValid())
        return;
    int productIndex = currentIndex.row();
    _game->_hero.useItem(productIndex);
}

void MainWindow::on_peekItem_clicked()
{
    QModelIndex currentIndex = ui->roomItems->currentIndex();
    if (!currentIndex.isValid())
        return;
    int productIndex = currentIndex.row();
    Room *currentRoom = &_game->_maze->rooms[_game->_hero.currentRoom];
    _game->peekItem(&_game->_hero, productIndex);
    ui->roomItems->clear();
    auto roomItems = currentRoom->visibleItems(&_game->_hero);
    ui->peekItem->setEnabled(!roomItems.isEmpty());
    for (int row = 0; row < roomItems.count(); ++row) {
        QListWidgetItem *nameItem = new QListWidgetItem(roomItems[row]->getName(), ui->roomItems);
        nameItem->setFlags(nameItem->flags() & ~ Qt::ItemIsEditable);
    }
}

void MainWindow::battleStarted(Battle *battle)
{
   BattleDialog bd(battle, this);
   bd.exec();
}

void MainWindow::gameOver(bool result)
{
    QMessageBox msgBox;
    if (!result)
        msgBox.setText(QObject::tr("Вы проиграли("));
    else
        msgBox.setText(QObject::tr("Вы выиграли)"));
    msgBox.exec();
    this->close();
}








