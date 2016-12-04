#include "chance.h"
#include "ui_chance.h"
#include "gameslot.h"
#include <QString>

chance::chance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chance)
{
    ui->setupUi(this);
    chance_name = "";
    money_change = 0;
    position_numC = new gameslot;
}

chance::chance(const chance& b)
{
    chance_name = b.chance_name;
    money_change = b.money_change;
    if (b.position_numC == NULL)
    {
        position_numC = NULL;
    }
    else
    {
        if (position_numC != NULL)
        {
            delete position_numC;
        }
        position_numC = new gameslot(*(b.position_numC));
    }
}

chance::~chance()
{
    delete ui;
    delete position_numC;
}

void chance::setChance(QString s)
{
    chance_name = s;
    return;
}

void chance::setMoneyC(int m)
{
    money_change = m;
    return;
}

void chance::setPositionC(gameslot* p)
{
    position_numC = p;
    return;
}

QString chance::getChance()
{
    return chance_name;
}

int chance::getMoneyC()
{
    return money_change;
}

gameslot *chance::getPositionC()
{
    return position_numC;
}
