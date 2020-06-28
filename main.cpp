#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QInputDialog>
#include "maze.h"
#include <QTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString heroName = QInputDialog::getText(nullptr, QObject::tr("Имя пользователя: "),
                                             QObject::tr("Введите имя:"));
    Maze m;
    Game g(heroName, &m);
    MainWindow w(&g);
    w.show();


    return a.exec();
}
