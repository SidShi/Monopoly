#ifndef GAMESLOT_H
#define GAMESLOT_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QRect>
#include "player.h"
#include "chance.h"

namespace Ui {
class gameslot;
}

class Player;
class chance;

class gameslot : public QWidget
{
    Q_OBJECT

public:
    explicit gameslot(QWidget *parent = 0);
    gameslot(const gameslot& b);
    ~gameslot();

    void paintEvent (QPaintEvent *e);

    // setters
    void setSlot(int x, int y);
    void setName(QString s);
    void setOwner(Player* user);
    void setPrice(int p);
    void setNum(int n);
    void setPaidPrice(int p);
    void setUpgrade();
    void setHouse();
    void setBuild(int b);

    // getters
    QString getName();
    Player* getOwner();
    int getPrice();
    QVector<int> getCoord();
    int getPaidPrice();
    int getSlot();
    bool getUpgrade();
    int getHouse();
    int getBuild();

private:
    Ui::gameslot *ui;
    QString name;
    QRect slot;
    Player* owner;
    // land purchasing price
    int land_price;
    // when owned, money other players need to pay to the owner
    int paid_price;
    // number of houses on the property
    int houselevel;
    // associated with the board
    int slot_no;
    // whether the land can build houses
    bool upgradable;
    // money for building a house
    int buildHouse;
};

#endif // GAMESLOT_H
