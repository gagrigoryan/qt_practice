#ifndef BATTLEDIALOG_H
#define BATTLEDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "battle.h"

namespace Ui {
class BattleDialog;
}

class BattleDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BattleDialog(Battle *battle,  QWidget *parent = nullptr);
    ~BattleDialog();

public slots:
    void battleHit(Actor *from, Actor *to, int damage);

private slots:
    void on_attackBtn_clicked();
    void battleFinished(Actor *winner, Actor *looser);


private:
    Ui::BattleDialog *ui;

    Battle *battle;

signals:
    void run(int room);
};

#endif // BATTLEDIALOG_H
