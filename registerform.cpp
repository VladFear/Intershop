#include "registerform.h"

RegisterForm* RegisterForm::m_pInstance = nullptr;

RegisterForm::RegisterForm(QWidget *parent, Qt::WindowFlags f) : QDialog(parent, f), visibleLbl(false)
{
    this->setFixedSize(400, 300);
    createInterior();
    initSlots();
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("intershop");
    db.setHostName("127.0.0.1");
}

void RegisterForm::createInterior()
{
    QVBoxLayout* main_lay = new QVBoxLayout;
    this->setLayout(main_lay);

    QHBoxLayout* firstname_lay = new QHBoxLayout;
    firstnameLbl = new QLabel(tr("<b>First Name</b>"), this);
    firstnameLine = new QLineEdit(this);
    firstname_lay->addWidget(firstnameLbl, 1, Qt::AlignTop);
    firstname_lay->addWidget(firstnameLine, 3, Qt::AlignTop);
    firstname_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* lastname_lay = new QHBoxLayout;
    lastnameLbl = new QLabel(tr("<b>Last Name</b>"), this);
    lastnameLine = new QLineEdit(this);
    lastname_lay->addWidget(lastnameLbl, 1, Qt::AlignTop);
    lastname_lay->addWidget(lastnameLine, 3, Qt::AlignTop);
    lastname_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* email_lay = new QHBoxLayout;
    emailLbl = new QLabel(tr("<b>Email</b>"), this);
    emailLine = new QLineEdit(this);
    email_lay->addWidget(emailLbl, 1, Qt::AlignTop);
    email_lay->addWidget(emailLine, 3, Qt::AlignTop);
    email_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* mobile_lay = new QHBoxLayout;
    mobileLbl = new QLabel(tr("<b>Phone</b>"), this);
    mobileLine = new QLineEdit(this);
    mobile_lay->addWidget(mobileLbl, 1, Qt::AlignTop);
    mobile_lay->addWidget(mobileLine, 3, Qt::AlignTop);
    mobile_lay->addItem(new QSpacerItem(10, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

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
    signupBtn = new QPushButton(tr("Sign up"), this);
    cancelBtn = new QPushButton(tr("Cancel"), this);
    buttons_lay->addWidget(signupBtn, 1, Qt::AlignBottom);
    buttons_lay->addWidget(cancelBtn, 1, Qt::AlignBottom);

    congrat = new QLabel(tr("<h2>Sign up Intershop</h2>"), this);
    errorLbl = new QLabel(tr(""), this);
    errorLbl->setStyleSheet("QLabel { font-weight: bold; color: red; }");
    errorLbl->setVisible(visibleLbl);

    main_lay->addWidget(congrat, 0, Qt::AlignHCenter | Qt::AlignTop);
    main_lay->addLayout(firstname_lay);
    main_lay->addLayout(lastname_lay);
    main_lay->addLayout(email_lay);
    main_lay->addLayout(mobile_lay);
    main_lay->addLayout(login_lay);
    main_lay->addLayout(password_lay);
    main_lay->addWidget(errorLbl, 0, Qt::AlignLeft);
    main_lay->addLayout(buttons_lay);
}

void RegisterForm::initSlots()
{
    connect(signupBtn, SIGNAL(clicked(bool)), this, SLOT(signupClickedSlt()));
    connect(cancelBtn, SIGNAL(clicked(bool)), this, SLOT(cancelClickedSlt()));
}

void RegisterForm::signupClickedSlt()
{
    errorLbl->setVisible(false);
    if (firstnameLine->text() == "" || lastnameLine->text() == "" || emailLine->text() == "" || loginLine->text() == "" || passwordLine->text() == "")
    {
        QString str = "Not all fields are filled.";
            errorLbl->setText(str);
        errorLbl->setVisible(true);
    }
    else
    {
        if (db.open("root", "root"))
        {
            QSqlQuery query(db);
            query.prepare("INSERT INTO customer (firstname, lastname, email, phone, login, password) VALUES (:firstname, :lastname, :email, :phone, :login, :password)");
            query.bindValue(":firstname", firstnameLine->text());
            query.bindValue(":lastname", lastnameLine->text());
            query.bindValue(":email", emailLine->text());
            query.bindValue(":phone", mobileLine->text());
            query.bindValue(":login", loginLine->text());
            query.bindValue(":password", passwordLine->text());
            query.exec();
            db.close();
            this->reject();
        }
        else
        {
            QMessageBox::information(this, "not connected", "database is not connected");
            db.close();
        }
    }
}

void RegisterForm::cancelClickedSlt()
{
    this->reject();
}

RegisterForm* RegisterForm::Instance(QWidget *parent, Qt::WindowFlags flags)
{
    if (!m_pInstance)
       m_pInstance = new RegisterForm(parent, flags);
    return m_pInstance;
}
