#ifndef SHOPWINDOW_H
#define SHOPWINDOW_H

#include <QDialog>
#include "hero.h"

namespace Ui {
class ShopWindow;
}


class ShopModel : public QAbstractTableModel
{
  Q_OBJECT

public:
    ShopModel(QList<std::shared_ptr<Item>> *inventory, QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QList<std::shared_ptr<Item>> *_inventory;
};


class ShopWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ShopWindow(Hero *hero, QWidget *parent = nullptr);
    ~ShopWindow();

    Hero *_hero;

private slots:
    void on_buy_clicked();

private:
    Ui::ShopWindow *ui;
    QList<std::shared_ptr<Item>> _inventory;
};

#endif // SHOPWINDOW_H
