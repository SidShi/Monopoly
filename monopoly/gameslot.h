#ifndef GAMESLOT_H
#define GAMESLOT_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QRect>
#include "player.h"

namespace Ui {
class gameslot;
}

class gameslot : public QWidget
{
    Q_OBJECT

public:
    explicit gameslot(QWidget *parent = 0);
    ~gameslot();

    void paintEvent (QPaintEvent *e);

    void setSlot(int x, int y);
    void setName(QString s);
    void setOwner(Player user);
    void setPrice(int p);
    void setNum(int n);
    void setPaidPrice(int p);
    void setUpgrade();
    void setHouse();
    void setBuild(int b);

    QString getName();
    Player getOwner();
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
    Player owner;
    int land_price;
    int paid_price;
    int houselevel;
    int slot_no;
    bool upgradable;
    int buildHouse;
};

#endif // GAMESLOT_H
