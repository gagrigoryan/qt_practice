#include "shopwindow.h"
#include "ui_shopwindow.h"
#include <QDebug>
#include "item.h"
#include "food.h"
#include "shield.h"
#include "weapon.h"

ShopWindow::ShopWindow(Hero *_hero, QWidget *parent) :
    QDialog(parent),
    _hero(_hero),
    ui(new Ui::ShopWindow)
{
    ui->setupUi(this);
    ui->money->setValue(_hero->getMoney());
    _inventory << std::make_shared<Food>("Бутерброд", "Увеличивает жизнь на 5", 5, 5)
               << std::make_shared<Food>("Толма", "Увеличивает жизнь на 100", 20, 30)
               << std::make_shared<Shield>("Щит(2)", "Защита 1ур.", 48, 26)
               << std::make_shared<Weapon>("Самурайский меч", "Атак 4ур.", 56, 40)
               << std::make_shared<Weapon>("AR-15", "Атак 6ур.", 90, 80)
               << std::make_shared<Food>("Круассан", "Увеличивает жизнь на 23", 15, 23);

    ui->subjectsTable->setModel(new ShopModel(&_inventory, ui->subjectsTable));

    connect(_hero, SIGNAL(money_changed(int)), ui->money, SLOT(setValue(int)));
}

ShopWindow::~ShopWindow()
{
    delete ui;
}



ShopModel::ShopModel(QList<std::shared_ptr<Item>> *inventory, QObject *parent)
    : QAbstractTableModel(parent),
      _inventory(inventory)
{

}

int ShopModel::rowCount([[maybe_unused]]const QModelIndex &parent) const
{
    return _inventory->count();
}

int ShopModel::columnCount([[maybe_unused]]const QModelIndex &parent) const
{
    return 2;
}

QVariant ShopModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Продукт");
        case 1:
            return tr("Описание");
        default:
            return QVariant();
        }
    } else {
        return QString("%1").arg(section + 1);
    }
}

QVariant ShopModel::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    switch (index.column()) {
    case 0:
        return (*_inventory)[index.row()]->getName();
    case 1:
        return QString("%1").arg((*_inventory)[index.row()]->getDescription());
    default:
        return QVariant();
    }

    return QVariant();
}

void ShopWindow::on_buy_clicked()
{
    QModelIndex currentIndex = ui->subjectsTable->currentIndex();
    if (!currentIndex.isValid())
        return;
    int productIndex = currentIndex.row();
    auto product = _inventory[productIndex];
    if (_hero->changeMoney(-product->getPrice()))
        _hero->addItem(product);
    //this->accept();
}
