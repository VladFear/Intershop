#ifndef PHONE_H
#define PHONE_H

#include <QObject>
#include <QWidget>

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

signals:

public slots:
};

#endif // PHONE_H
