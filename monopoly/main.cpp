#include "monopoly.h"
#include "gameslot.h"
#include <QApplication>
#include <QRect>
#include <QVector>
#include <QBoxLayout>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Player bank;
    bank.setName("bank");
    bank.money_change(15000);

    QVector<gameslot> board(40);
    for (int i = 0; i < 40; i++)
    {
        board[i].setNum(i+1);
        board[i].setOwner(&bank);
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



    QVector<chance*> cha(18);
    for (int i = 0; i < 18; i++)
    {
        cha[i] = new chance;
    }
    cha[0]->setChance("Advance to GO. Collect $200");
    cha[0]->setPositionC(&board[0]);
    cha[1]->setChance("Advance to Illinois Avenue");
    cha[1]->setPositionC(&board[24]);
    cha[2]->setChance("Advance to Electricity Company. If owned, pay ten times of a dice throw");
    cha[2]->setPositionC(&board[12]);
    cha[3]->setChance("Advance to Water Works. If owned, pay ten times of a dice throw");
    cha[3]->setPositionC(&board[28]);
    cha[4]->setChance("Advance to Reading Railroad. If owned, pay twice");
    cha[4]->setPositionC(&board[5]);
    cha[5]->setChance("Advance to Pennsylvania Railroad. If owned, pay twice");
    cha[5]->setPositionC(&board[15]);
    cha[6]->setChance("Advance to B&O Railroad. If owned, pay twice");
    cha[6]->setPositionC(&board[25]);
    cha[7]->setChance("Advance to Short Line. If owned, pay twice");
    cha[7]->setPositionC(&board[35]);
    cha[8]->setChance("Advance to St. Charles Place. Collect 200$ if passing GO");
    cha[8]->setPositionC(&board[11]);
    cha[9]->setChance("Stay where you are");
    cha[10]->setChance("Go directly to Jail");
    cha[10]->setPositionC(&board[10]);
    cha[11]->setChance("Take a walk on the Broadwalk");
    cha[11]->setPositionC(&board[39]);
    cha[12]->setChance("Bank pays you dividend of $50");
    cha[12]->setMoneyC(50);
    cha[13]->setChance("Make general repairs on all your property");
    cha[14]->setChance("You have been elected chairman of the board - pay $50");
    cha[14]->setMoneyC(-50);
    cha[15]->setChance("Your building loan matures - collect $150");
    cha[15]->setMoneyC(150);
    cha[16]->setChance("You have won a crossword competition - collect $100");
    cha[16]->setMoneyC(100);
    cha[17]->setChance("Get out of jail free card");


    QVector<chance*> com(17);
    for (int i = 0; i < 17; i++)
    {
        com[i] = new chance;
    }
    com[0]->setChance("Advance to GO. Collect $200");
    com[0]->setPositionC(&board[0]);
    com[1]->setChance("Go to Jail");
    com[1]->setPositionC(&board[10]);
    com[2]->setChance("Bank error in your favor. Collect $75");
    com[2]->setMoneyC(75);
    com[3]->setChance("Doctor's fees. Pay $50");
    com[3]->setMoneyC(-50);
    com[4]->setChance("It is your birthday. Collect $10");
    com[4]->setMoneyC(10);
    com[5]->setChance("Grand Opera Night. Collect $50");
    com[5]->setMoneyC(50);
    com[6]->setChance("Income Tax refund. Collect $20");
    com[6]->setMoneyC(20);
    com[7]->setChance("Life Insurance Matures. Collect $100");
    com[7]->setMoneyC(100);
    com[8]->setChance("Pay Hospital Fees of $100");
    com[8]->setMoneyC(-100);
    com[9]->setChance("Pay School Fees of $50");
    com[9]->setMoneyC(-50);
    com[10]->setChance("Receive $25 Consultancy Fee");
    com[10]->setMoneyC(25);
    com[11]->setChance("You are assessed for street repairs");
    com[12]->setChance("You have won second prize in a beauty contest - collect $10");
    com[12]->setMoneyC(10);
    com[13]->setChance("You inherit $100");
    com[13]->setMoneyC(100);
    com[14]->setChance("From sale of stock you get $50");
    com[14]->setMoneyC(50);
    com[15]->setChance("Holiday Fund matures - receive $100");
    com[15]->setMoneyC(100);
    com[16]->setChance("Get Out of Jail Free Card");

    /*
    qsrand(1);
    int xxx = qrand()%6+1;
    int yyy = qrand()%6+1;
    qDebug() << xxx << yyy;
    xxx = qrand()%6+1;
    yyy = qrand()%6+1;
    qDebug() << xxx << yyy;
    xxx = qrand()%6+1;
    yyy = qrand()%6+1;
    qDebug() << xxx << yyy;
    */
    /*
    qsrand(13);
    int xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(14);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(15);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(16);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(11);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(12);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(17);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(18);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(19);
    xxx = qrand()%18;
    qDebug() << xxx;
    qsrand(20);
    xxx = qrand()%18;
    qDebug() << xxx;


    qsrand(11);
    int xxx = qrand()%18;
    int yyy = qrand()%6+1;
    qDebug() << xxx << yyy;
    */


    /*
    Player user1;
    user1.setName("user1");
    // Test if landing position is correct and rolling counter is correct
    qsrand(1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 13 && user1.getRollingC() == 1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 23 && user1.getRollingC() == 2);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 34 && user1.getRollingC() == 0);
    // subcase: when rolling counter adds up to 3, if the player goes to jail
    user1.move_Player(1);
    qsrand(1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 13 && user1.getRollingC() == 1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 23 && user1.getRollingC() == 2);
    qsrand(1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 11 && user1.getRollingC() == 3 && user1.getPrisonC() == 0);
    // subcase: when Player goes around the board, get at the right position
    user1.move_Player(38);
    user1.setJailC(0);
    qsrand(1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 10);
    user1.move_Player(28);
    qsrand(1);
    user1.rolling_dice();
    Q_ASSERT(user1.getSl() == 40);
    */


    /*
    Player user2;
    user2.setName("user2");
    // test in jail conditions
    user2.move_Player(11);
    // subcase: cannot get out by rolling different numbers
    qsrand(2);
    user2.in_jail();
    Q_ASSERT(user2.getSl() == 11 && user2.getPrisonC() == 1 && user2.getRollingC() == 0);
    // subcase: get out by rolling same numbers
    qsrand(1);
    user2.in_jail();
    Q_ASSERT(user2.getSl() == 23 && user2.getPrisonC() == 0);
    // subcase: get out with a card
    user2.move_Player(11);
    user2.setJailC(0);
    user2.setJailCard();
    qsrand(2);
    user2.in_jail();
    Q_ASSERT(user2.getSl() == 18 && user2.getPrisonC() == 0 && user2.getJailCard() == false);
    // subcase: get out by waiting till the third round
    user2.move_Player(11);
    user2.setJailC(0);
    qsrand(2);
    user2.in_jail();
    qsrand(2);
    user2.in_jail();
    qsrand(2);
    user2.in_jail();
    Q_ASSERT(user2.getSl() == 18 && user2.getPrisonC() == 0);
    */



    /*
    Player user3;
    user3.setName("user3");
    // test purchasing
    // subcase: purchase railroad
    user3.land_purchase(board[5]);
    Q_ASSERT(user3.getMoney() == 1300 && user3.getRail() == 1 && board[5].getOwner()->getPlayer() == "user3" && board[5].getPaidPrice() == 25);
    // subcase: another railroad purchased
    user3.land_purchase(board[35]);
    Q_ASSERT(user3.getMoney() == 1100 && user3.getRail() == 2 && board[35].getOwner()->getPlayer() == "user3" && board[35].getPaidPrice() == 50 && board[5].getPaidPrice() == 50);
    // subcase: purchase one utility
    user3.land_purchase(board[12]);
    Q_ASSERT(user3.getMoney() == 950 && user3.getUtil() == 1 && board[12].getOwner()->getPlayer() == "user3" && board[12].getPaidPrice() == 4);
    // subcase: purchase another utility
    user3.land_purchase(board[28]);
    Q_ASSERT(user3.getMoney() == 800 && user3.getUtil() == 2 && board[28].getOwner()->getPlayer() == "user3" && board[28].getPaidPrice() == 10 && board[12].getPaidPrice() == 10);
    // subcase: purchase one household
    user3.land_purchase(board[3]);
    Q_ASSERT(user3.getMoney() == 740 && user3.getLand().length() == 1 && board[3].getOwner()->getPlayer() == "user3" && board[3].getPaidPrice() == 20);
    // subcase: purchase another household
    user3.land_purchase(board[39]);
    Q_ASSERT(user3.getMoney() == 340 && user3.getLand().length() == 2 && board[39].getOwner()->getPlayer() == "user3" && board[39].getPaidPrice() == 133);
    */


    /*
    Player user4;
    Player user5;
    user4.setName("user4");
    user5.setName("user5");
    // test landing options
    // whether the player receives 200 when going past GO in most cases
    user4.landing_option(board[31],board[0],com,cha);
    user5.landing_option(board[38],board[10],com,cha);
    Q_ASSERT(user4.getMoney() == 1700 && user5.getMoney() == 1700);
    user4.money_change(-200);
    user5.money_change(-200);
    // if lands on "GO TO JAIL"
    user4.landing_option(board[28],board[30],com,cha);
    Q_ASSERT(user4.getSl() == 11);
    // if go to the jail grid from general slots
    user5.landing_option(board[8],board[10],com,cha);
    Q_ASSERT(user5.getPrisonC() == 0);
    // if go to a place that nobody owns
    user4.landing_option(board[0],board[3],com,cha);
    user4.landing_option(board[3],board[5],com,cha);
    user4.landing_option(board[5],board[12],com,cha);
    Q_ASSERT(user4.getMoney() == 1090);
    // if go to a place self-owned and can be upgraded
    user4.landing_option(board[0],board[3],com,cha);
    Q_ASSERT(user4.getMoney() == 1040 && board[3].getHouse() == 1 && board[3].getPaidPrice() == 30);
    user4.landing_option(board[0],board[3],com,cha);
    Q_ASSERT(user4.getMoney() == 990 && board[3].getHouse() == 2 && board[3].getPaidPrice() == 45);
    // if go to a place owned by others
    user5.landing_option(board[0],board[3],com,cha);
    Q_ASSERT(user5.getMoney() == 1455 && user4.getMoney() == 1035);
    user5.landing_option(board[5],board[12],com,cha);
    Q_ASSERT(user5.getMoney() == 1427 && user4.getMoney() == 1063);

    // testing landing options and cards
    Player user6;
    user6.setName("user6");
    // Move cards
    qsrand(4);
    user6.landing_option(board[0],board[2],com,cha);
    Q_ASSERT(user6.getMoney() == 1700 && user6.getSl() == 1);
    // Special money cards
    qsrand(2);
    user4.landing_option(board[0],board[2],com,cha);
    Q_ASSERT(user4.getMoney() == 983);
    // General money cards
    qsrand(3);
    user6.landing_option(board[0],board[2],com,cha);
    Q_ASSERT(user6.getMoney() == 1750);
    // Move to utility held by others
    qsrand(11);
    user6.landing_option(board[0],board[7],com,cha);
    Q_ASSERT(user6.getMoney() == 1740 && user4.getMoney() == 993);
    */





    // make sure how many players are there
    QVector<Player> pla;
    int min_mon;
    min_mon = pla[1].getMoney();
    for (int i = 1; i < pla.length(); i++)
    {
        if (pla[i].getMoney() < min_mon)
        {
            min_mon = pla[i].getMoney();
        }
    }
    while (min_mon > 0)
    {
        for (int i = 0; i < pla.length(); i++)
        {
            int prev = pla[i].getSl();
            pla[i].rolling_dice();
            pla[i].landing_option(board[prev-1],board[pla[i].getSl()-1]);
            while (pla[i].getRollingC() > 0)
            {
                int prev1 = pla[i].getSl();
                pla[i].rolling_dice();
                pla[i].landing_option(board[prev1-1],board[pla[i].getSl()-1]);
            }
        }
        min_mon = pla[1].getMoney();
        for (int i = 1; i < pla.length(); i++)
        {
            if (pla[i].getMoney() < min_mon)
            {
                min_mon = pla[i].getMoney();
            }
        }
    }


    return a.exec();
}
