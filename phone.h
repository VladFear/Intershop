#ifndef PHONE_H
#define PHONE_H

#include <QObject>
#include <QWidget>
#include "clickablelabel.h"

namespace Ui {
class Phone;
}

class Phone : public QWidget
{
    Q_OBJECT
private:
    Ui::Phone* ui;

public:
    explicit Phone(QWidget *parent = nullptr);
    ~Phone();
    ClickableLabel* getImage();
    ClickableLabel* getModel();

signals:

public slots:
};

#endif // PHONE_H
