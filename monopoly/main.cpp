#include "monopoly.h"
#include "gameslot.h"
#include <QApplication>
#include <QRect>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gameslot t1;
    t1.setName("Mi");
    t1.setSlot(10,10,100,100);
    t1.show();

    return a.exec();
}
