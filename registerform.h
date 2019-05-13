#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSql>
#include <QDebug>

class RegisterForm : public QDialog
{
    Q_OBJECT
private:
    QLabel* loginLbl;
    QLabel* passwordLbl;
    QLabel* congrat;
    QLabel* errorLbl;
    QLabel* firstnameLbl;
    QLabel* lastnameLbl;
    QLabel* mobileLbl;
    QLabel* emailLbl;
    QLineEdit* emailLine;
    QLineEdit* mobileLine;
    QLineEdit* lastnameLine;
    QLineEdit* firstnameLine;
    QLineEdit* loginLine;
    QLineEdit* passwordLine;
    QPushButton* signupBtn;
    QPushButton* cancelBtn;
    bool visibleLbl;
    static RegisterForm* m_pInstance;
    QSqlDatabase db;

private:
    RegisterForm(QWidget* parent = 0, Qt::WindowFlags f = 0);
    void createInterior();
    void initSlots();

private slots:
    void signupClickedSlt();
    void cancelClickedSlt();

public:
    static RegisterForm* Instance(QWidget* parent = 0, Qt::WindowFlags = 0);
};

#endif // REGISTERFORM_H
