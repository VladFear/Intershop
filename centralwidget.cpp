#include "centralwidget.h"
#include "ui_centralwidget.h"

void CentralWidget::createInterior()
{

}

void CentralWidget::initSlots()
{
    connect(ui->huaweiImage, SIGNAL(clicked()), this, SLOT(huaweiImageClicked()));
}

CentralWidget::CentralWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CentralWidget)
{
    ui->setupUi(this);
    createInterior();
    initSlots();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("intershop");
    db.setHostName("127.0.0.1");
}

CentralWidget::~CentralWidget()
{
    delete ui;
}

void CentralWidget::huaweiImageClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QVBoxLayout* main_layout = new QVBoxLayout;

    QSqlQuery query(db);
//    query.prepare("INSERT INTO customer (firstname, lastname, email, phone, login, password) VALUES (:firstname, :lastname, :email, :phone, :login, :password)");
//    query.bindValue(":firstname", firstnameLine->text());
//    query.bindValue(":lastname", lastnameLine->text());
//    query.bindValue(":email", emailLine->text());
//    query.bindValue(":phone", mobileLine->text());
//    query.bindValue(":login", loginLine->text());
//    query.bindValue(":password", passwordLine->text());
//    query.exec();

    QHBoxLayout* row = new QHBoxLayout;
    db.close();
}
