#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QDialog>
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QWidget>
#include <QVBoxLayout>
#include <QSpacerItem>
#include <QStackedWidget>
#include <QDebug>
#include <QCompleter>
#include <QSql>
#include <QMessageBox>

#include "loginform.h"
#include "registerform.h"
#include "centralwidget.h"
#include "phone.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QWidget* header_widget;
    CentralWidget* central_widget;
    QLabel* number_lbl;
    QLabel* popular;
    QLineEdit* search_line;
    QPushButton* search_but;
    QPushButton* login_but;
    QPushButton* register_but;
    QSqlDatabase db;

private:
    void createInterior();
    void initSlots();

private slots:
    void loginClickedSlt();
    void registerClickedSlt();
    void searchButClickedSlt();

signals:
    void searchButClicked(QString str);

public:
    explicit MainWindow(QWidget* parent = 0);
};

#endif // MAINWINDOW_H
