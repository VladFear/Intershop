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

void CentralWidget::clearLayout(QLayout *layout, bool deleteWidgets)
{
    while (QLayoutItem* item = layout->takeAt(0))
    {
        if (deleteWidgets)
        {
            if (QWidget* widget = item->widget())
                widget->deleteLater();
        }
        if (QLayout* childLayout = item->layout())
            clearLayout(childLayout, deleteWidgets);
        delete item;
    }
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
    QVBoxLayout* lay = ui->scrollWidg->findChild<QVBoxLayout*>(QString("verticalLayout_6"));
    clearLayout(lay, true);

    if (QSqlDatabase::database().isOpen())
    {
        QString manufacturer = "Huawei";
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT pr.model, pi.picture_1 FROM product pr inner join picturesTable pi on pr.idPicturesTable = pi.id inner join manufacturer ma on pr.idManufacturer = ma.id where ma.name = :manufact");
        query.bindValue(":manufact", manufacturer);
        query.exec();

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
    QVBoxLayout* lay = ui->scrollWidg_2->findChild<QVBoxLayout*>(QString("verticalLayout_8"));
    clearLayout(lay, true);

    if (QSqlDatabase::database().isOpen())
    {
        QString manufacturer = "Xiaomi";
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT pr.model, pi.picture_1 FROM product pr inner join picturesTable pi on pr.idPicturesTable = pi.id inner join manufacturer ma on pr.idManufacturer = ma.id where ma.name = :manufact");
        query.bindValue(":manufact", manufacturer);
        query.exec();

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

void CentralWidget::intershopImageClicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void CentralWidget::searchButClicked(QString str)
{
    ui->stackedWidget->setCurrentIndex(0);
    QVBoxLayout* lay = ui->scrollAreaWidgetContents->findChild<QVBoxLayout*>(QString("verticalLayout_9"));
    clearLayout(lay, true);

    if (QSqlDatabase::database().isOpen())
    {
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT p.model, pt.picture_1 FROM product p inner join picturesTable pt on p.idPicturesTable = pt.id WHERE p.model LIKE :str");
        query.bindValue(":str", QString("%%1%").arg(str));
        query.exec();

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
