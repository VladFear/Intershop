#include "mainwindow.h"

void MainWindow::createInterior()
{
    QVBoxLayout* main_layout = new QVBoxLayout;
    main_layout->setMargin(0);
    this->setLayout(main_layout);

    QHBoxLayout* general_headerlay = new QHBoxLayout;
    QVBoxLayout* header_lay = new QVBoxLayout;
    QHBoxLayout* navigation_lay = new QHBoxLayout;
    header_widget = new QWidget(this);
    header_widget->setMaximumHeight(100);
    header_widget->setStyleSheet(
    "QWidget { background-color: rgb(18, 37, 56); }");

    number_lbl = new QLabel("<b>(099) 444-88-27</b>", this);
    number_lbl->setStyleSheet(
    "QLabel { color: white; } ");
    login_but = new QPushButton(this);
    login_but->setStyleSheet(
    "QPushButton { color: white; }"
    "QPushButton:pressed { background-color: green; } ");
    register_but = new QPushButton(this);
    register_but->setStyleSheet(
    "QPushButton { color: white; }");

    login_but->setText(tr("Log in"));
    register_but->setText(tr("Sign up"));

    QPixmap phone_pix(":/icons/phone.png");
    QLabel* phone_pict = new QLabel(this);
    phone_pict->setPixmap(phone_pix);

    welcome = new QLabel(tr("Welcome, "), this);
    welcome->setStyleSheet("QLabel { font-weight: bold; color: white; }");
    welcome->setVisible(false);

    navigation_lay->addItem(new QSpacerItem(400, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    navigation_lay->addWidget(phone_pict);
    navigation_lay->addWidget(number_lbl, 1, Qt::AlignLeft);
    navigation_lay->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    navigation_lay->addWidget(login_but, 0, Qt::AlignRight);
    navigation_lay->addWidget(register_but, 0, Qt::AlignRight);
    navigation_lay->addWidget(welcome, 0, Qt::AlignRight);
    navigation_lay->addItem(new QSpacerItem(100, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    QHBoxLayout* search_lay = new QHBoxLayout;
    search_line = new QLineEdit(this);
    search_line->setStyleSheet(
    "QLineEdit"
    "{ background-color: white; "
    "  border: none; "
    "  border-radius: 5px; "
    "  color: black; }");
    search_line->setMinimumSize(700, 25);
    search_line->setPlaceholderText(tr("Search..."));
    search_line->addAction(QIcon(":/icons/search.jpg"), QLineEdit::LeadingPosition);
    if (QSqlDatabase::database().isOpen())
    {
        QStringList wordList;
        QSqlQuery query(QSqlDatabase::database());
        query.exec("SELECT string FROM searched");
        while (query.next())
        {
            QString str = query.value(0).toString();
            wordList << str;
        }

        QCompleter *completer = new QCompleter(wordList, this);
        completer->setCaseSensitivity(Qt::CaseInsensitive);
        search_line->setCompleter(completer);
    }
    search_but = new QPushButton(this);
    search_but->setStyleSheet(
    "QPushButton { "
    "    background-color: rgb(0, 188, 82);"
    "    border-radius: 3px;"
    "    color: white; "
    "}"
    ""
    "QPushButton:hover { "
    "   background-color: rgb(0, 168, 72); "
    "}"
    ""
    "QPushButton:pressed {"
    "   background-color: green; "
    "}");
    search_but->setMinimumSize(70, 25);
    search_but->setText(tr("Find"));
    search_lay->addItem(new QSpacerItem(400, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    search_lay->addWidget(search_line, 0, Qt::AlignLeft);
    search_lay->addWidget(search_but, 1, Qt::AlignLeft);
    search_lay->addItem(new QSpacerItem(100, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));

    header_lay->addLayout(navigation_lay);
    header_lay->addLayout(search_lay);

    QPixmap intershop(":/pictures/intershop1.png");
    intershopLabel = new ClickableLabel(this);
    intershopLabel->setPixmap(intershop);

    general_headerlay->addWidget(intershopLabel);
    general_headerlay->addLayout(header_lay);
    header_widget->setLayout(general_headerlay);

    QHBoxLayout* central_layout = new QHBoxLayout;
    central_widget = new CentralWidget(this);
    central_widget->setStyleSheet("QWidget { background-color: white; }");

    central_layout->addWidget(central_widget);

    main_layout->addWidget(header_widget);
    main_layout->addWidget(central_widget);

    main_layout->setSpacing(0);

    login_form = LoginForm::Instance(this);

    register_form = RegisterForm::Instance(this);
}

void MainWindow::initSlots()
{
    connect(login_but, SIGNAL(clicked(bool)), this, SLOT(loginClickedSlt()));
    connect(register_but, SIGNAL(clicked(bool)), this, SLOT(registerClickedSlt()));
    connect(search_but, SIGNAL(clicked(bool)), this, SLOT(searchButClickedSlt()));
    connect(this, SIGNAL(searchButClicked(QString)), central_widget, SLOT(searchButClicked(QString)));
    connect(intershopLabel, SIGNAL(clicked(QString)), this, SLOT(intershopImageClickedSlt()));
    connect(this, SIGNAL(intershopImageClicked()), central_widget, SLOT(intershopImageClicked()));
    connect(login_form, SIGNAL(logged(int)), this, SLOT(userLogged(int)));
}

void MainWindow::loginClickedSlt()
{
    login_form->exec();
}

void MainWindow::registerClickedSlt()
{
    register_form->exec();
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), user(0)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(1550, 800);
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName("intershop");
    db.setHostName("127.0.0.1");
    if(!db.open("root", "root"))
        QMessageBox::information(this, "Not connected", "Database is not connected");
    createInterior();
    initSlots();
}

void MainWindow::searchButClickedSlt()
{
    if (QSqlDatabase::database().isOpen())
    {
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("INSERT INTO searched(string) VALUES (:str)");
        query.bindValue(":str", search_line->text());
        query.exec();
    }

    emit searchButClicked(search_line->text());
}

void MainWindow::intershopImageClickedSlt()
{
    emit intershopImageClicked();
}

void MainWindow::userLogged(int id)
{
    if (QSqlDatabase::database().isOpen())
    {
        QSqlQuery query(QSqlDatabase::database());
        query.prepare("SELECT login FROM customer WHERE id = :id");
        query.bindValue(":id", id);
        query.exec();
        query.first();
        welcome->setText(welcome->text() + query.value(0).toString());
        welcome->setVisible(true);
        login_but->setVisible(false);
        register_but->setVisible(false);
    }
    else
        QMessageBox::information(this, "Not connected", "Database is not connected");
}
