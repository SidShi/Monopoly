#include "gameslot.h"
#include "ui_gameslot.h"
#include "player.h"
#include <QString>
#include <QRect>
#include <QPainter>
#include <QVector>

gameslot::gameslot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameslot)
{
    ui->setupUi(this);
    slot.setRect(0,0,200,200);
    name = "default";
    owner = new Player;
    houselevel = 0;
    land_price = 0;
    paid_price = 0;
    slot_no = 0;
    upgradable = false;
    buildHouse = 0;
}

gameslot::gameslot(const gameslot& b)
{
    slot.setRect(b.slot.x(),b.slot.y(),b.slot.width(),b.slot.height());
    name = b.name;
    houselevel = b.houselevel;
    land_price = b.land_price;
    paid_price = b.paid_price;
    slot_no = b.slot_no;
    upgradable = b.upgradable;
    buildHouse = b.buildHouse;
    if (b.owner == NULL)
    {
        owner = NULL;
    }
    else
    {
        if (owner != NULL)
        {
            delete owner;
        }
        owner = new Player(*b.owner);
    }
}

gameslot::~gameslot()
{
    delete ui;
    delete owner;
}

void gameslot::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setBrush( QBrush(Qt::blue) );

    painter.drawRect(slot);

    return;
}

void gameslot::setSlot(int x, int y)
{
    slot.setRect(x,y,200,200);
    return;
}

void gameslot::setName(QString s)
{
    name = s;
    return;
}

void gameslot::setOwner(Player* user)
{
    owner = user;
    return;
}

void gameslot::setPrice(int p)
{
    land_price = p;
    return;
}

void gameslot::setNum(int n)
{
    slot_no = n;
    return;
}

void gameslot::setPaidPrice(int p)
{
    paid_price = p;
    return;
}

void gameslot::setUpgrade()
{
    upgradable = true;
}

void gameslot::setHouse()
{
    houselevel += 1;
    return;
}

void gameslot::setBuild(int b)
{
    buildHouse = b;
    return;
}

QString gameslot::getName()
{
    return name;
}

Player* gameslot::getOwner()
{
    return owner;
}

int gameslot::getPrice()
{
    return land_price;
}

int gameslot::getPaidPrice()
{
    return paid_price;
}

QVector<int> gameslot::getCoord()
{
    QVector<int> result;
    result.push_back(slot.x());
    result.push_back(slot.y());
    return result;
}

int gameslot::getSlot()
{
    return slot_no;
}

bool gameslot::getUpgrade()
{
    return upgradable;
}

int gameslot::getHouse()
{
    return houselevel;
}

int gameslot::getBuild()
{
    return buildHouse;
}
