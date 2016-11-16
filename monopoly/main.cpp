#include "monopoly.h"
#include "gameslot.h"
#include <QApplication>
#include <QRect>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    gameslot t1;
    t1.setName("Mi");
    t1.setSlot(10,10);
    t1.show();


    QVector<gameslot> board = new QVector<gameslot>[40];
    for (int i = 0; i < 40; i++)
    {
        board[i].setNum(i+1);
        if (i < 10)
        {
            board[i].setSlot(1000-100*i,-1000);
        }
        else if (i < 20)
        {
            board[i].setSlot(0,-1000+100*(i-10));
        }
        else if (i < 30)
        {
            board[i].setSlot(100*(i-20),0);
        }
        else
        {
            board[i].setSlot(1000,-100*(i-30));
        }
    }
    board[0].setName("GO");
    board[1].setName("Mediterranean Avenue");
    board[1].setPrice(60);
    board[1].setBuild(50);
    board[1].setUpgrade();
    board[2].setName("Community Chest");
    board[3].setName("Baltic Avenue");
    board[3].setPrice(60);
    board[3].setBuild(50);
    board[3].setUpgrade();
    board[4].setName("Income Tax");
    board[5].setName("Reading Railroad");
    board[5].setPrice(200);
    board[6].setName("Oriental Avenue");
    board[6].setPrice(100);
    board[6].setBuild(50);
    board[6].setUpgrade();
    board[7].setName("Chance");
    board[8].setName("Vermont Avenue");
    board[8].setPrice(100);
    board[8].setBuild(50);
    board[8].setUpgrade();
    board[9].setName("Connecticut Avenue");
    board[9].setPrice(120);
    board[9].setBuild(50);
    board[9].setUpgrade();
    board[10].setName("In Jail/Just Visiting");
    board[11].setName("St.Charles Place");
    board[11].setPrice(140);
    board[11].setBuild(100);
    board[11].setUpgrade();
    board[12].setName("Electric Company");
    board[12].setPrice(150);
    board[13].setName("States Avenue");
    board[13].setPrice(140);
    board[13].setBuild(100);
    board[13].setUpgrade();
    board[14].setName("Virginia Avenue");
    board[14].setPrice(160);
    board[14].setBuild(100);
    board[14].setUpgrade();
    board[15].setName("Pennsylvania Railroad");
    board[15].setPrice(200);
    board[16].setName("St.James Place");
    board[16].setPrice(180);
    board[16].setBuild(100);
    board[16].setUpgrade();
    board[17].setName("Community Chest");
    board[18].setName("Tennessee Avenue");
    board[18].setPrice(180);
    board[18].setBuild(100);
    board[18].setUpgrade();
    board[19].setName("New York Avenue");
    board[19].setPrice(200);
    board[19].setBuild(100);
    board[19].setUpgrade();
    board[20].setName("Free Parking");
    board[21].setName("Kentucky Avenue");
    board[21].setPrice(220);
    board[21].setBuild(150);
    board[21].setUpgrade();
    board[22].setName("Chance");
    board[23].setName("Indiana Avenue");
    board[23].setPrice(220);
    board[23].setBuild(150);
    board[23].setUpgrade();
    board[24].setName("Illiois Avenue");
    board[24].setPrice(240);
    board[24].setBuild(150);
    board[24].setUpgrade();
    board[25].setName("B&O Railroad");
    board[25].setPrice(200);
    board[26].setName("Atlantic Avenue");
    board[26].setPrice(260);
    board[26].setBuild(150);
    board[26].setUpgrade();
    board[27].setName("Ventnor Avenue");
    board[27].setPrice(260);
    board[27].setBuild(150);
    board[27].setUpgrade();
    board[28].setName("Water Works");
    board[28].setPrice(150);
    board[29].setName("Marvin Gardens");
    board[29].setPrice(280);
    board[29].setBuild(150);
    board[29].setUpgrade();
    board[30].setName("Go To Jail");
    board[31].setName("Pacific Avenue");
    board[31].setPrice(300);
    board[31].setBuild(200);
    board[31].setUpgrade();
    board[32].setName("North Carolina Avenue");
    board[32].setPrice(300);
    board[32].setBuild(200);
    board[32].setUpgrade();
    board[33].setName("Community Chest");
    board[34].setName("Pennsylvania Avenue");
    board[34].setPrice(320);
    board[34].setBuild(200);
    board[34].setUpgrade();
    board[35].setName("Short Line");
    board[35].setPrice(200);
    board[36].setName("Chance");
    board[37].setName("Park Place");
    board[37].setPrice(350);
    board[37].setBuild(200);
    board[37].setUpgrade();
    board[38].setName("Luxury Tax");
    board[39].setName("Broadwalk");
    board[39].setPrice(400);
    board[39].setBuild(200);
    board[39].setUpgrade();







    return a.exec();
}
