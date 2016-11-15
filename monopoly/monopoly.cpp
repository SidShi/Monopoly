#include "monopoly.h"
#include "ui_monopoly.h"
#include "gameslot.h"

monopoly::monopoly(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::monopoly)
{
    ui->setupUi(this);
}

monopoly::~monopoly()
{
    delete ui;
}

