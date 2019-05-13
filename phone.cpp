#include "phone.h"
#include "ui_phone.h"

Phone::Phone(QWidget *parent) : QWidget(parent), ui(new Ui::Phone)
{
    ui->setupUi(this);
}
