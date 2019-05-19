#ifndef LOGINFORM_H
#define LOGINFORM_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>

class LoginForm : public QDialog
{
    Q_OBJECT
private:
    QLabel* loginLbl;
    QLabel* passwordLbl;
    QLabel* congrat;
    QLabel* errorLbl;
    QLineEdit* loginLine;
    QLineEdit* passwordLine;
    QPushButton* loginBtn;
    QPushButton* cancelBtn;
    bool visibleLbl;
    static LoginForm* m_pInstance;

private:
    void createInterior();
    void initSlots();
    LoginForm(QWidget* parent = 0, Qt::WindowFlags f = 0);

private slots:
    void loginClickedSlt();
    void cancelClickedSlt();

public:
    static LoginForm* Instance(QWidget* parent = 0, Qt::WindowFlags = 0);
};

#endif // LOGINFORM_H
