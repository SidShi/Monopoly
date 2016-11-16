#include "chance.h"
#include "ui_chance.h"
#include <QString>

card::chance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::chance)
{
    ui->setupUi(this);
    chance_name = "";
    money_change = 0;
    position_numC = 0;
}

chance::~chance()
{
    delete ui;
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

void chance::setPositionC(int p)
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

int chance::getPositionC()
{
    return position_numC;
}
