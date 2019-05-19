#include "phone.h"
#include "ui_phone.h"

Phone::Phone(QWidget *parent) : QWidget(parent), ui(new Ui::Phone)
{
    ui->setupUi(this);
    ui->image->setFixedSize(237, 332);
    ui->model->setFixedSize(237, 54);
    ui->model->setStyleSheet(
   "ClickableLabel "
   "{ color: black; }"
   "ClickableLabel::hover"
   "{ color: grey; }");
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

void Phone::setImage(QString& str)
{
    QPixmap p(str);
    int w = ui->image->width();
    int h = ui->image->height();
    ui->image->setPixmap(p.scaled(w,h,Qt::KeepAspectRatio));
}

void* Phone::setModel(QString& str)
{
    ui->model->setText(str);
}
