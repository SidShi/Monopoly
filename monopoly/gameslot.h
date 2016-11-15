#ifndef GAMESLOT_H
#define GAMESLOT_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QRect>

namespace Ui {
class gameslot;
}

class gameslot : public QWidget
{
    Q_OBJECT

public:
    explicit gameslot(QWidget *parent = 0);
    ~gameslot();

    void paintEvent (QPaintEvent *e);

    void setSlot(int x, int y);
    void setName(QString s);
    void setOwner(QString user);
    void setPrice(int p);

    QString getName();
    QString getOwner();
    int getPrice();
    QVector<int> getCoord();

private:
    Ui::gameslot *ui;
    QString name;
    QRect slot;
    QString owner_name;
    int land_price;
};

#endif // GAMESLOT_H
