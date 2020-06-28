QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
CONFIG += debug

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    actor.cpp \
    battle.cpp \
    battledialog.cpp \
    enemy.cpp \
    food.cpp \
    game.cpp \
    gold.cpp \
    hero.cpp \
    item.cpp \
    main.cpp \
    mainwindow.cpp \
    maze.cpp \
    room.cpp \
    shield.cpp \
    shopwindow.cpp \
    weapon.cpp

HEADERS += \
    actor.h \
    battle.h \
    battledialog.h \
    enemy.h \
    food.h \
    game.h \
    gold.h \
    hero.h \
    item.h \
    mainwindow.h \
    maze.h \
    room.h \
    shield.h \
    shopwindow.h \
    weapon.h

FORMS += \
    battledialog.ui \
    mainwindow.ui \
    shopwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
