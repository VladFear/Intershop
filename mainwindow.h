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

class MainWindow : public QWidget
{
    Q_OBJECT
private:
    QWidget* header_widget;
    QWidget* center_widget;
    QLabel* number_lbl;
    QLabel* phones;
    QLineEdit* search_line;
    QPushButton* search_but;
    QPushButton* login_but;
    QPushButton* register_but;

private:
    void createInterior();

public:
    explicit MainWindow(QWidget* parent = 0);
};

#endif // MAINWINDOW_H
