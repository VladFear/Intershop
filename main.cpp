#include "mainwindow.h"

#include <QApplication>
#include <QDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* wnd = new MainWindow();
    wnd->show();

    return a.exec();
}
