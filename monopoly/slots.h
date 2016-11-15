#ifndef SLOTS_H
#define SLOTS_H

#include <QMainWindow>

namespace Ui {
class slots;
}

class slots : public QMainWindow
{
    Q_OBJECT

public:
    explicit slots(QWidget *parent = 0);
    ~slots();

private:
    Ui::slots *ui;
};

#endif // SLOTS_H
