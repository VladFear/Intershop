#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QScrollArea>
#include <QMessageBox>
#include <QDebug>

#include "phone.h"
#include "clickablelabel.h"
#include "phone.h"

namespace Ui {
    class CentralWidget;
}

class CentralWidget : public QWidget
{
    Q_OBJECT
private:
    QLabel* phones;
    QStackedWidget* stackedWidget;
    Ui::CentralWidget *ui;

private:
    void createInterior();
    void initSlots();
    void clearLayout(QLayout* layout, bool deleteWidgets = true);

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    virtual ~CentralWidget();

signals:

private slots:
    void displayBrandPhones(QString);

public slots:
    void searchButClicked(QString str);
    void intershopImageClicked();

public slots:
};

#endif // CENTRALWIDGET_H
