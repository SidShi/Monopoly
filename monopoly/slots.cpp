#include "slots.h"
#include "ui_slots.h"

slots::slots(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::slots)
{
    ui->setupUi(this);
}

slots::~slots()
{
delete ui;
}
