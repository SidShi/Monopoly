#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "gameslot.h"
#include "chance.h"

namespace Ui {
class Player;
}

class gameslot;
class chance;

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    Player(const Player& b);
    ~Player();

    // The setters are for debugging and unit testing use
    void setName(QString a);
    void setJailC(int a);
    void setJailCard();


    // Basic activities of players
    void paintEvent (QPaintEvent *e);
    void move_Player(int sl_final);
    void money_change(int c);
    void land_purchase(gameslot& l);
    void rolling_dice();
    void in_jail();
    void landing_option(gameslot &f, gameslot& l, QVector<chance*> com, QVector<chance*> cha);


    // getters
    QString getPlayer();
    int getMoney();
    int getPrisonC();
    int getRollingC();
    bool getJailCard();
    int getRail();
    int getUtil();
    int getSl();
    QVector<gameslot*> getLand();
    QVector<gameslot*> getRailroad();
    QVector<gameslot*> getUtility();



private:
    Ui::Player *ui;
    int x_coord;
    int y_coord;
    int money;
    QString player_name;
    // lists of land and properties owned
    QVector<gameslot*> land;
    QVector<gameslot*> railroad;
    QVector<gameslot*> utility;
    // consecutive number of doubles rolled
    int rolling_counter;
    // number of turns in prison
    int prison_counter;
    // whether own a get out of jail card
    bool jail_card;
    // where the player is right now
    int sl_no;
    // number of railroads owned
    int rail;
    // number of utilities owned
    int util;
};

#endif // PLAYER_H
