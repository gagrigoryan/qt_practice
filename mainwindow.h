#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"
#include "battledialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Game *game, QWidget *parent = nullptr);
    ~MainWindow();

    Game *_game;

private:
    Ui::MainWindow *ui;

public slots:
    void enterRoom(int room);
    void battleStarted(Battle *battle);
    void gameOver(bool result);
private slots:
    void on_north_clicked();
    void on_east_clicked();
    void on_west_clicked();
    void on_south_clicked();
    void on_openShop_clicked();
    void on_useItem_clicked();
    void on_peekItem_clicked();
};

#endif // MAINWINDOW_H
