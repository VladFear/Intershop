#include "phone.h"
#include "ui_phone.h"

Phone::Phone(QWidget *parent) : QWidget(parent), ui(new Ui::Phone)
{
    ui->setupUi(this);
    ui->image->setFixedSize(237, 332);
    //    ui->model->setFixedSize();
}

Phone::~Phone()
{
    delete ui;
}

ClickableLabel *Phone::getImage()
{
    return ui->image;
}

ClickableLabel *Phone::getModel()
{
    return ui->model;
}
