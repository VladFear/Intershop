#include "centralwidget.h"
#include "ui_centralwidget.h"

void CentralWidget::createInterior()
{

}

void CentralWidget::initSlots()
{
    connect(ui->huaweiImage, SIGNAL(clicked()), this, SLOT(huaweiImageClicked()));
    connect(ui->miImage, SIGNAL(clicked()), this, SLOT(xiaomiImageClicked()));
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
    ui->stackedWidget->setCurrentIndex(2);
//    QSqlQuery query(db);
//    query.prepare("INSERT INTO customer (firstname, lastname, email, phone, login, password) VALUES (:firstname, :lastname, :email, :phone, :login, :password)");
//    query.bindValue(":firstname", firstnameLine->text());
//    query.bindValue(":lastname", lastnameLine->text());
//    query.bindValue(":email", emailLine->text());
//    query.bindValue(":phone", mobileLine->text());
//    query.bindValue(":login", loginLine->text());
//    query.bindValue(":password", passwordLine->text());
//    query.exec();

    QVBoxLayout* lay = ui->scrollWidg->findChild<QVBoxLayout*>(QString("verticalLayout_6"));

    for (int j = 0; j < 3; j++)
    {
        QLayout* row = new QHBoxLayout;
        for (int i = 0; i < 5; i++)
        {
            Phone* new_ph = new Phone(this);
            new_ph->getImage()->setPixmap(QPixmap("/home/vlad/Programming/Qt Projects/Intershop/pictures/Huawei/huawei_2.jpg"));
            row->addWidget(new_ph);
        }
        lay->addLayout(row);
    }
}

void CentralWidget::xiaomiImageClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
