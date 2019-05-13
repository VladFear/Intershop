#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

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

public:
    explicit CentralWidget(QWidget *parent = nullptr);
    virtual ~CentralWidget();

signals:

public slots:
};

#endif // CENTRALWIDGET_H
