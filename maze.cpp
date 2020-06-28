#include "maze.h"
#include "food.h"
#include "item.h"
#include "gold.h"
#include <QDebug>
#include "game.h"
#include "shield.h"
#include "weapon.h"

Maze::Maze()
{
    //init();
}

void Maze::init(Game *game)
{
    rooms.append(Room(QObject::tr("Хань"),
                      QObject::tr("Вы находитесь в империи Хань. Китай встал на новый путь, пользуйтесь всеми благами, что дарует вам империя."),
                      -1, 11, 2, 1)); //0
    rooms.append(Room(QObject::tr("Рим"),
                      QObject::tr("Вы находитесь в Великой Римской Империи. Сражайтесь с легионером и покажите свою мощь."),
                      5, 3, 4, -1)); //1
    rooms.append(Room(QObject::tr("Персия"),
                      QObject::tr("Персидская империя - гроза всего Ближнего Востока. Эта страна может не принять Вас всерьез, будьте осторожны."),
                      3, 1, -1, -1)); //2
    rooms.append(Room(QObject::tr("Армения"),
                      QObject::tr("Вы находитесь в Великой Армении. Сейчас здесь правит Тигран Великий. Пользуйтесь всеми благами этого гостеприимного государства."),
                      -1, 11, 7, 4)); //3
    rooms.append(Room(QObject::tr("Греция"),
                      QObject::tr("Греция - страна Геродота и Аристотеля. Боги Греции не любят чужаков, Готовьтесь к неприятностям."),
                      -1, 8, -1, 10)); //4
    rooms.append(Room(QObject::tr("Галлия"),
                      QObject::tr("Земля суровых галлов, вечных врагов Рима."),
                      6, -1, 1, -1)); //5
    rooms.append(Room(QObject::tr("Великобритания"),
                      QObject::tr("Великобритания - самая большая империя в мире. пользуйтесь всеми благами индустриальной революции и продолжайте свой путь."),
                      -1, 8, -1, 9)); //6
    rooms.append(Room(QObject::tr("Иерусалим"),
                      QObject::tr("Иерусалимское королевство - страна крестоносцев. Несмотря на то, что Священная Земля свободна, крестоносцы не за этим сюда пришли!"),
                      -1, 8, -1, 10)); //7
    rooms.append(Room(QObject::tr("США"),
                      QObject::tr("После гражданской войны США только набирает обороты! Интересно, что Вы с этого можете получить!"),
                      -1, 9, 2, 10));//8
    rooms.append(Room(QObject::tr("Россия"),
                      QObject::tr("В России неспокойно. Страна воюет на юге с османами, а внутри страны бушуют революционные настроения! Вас в любое время может кто-то вызвать на дуэль."),
                      -1, 1, 3, 8));//9
    rooms.append(Room(QObject::tr("Япония"),
                      QObject::tr("Феодальная Япония - закрытое и очень опасное место. Вы близки к победе, но еще нужно доказать свою правоту."),
                      0, -1, -1, 11));//10
    rooms.append(Room(QObject::tr("Чосон"),
                      QObject::tr("Чосон - Корейское государство, которое несмотря на то, что имеет сильных соседей, все еще является непокоренным и сильным. Вы на верном пути!"),
                      12, -1, 7, -1));//11

    rooms.append(Room(QObject::tr("Страна без войн"),
                      QObject::tr("Наконец вы в этой эпохе. Осталось всего чуть-чуть! Держитесь!"),
                      -1, -1, -1, -1, true));

    rooms[0].putItem(std::make_shared<Food>("Рис", "Увеличивает жизнь на 10", 10, 10));
    rooms[0].putItem(std::make_shared<Gold>("Шелк", "+25", 25));

    rooms[2].putItem(std::make_shared<Shield>("Перс. щит", "23", 0, 25));
    rooms[2].putItem(std::make_shared<Gold>("Ковер", "+20", 20));

    rooms[3].putItem(std::make_shared<Food>("Толма", "Увеличивает жизнь на 30", 0, 30));
    rooms[3].putItem(std::make_shared<Food>("Гата", "Увеличивает жизнь на 25", 0, 25));
    rooms[3].putItem(std::make_shared<Weapon>("Вост. клинок(3)", "Атак 3ур.", 0, 45));

    rooms[6].putItem(std::make_shared<Shield>("Щит", "40", 0, 40));
    rooms[6].putItem(std::make_shared<Weapon>("Винтовка", "Атак 4ур.", 0, 45));

    rooms[8].putItem(std::make_shared<Food>("ХотДог", "Увеличивает жизнь на 15", 0, 15));
    rooms[8].putItem(std::make_shared<Food>("Вакцина", "Увеличивает жизнь на 20", 0, 20));

    rooms[9].putItem(std::make_shared<Food>("Блины", "Увеличивает жизнь на 16", 0, 16));

    rooms[10].putItem(std::make_shared<Food>("Саке", "Увеличивает жизнь на 20", 0, 20));

    rooms[11].putItem(std::make_shared<Food>("Соджу", "Увеличивает жизнь на 30", 0, 30));
    rooms[11].putItem(std::make_shared<Food>("Рамен", "Увеличивает жизнь на 14", 0, 14));

    game->addEnemy(&rooms[1], new Enemy("Легионер", 15, 15, 30, game));
    game->addEnemy(&rooms[2], new Enemy("Перс. копейщик", 15, 15, 40, game));
    game->addEnemy(&rooms[4], new Enemy("Ахиллес", 15, 35, 55, game));
    game->addEnemy(&rooms[5], new Enemy("Галл", 45, 78, 68, game));

    game->addEnemy(&rooms[9], new Enemy("Крестоносец", 35, 60, 70, game));
    game->addEnemy(&rooms[9], new Enemy("Князь Тихонов", 20, 40, 55, game));
    game->addEnemy(&rooms[10], new Enemy("Самурай", 50, 80, 70, game));

    game->addEnemy(&rooms[12], new Enemy("Социалист", 30, 85, 90, game));
}

Room& Maze::operator[](int index)
{
    return rooms[index];
}
