#include "player.h"
#include "ui_player.h"
#include "gameslot.h"
#include "chance.h"
#include <QPainter>
#include <QRect>
#include <QtCore>

Player::Player(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Player)
{
    ui->setupUi(this);
    x_coord = 1050;
    y_coord = -1050;
    money = 1500;
    player_name = "bank";
    rolling_counter = 0;
    prison_counter = 0;
    jail_card = false;
    sl_no = 1;
    rail = 0;
    util = 0;
}

Player::Player(const Player& b)
{
    x_coord = b.x_coord;
    y_coord = b.y_coord;
    money = b.money;
    player_name = b.player_name;
    rolling_counter = b.rolling_counter;
    prison_counter = b.prison_counter;
    jail_card = b.jail_card;
    sl_no = b.sl_no;
    rail = b.rail;
    util = b.util;
    land = b.land;
    railroad = b.railroad;
    utility = b.utility;
}

Player::~Player()
{
    delete ui;
}

void Player::setName(QString a)
{
    player_name = a;
    return;
}

void Player::setJailC(int a)
{
    prison_counter = a;
    return;
}

void Player::setJailCard()
{
    jail_card = true;
    return;
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
    l.setOwner(this);
    money_change(-l.getPrice());
    if (l.getSlot()%10 == 6)
    {
        railroad.push_back(&l);
        rail += 1;
        for (int i = 0; i < rail; i++)
        {
            railroad[i]->setPaidPrice(25*qPow(2,rail-1));
        }
        return;
    }
    if (l.getSlot() == 13 || l.getSlot() == 29)
    {
        utility.push_back(&l);
        util += 1;
        if (util == 1)
        {
            utility[0]->setPaidPrice(4);
        }
        else
        {
            utility[0]->setPaidPrice(10);
            utility[1]->setPaidPrice(10);
        }
        return;
    }
    land.push_back(&l);
    int te = l.getPrice()/3;
    l.setPaidPrice(te);
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

int Player::getSl()
{
    return sl_no;
}

bool Player::getJailCard()
{
    return jail_card;
}

QVector<gameslot*> Player::getLand()
{
    return land;
}

QVector<gameslot*> Player::getRailroad()
{
    return railroad;
}

QVector<gameslot*> Player::getUtility()
{
    return utility;
}

void Player::rolling_dice()
{
    if (prison_counter > 0)
    {
        return;
    }
    // make a button to roll the dice
    int r1 = qrand() % 6 + 1;
    int r2 = qrand() % 6 + 1;
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
    }
    else
    {
        int move = r1+r2;
        int des = (sl_no+move)%40;
        if (des == 0)
        {
            des = 40;
        }
        move_Player(des);
    }
    return;
}

void Player::in_jail()
{
    rolling_counter = 0;
    int r1 = qrand() % 6 + 1;
    int r2 = qrand() % 6 + 1;
    if (r1 == r2 || jail_card == true || prison_counter == 2)
    {
        int move = r1+r2;
        int des = (sl_no+move)%40;
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

void Player::landing_option(gameslot& f, gameslot& l, QVector<chance *> com, QVector<chance *> cha)
{
    if (((f.getSlot() > l.getSlot()) && l.getSlot() != 11) || (f.getSlot() > 38 && l.getSlot() == 11))
    {
        money_change(200);
    }
    if (l.getSlot() == 1 || l.getSlot() == 21)
    {
        return;
    }
    if (l.getSlot() == 31)
    {
        move_Player(11);
        return;
    }
    if (l.getSlot() == 11 && (f.getSlot() == 11 || f.getSlot() == 31 || f.getSlot() == 3 || f.getSlot() == 8 || f.getSlot() == 18 || f.getSlot() == 23 || f.getSlot() == 34 || f.getSlot() == 37 || rolling_counter == 3))
    {
        in_jail();
        return;
    }
    else if (l.getSlot() == 11)
    {
        return;
    }
    if (l.getPrice() != 0)
    {
        if (l.getOwner()->getPlayer() == "bank")
        {
            if (money >= l.getPrice())
            {
                // make a pop-up window with option whether to purchase
                // if yes
                land_purchase(l);
            }
            return;
        }
        else if (l.getOwner()->getPlayer() == player_name)
        {
            if (l.getUpgrade())
            {
                if (money >= l.getBuild())
                {
                    // ask whether the player wants to build one more house
                    //if yes
                    l.setHouse();
                    l.setPaidPrice(l.getPaidPrice()*1.5);
                    money_change(-l.getBuild());
                }
            }
            return;
        }
        else
        {
            if (l.getSlot() != 13 && l.getSlot() != 29)
            {
                l.getOwner()->money_change(l.getPaidPrice());
                money_change(-l.getPaidPrice());
            }
            else
            {
                int t = qAbs(l.getSlot()-f.getSlot())*l.getPaidPrice();
                l.getOwner()->money_change(t);
                money_change(-t);
            }
            return;
        }
    }
    else
    {
        if (l.getSlot() == 5)
        {
            money_change(-200);
            return;
        }
        else if (l.getSlot() == 39)
        {
            money_change(-100);
            return;
        }
        else if (l.getSlot() == 3 || l.getSlot() == 18 || l.getSlot() == 34)
        {
            int r = qrand()%17;
            chance* c1 = com[r];
            if (r == 0 || r == 1)
            {
                move_Player(c1->getPositionC()->getSlot());
                landing_option(l,*(c1->getPositionC()),com,cha);

                return;
            }
            else if (r == 11)
            {
                int s = 0;
                int h = 0;
                for (int i = 0; i < getLand().length(); i++)
                {
                    if ((getLand()[i])->getHouse() == 4)
                    {
                        h++;
                    }
                    else
                    {
                        s += (getLand()[i])->getHouse();
                    }
                }
                money_change(-s*40-115*h);

                return;
            }
            else if (r == 16)
            {
                jail_card = true;

                return;
            }
            else
            {
                money_change(c1->getMoneyC());

                return;
            }
        }
        else
        {
            int z = qrand()%18;
            chance* c2 = cha[z];
            if (z == 0 || z == 1 || z == 8 || z == 11 || (z >= 4 && z <= 7) || z == 10)
            {
                move_Player(c2->getPositionC()->getSlot());
                landing_option(l,*(c2->getPositionC()),com,cha);

                return;
            }
            else if (z == 2 || z == 3)
            {
                move_Player(c2->getPositionC()->getSlot());
                if (c2->getPositionC()->getOwner()->getPlayer() == "bank")
                {
                    if (money >= c2->getPositionC()->getPrice())
                    {
                        // ask if buy
                        land_purchase(*(c2->getPositionC()));

                        return;
                    }
                }
                else if (c2->getPositionC()->getOwner()->getPlayer() == player_name)
                {

                    return;
                }
                else
                {
                    // roll one die
                    int d = qrand()%6+1;
                    money_change(-10*d);
                    c2->getPositionC()->getOwner()->money_change(10*d);

                    return;
                }
            }
            else if (z == 9)
            {

                return;
            }
            else if (z == 13)
            {
                int s = 0;
                int h = 0;
                for (int i = 0; i < getLand().length(); i++)
                {
                    if ((getLand()[i])->getHouse() == 4)
                    {
                        h++;
                    }
                    else
                    {
                        s += (getLand()[i])->getHouse();
                    }
                }
                money_change(-s*25-100*h);

                return;
            }
            else if (z == 17)
            {
                jail_card = true;

                return;
            }
            else
            {
                money_change(c2->getMoneyC());

                return;
            }
        }
    }
    return;
}
