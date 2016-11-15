#include "gameslot.h"
#include "ui_gameslot.h"
#include <QString>
#include <QRect>
#include <QPainter>
#include <QVector>

gameslot::gameslot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::gameslot)
{
    ui->setupUi(this);
    slot(0,0,200,200);
    name = "default";
    owner_name = "bank";
}

gameslot::~gameslot()
{
    delete ui;
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
    slot(x,y,200,200);
    return;
}

void gameslot::setName(QString s)
{
    name = s;
    return;
}

void gameslot::setOwner(QString user)
{
    owner_name = user;
    return;
}

void gameslot::setPrice(int p)
{
    land_price = p;
    return;
}

QString gameslot::getName()
{
    return name;
}

QString gameslot::getOwner()
{
    return owner_name;
}

int gameslot::getPrice()
{
    return land_price;
}

QVector<int> gameslot::getCoord()
{
    QVector<int> result;
    result.push_back(slot.x());
    result.push_back(slot.y());
    return result;
}
