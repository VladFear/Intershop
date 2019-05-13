#include "centralwidget.h"
#include "ui_centralwidget.h"

void CentralWidget::createInterior()
{

}

void CentralWidget::initSlots()
{

}

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
    createInterior();
    initSlots();
}

CentralWidget::~CentralWidget()
{
    delete ui;
}
