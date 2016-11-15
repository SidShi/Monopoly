#ifndef MONOPOLY_H
#define MONOPOLY_H

#include <QMainWindow>
#include <QRect>
#include <QString>
#include "gameslot.h"

namespace Ui {
class monopoly;
}

class monopoly : public QMainWindow
{
    Q_OBJECT

public:
    explicit monopoly(QWidget *parent = 0);
    ~monopoly();


private:
    Ui::monopoly *ui;
};

#endif // MONOPOLY_H
