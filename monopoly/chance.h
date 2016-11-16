#ifndef CHANCE_H
#define CHANCE_H

#include <QWidget>
#include <QString>

namespace Ui {
class chance;
}

class chance : public QWidget
{
    Q_OBJECT

public:
    explicit chance(QWidget *parent = 0);
    ~chance();

    void setChance(QString s);
    void setMoneyC(int m);
    void setPositionC(int p);

    QString getChance();
    int getMoneyC();
    int getPositionC();

private:
    Ui::chance *ui;
    QString chance_name;
    int money_change;
    int position_numC;
};

#endif // CHANCE_H
