#include "battledialog.h"
#include "ui_battledialog.h"
#include <iterator>
#include <random>
#include "room.h"
#include <QDebug>

BattleDialog::BattleDialog(Battle *battle, QWidget *parent)
    : QDialog(parent),
    ui(new Ui::BattleDialog), battle(battle)
{
    ui->setupUi(this);
    Hero *hero = battle->getHero();
    Enemy *enemy = battle->getEnemy();
    ui->heroName->setText(QString("Имя: %1").arg(hero->name));
    ui->enemyName->setText(QString("Имя: %1").arg(enemy->name));
    ui->heroHealth->setValue(hero->health);
    ui->enemyHealth->setValue(enemy->health);

    connect(hero, SIGNAL(health_changed(int)), ui->heroHealth, SLOT(setValue(int)));
    connect(enemy, SIGNAL(health_changed(int)), ui->enemyHealth, SLOT(setValue(int)));

    connect(battle, SIGNAL(battle_hit(Actor*, Actor*, int)), this, SLOT(battleHit(Actor*, Actor*, int)));
    connect(battle, SIGNAL(battle_finished(Actor*, Actor*)), this, SLOT(battleFinished(Actor*, Actor*)));
}

BattleDialog::~BattleDialog()
{
    delete ui;
}

void BattleDialog::on_attackBtn_clicked()
{
    battle->hero_attack();
}

void BattleDialog::battleHit(Actor *from, Actor *to, int damage)
{
    ui->battleHistory->addItem(QString("%1 наносит удар %2 - %3").arg(from->name).arg(to->name).arg(damage));
}

void BattleDialog::battleFinished(Actor *winner, Actor *looser)
{
    QMessageBox msgBox;
    msgBox.setText(QString("%1 победил!").arg(winner->name));
    msgBox.exec();
    this->reject();
}
