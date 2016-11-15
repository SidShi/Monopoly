#include "player.h"
#include "ui_player.h"
#include "gameslot.h"
#include <QPainter>
#include <QRect>

Player::Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    x_coord = 1050;
    y_coord = -50;
    money = 1000;
    player_name = "player";
}

Player::~Player()
{
    delete ui;
}

void Player::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush( QBrush(Qt::red) );
    int width = 20;
    int height = 20;
    QRect token(x_coord,y_coord,width,height);
    painter.drawEllipse(token);

    return;
}

void Player::move_Player(int x_final, int y_final)
{
    x_coord = x_final;
    y_coord = y_final;
    return;
}

void Player::money_change(int c)
{
    money += c;
    return;
}

void Player::land_purchase(gameslot l)
{
    land.push_back(l);
    return;
}

int Player::getMoney()
{
    return money;
}

QString Player::getPlayer()
{
    return player_name;
}
