#include "player.h"
#include "ui_player.h"
#include "gameslot.h"
#include "chance.h"
#include <QPainter>
#include <QRect>

Player::Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    x_coord = 1050;
    y_coord = -1050;
    money = 1000;
    player_name = "bank";
    rolling_counter = 0;
    prison_counter = 0;
    jail_card = false;
    sl_no = 1;
    rail = 0;
    util = 0;
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

void Player::move_Player(int sl_final)
{
    sl_no = sl_final;
    if (sl_final <= 10)
    {
        x_coord = 1050-100*(sl_final-1);
        y_coord = -1050;
    }
    else if (sl_final <= 20)
    {
        x_coord = 50;
        y_coord = -1050+100*(sl_final-11);
    }
    else if (sl_final <= 30)
    {
        x_coord = 50+100*(sl_final-21);
        y_coord = -50;
    }
    else
    {
        x_coord = 1050;
        y_coord = -50-100*(sl_final-31);
    }
    return;
}

void Player::money_change(int c)
{
    money += c;
    return;
}

void Player::land_purchase(gameslot& l)
{
    land.push_back(l);
    l.setOwner(*this);
    money_change(-l.getPrice());
    int te = l.getPrice()/3;
    l.setPaidPrice(te);
    if (l.getSlot()%10 == 6)
    {
        rail += 1;
        l.setPaidPrice(25*2^(rail-1));
    }
    if (l.getSlot() == 13 || l.getSlot() == 29)
    {
        util += 1;
        if (util == 1)
        {
            l.setPaidPrice(4);
        }
        else
        {
            l.setPaidPrice(10);
        }
    }
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

int Player::getPrisonC()
{
    return prison_counter;
}

int Player::getRollingC()
{
    return rolling_counter;
}

int Player::getRail()
{
    return rail;
}

int Player::getUtil()
{
    return util;
}

void Player::rolling_dice()
{
    // make a button to roll the dice
    int r1 = qrand() % 6;
    int r2 = qrand() % 6;
    if (r1 == r2)
    {
        rolling_counter += 1;
    }
    else
    {
        rolling_counter = 0;
    }
    if (rolling_counter == 3)
    {
        x_coord = 50;
        y_coord = -1050;
        sl_no = 11;
        rolling_counter = 0;
        prison_counter = 1;
    }
    else
    {
        int move = r1+r2;
        int des = (sl_no+move)%40+1;
        move_Player(des);
    }
    return;
}

void Player::in_jail()
{
    int r1 = qrand() % 6;
    int r2 = qrand() % 6;
    if (r1 == r2 || jail_card == true)
    {
        int move = r1+r2;
        int des = (sl_no+move)%40+1;
        move_Player(des);
        prison_counter = 0;
        jail_card = false;
    }
    else
    {
        prison_counter += 1;
    }
    return;
}

void Player::landing_option(gameslot f, gameslot& l)
{
    if (f.getSlot() > l.getSlot())
    {
        money_change(200);
    }
    if (l.getSlot() == 31)
    {
        move_Player(11);
        return;
    }
    if (l.getSlot() == 11 && (f.getSlot() == 11 || f.getSlot() == 31 || f.getSlot() == 3 || f.getSlot() == 8 || f.getSlot() == 18 || f.getSlot() == 23 || f.getSlot() == 34 || f.getSlot() == 37))
    {
        in_jail();
        return;
    }
    if (l.getPrice() != 0)
    {
        if (l.getOwner().getPlayer() == "bank")
        {
            if (money >= l.getPrice())
            {
                // make a pop-up window with option whether to purchase
                // if yes
                land_purchase(l);
            }
        }
        else if (l.getOwner().getPlayer() == player_name)
        {
            if (l.getUpgrade())
            {
                if (money >= l.getBuild())
                {
                    // ask whether the player wants to build one more house
                    //if yes
                    l.setHouse();
                    l.setPaidPrice(l.getPaidPrice()*2.5);
                    money_change(-l.getBuild());
                }
            }
        }
        else
        {
            if (l.getSlot() != 13 && l.getSlot() != 29)
            {
                l.getOwner().money_change(l.getPaidPrice());
                money_change(-l.getPaidPrice());
            }
            else
            {
                int t = (l.getSlot()-f.getSlot())*l.getPaidPrice();
                l.getOwner().money_change(t);
                money_change(-t);
            }

        }
    }
    else
    {
        // draw cards
    }
}
