#include "loginform.h"

void LoginForm::createInterior()
{
    QVBoxLayout* main_lay = new QVBoxLayout;
    this->setLayout(main_lay);

    QHBoxLayout* login_lay = new QHBoxLayout;
    loginLbl = new QLabel(tr("<b>Login</b>"), this);
    loginLine = new QLineEdit(this);
    login_lay->addWidget(loginLbl, 1, Qt::AlignTop);
    login_lay->addWidget(loginLine, 3, Qt::AlignTop);
    login_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* password_lay = new QHBoxLayout;
    passwordLbl = new QLabel(tr("<b>Password</b>"), this);
    passwordLine = new QLineEdit(this);
    passwordLine->setEchoMode(QLineEdit::Password);
    password_lay->addWidget(passwordLbl, 1, Qt::AlignTop);
    password_lay->addWidget(passwordLine, 3, Qt::AlignTop);
    password_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* buttons_lay = new QHBoxLayout;
    loginBtn = new QPushButton(tr("Log in"), this);
    cancelBtn = new QPushButton(tr("Cancel"), this);
    buttons_lay->addWidget(loginBtn, 1, Qt::AlignBottom);
    buttons_lay->addWidget(cancelBtn, 1, Qt::AlignBottom);

    congrat = new QLabel(tr("<h2>Log in Intershop</h2>"), this);
    errorLbl = new QLabel(tr("Wrong login or password."), this);
    errorLbl->setStyleSheet("QLabel { font-weight: bold; color: red; }");
    errorLbl->setVisible(visibleLbl);

    main_lay->addWidget(congrat, 0, Qt::AlignHCenter | Qt::AlignTop);
    main_lay->addLayout(login_lay);
    main_lay->addLayout(password_lay);
    main_lay->addWidget(errorLbl, 0, Qt::AlignLeft);
    main_lay->addLayout(buttons_lay);
}

void LoginForm::initSlots()
{
    connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginClickedSlt()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(cancelClickedSlt()));
}

void LoginForm::loginClickedSlt()
{
    errorLbl->setVisible(false);
    if (loginLine->text() == "" || passwordLine->text() == "")
    {
        QString str = "Not all fields are filled.";
        errorLbl->setText(str);
        errorLbl->setVisible(true);
    }
    else
    {
        if (QSqlDatabase::database().isOpen())
        {
            QString password = QString("%1").arg(QString(QCryptographicHash::hash(passwordLine->text().toUtf8(),QCryptographicHash::Md5).toHex()));
            QSqlQuery query(QSqlDatabase::database());
            query.prepare("SELECT COUNT(*) FROM customer WHERE login = :login");
            query.bindValue(":login", loginLine->text());
            query.exec();
            if (query.next())
            {
                int count = query.value(0).toInt();
//                bool exist = false;
                if (count)
                {
                    qDebug() << "exist";
//                    QString pass = query.value(2).toString();
//                    if (password == pass) exist = true;
//                    else exist = false;
//                    this->reject();
                }
                else
//                if (!exist)
                {
                    QString str = "Wrong login or password.";
                    errorLbl->setText(str);
                    errorLbl->setVisible(true);
                }
            }
        }
        else
            QMessageBox::information(this, "Not connected", "Database is not connected");
    }
//    this->reject();
}

LoginForm* LoginForm::m_pInstance = nullptr;

LoginForm* LoginForm::Instance(QWidget *parent, Qt::WindowFlags flags)
{
    if (!m_pInstance)
       m_pInstance = new LoginForm(parent, flags);
    return m_pInstance;
}

LoginForm::LoginForm(QWidget* parent, Qt::WindowFlags flags) : QDialog(parent, flags), visibleLbl(false)
{
    this->setFixedSize(350, 250);
    createInterior();
    initSlots();
}

void LoginForm::cancelClickedSlt()
{
    this->reject();
}
