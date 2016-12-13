#ifndef CHANCE_H
#define CHANCE_H

#include <QWidget>
#include <QString>
#include "gameslot.h"

namespace Ui {
class chance;
}

class gameslot;
class Player;

class chance : public QWidget
{
    Q_OBJECT

public:
    explicit chance(QWidget *parent = 0);
    chance(const chance& b);
    ~chance();

    // setters
    void setChance(QString s);
    void setMoneyC(int m);
    void setPositionC(gameslot* p);

    // getters
    QString getChance();
    int getMoneyC();
    gameslot* getPositionC();

private:
    Ui::chance *ui;
    QString chance_name;
    // Money changes associated with the cards
    int money_change;
    // Destinations where the cards will move the players to
    gameslot* position_numC;
};

#endif // CHANCE_H
