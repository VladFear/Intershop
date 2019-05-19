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
}

CentralWidget::~CentralWidget()
{
    delete ui;
}

void CentralWidget::huaweiImageClicked()
{
    ui->stackedWidget->setCurrentIndex(3);

    if (QSqlDatabase::database().isOpen())
    {
        QString manufacturer = "Huawei";
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT pr.model, pi.picture_1 FROM product pr inner join picturesTable pi on pr.idPicturesTable = pi.id inner join manufacturer ma on pr.idManufacturer = ma.id where ma.name = :manufact");
        query.bindValue(":manufact", manufacturer);
        query.exec();

        QVBoxLayout* lay = ui->scrollWidg->findChild<QVBoxLayout*>(QString("verticalLayout_6"));
        int i = 0;
        QHBoxLayout* row = new QHBoxLayout;
        while (query.next())
        {
            if (i == 5)
            {
                lay->addLayout(row);
                i = 0;
                row = new QHBoxLayout;
            }

            QString model = query.value(0).toString();
            QString image = query.value(1).toString();
            Phone* new_phone = new Phone(this);
            new_phone->setImage(image);
            new_phone->setModel(model);
            row->addWidget(new_phone);
            i++;
        }

        if (i != 0)
            lay->addLayout(row);
    }
    else
        QMessageBox::information(this, "Not connected", "<font color='black'>Database is not connected</font>");
}

void CentralWidget::xiaomiImageClicked()
{
    ui->stackedWidget->setCurrentIndex(2);

    if (QSqlDatabase::database().isOpen())
    {
        QString manufacturer = "Xiaomi";
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT pr.model, pi.picture_1 FROM product pr inner join picturesTable pi on pr.idPicturesTable = pi.id inner join manufacturer ma on pr.idManufacturer = ma.id where ma.name = :manufact");
        query.bindValue(":manufact", manufacturer);
        query.exec();

        QVBoxLayout* lay = ui->scrollWidg_2->findChild<QVBoxLayout*>(QString("verticalLayout_8"));
        int i = 0;
        QHBoxLayout* row = new QHBoxLayout;
        while (query.next())
        {
            if (i == 5)
            {
                lay->addLayout(row);
                i = 0;
                row = new QHBoxLayout;
            }

            QString model = query.value(0).toString();
            QString image = query.value(1).toString();
            Phone* new_phone = new Phone(this);
            new_phone->setImage(image);
            new_phone->setModel(model);
            row->addWidget(new_phone);
            i++;
        }

        if (i != 0)
            lay->addLayout(row);
    }
    else
        QMessageBox::information(this, "Not connected", "<font color='black'>Database is not connected</font>");
}

void CentralWidget::searchButClicked(QString str)
{
    ui->stackedWidget->setCurrentIndex(0);
}
