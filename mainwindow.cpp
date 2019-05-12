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
    "QPushButton { color: white; }");
    register_but = new QPushButton(this);
    register_but->setStyleSheet(
    "QPushButton { color: white; }");

    login_but->setText(tr("Log in"));
    register_but->setText(tr("Sign up"));

    QPixmap phone_pix(":/icons/phone.png");
    QLabel* phone_pict = new QLabel(this);
    phone_pict->setPixmap(phone_pix);

    navigation_lay->addItem(new QSpacerItem(400, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
        navigation_lay->addWidget(phone_pict);
    navigation_lay->addWidget(number_lbl, 1, Qt::AlignLeft);
    navigation_lay->addItem(new QSpacerItem(200, 0, QSizePolicy::Expanding, QSizePolicy::Fixed));
    navigation_lay->addWidget(login_but, 0, Qt::AlignRight);
    navigation_lay->addWidget(register_but, 0, Qt::AlignRight);
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
    QLabel* intershopLabel = new QLabel(this);
    intershopLabel->setPixmap(intershop);

    general_headerlay->addWidget(intershopLabel);
    general_headerlay->addLayout(header_lay);
    header_widget->setLayout(general_headerlay);

    QVBoxLayout* centerlayout = new QVBoxLayout;
    center_widget = new QWidget(this);
    center_widget->setStyleSheet(
    "QWidget { background-color: white; }");
    center_widget->setLayout(centerlayout);
    phones = new QLabel(tr("<h1>Phones</h1>"), this);
    phones->setStyleSheet(
    "QLabel { color: black; } ");
    centerlayout->addWidget(phones, 1, Qt::AlignCenter | Qt::AlignTop);

    QHBoxLayout* phones_brands = new QHBoxLayout;
    QPixmap iphone(":/pictures/iphone.jpg");
    QLabel* iphoneLabel = new QLabel(this);
    iphoneLabel->setPixmap(iphone);
    phones_brands->addWidget(iphoneLabel, 1, Qt::AlignTop);

    QPixmap mi(":/pictures/mi.jpg");
    QLabel* miLabel = new QLabel(this);
    miLabel->setPixmap(mi);
    phones_brands->addWidget(miLabel, 1, Qt::AlignTop);

    QPixmap meizu(":/pictures/meizu.jpg");
    QLabel* meizuLabel = new QLabel(this);
    meizuLabel->setPixmap(meizu);
    phones_brands->addWidget(meizuLabel, 1, Qt::AlignTop);

    centerlayout->addLayout(phones_brands);

    main_layout->addWidget(header_widget);
    main_layout->addWidget(center_widget);
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setMinimumSize(1550, 800);
    createInterior();
}
