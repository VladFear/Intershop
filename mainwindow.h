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
#include "clickablelabel.h"

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QWidget* header_widget;
    CentralWidget* central_widget;
    QLabel* number_lbl;
    QLabel* popular;
    QLabel* welcome;
    QLineEdit* search_line;
    QPushButton* search_but;
    QPushButton* login_but;
    QPushButton* register_but;
    ClickableLabel* intershopLabel;
    QSqlDatabase db;
    int user;

private:
    void createInterior();
    void initSlots();

private slots:
    void loginClickedSlt();
    void registerClickedSlt();
    void searchButClickedSlt();
    void intershopImageClickedSlt();

signals:
    void searchButClicked(QString str);
    void intershopImageClicked();

public:
    explicit MainWindow(QWidget* parent = 0);
};

#endif // MAINWINDOW_H
