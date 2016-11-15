#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "gameslot.h"

namespace Ui {
class Player;
}

class Player : public QWidget
{
    Q_OBJECT

public:
    explicit Player(QWidget *parent = 0);
    ~Player();
    void paintEvent (QPaintEvent *e);
    void move_Player(int x_final, int y_final);
    void money_change(int c);
    void land_purchase(gameslot l);

    QString getPlayer();
    int getMoney();

private:
    Ui::Player *ui;
    int x_coord;
    int y_coord;
    int money;
    QString player_name;
    QVector<gameslot> land;
};

#endif // PLAYER_H
