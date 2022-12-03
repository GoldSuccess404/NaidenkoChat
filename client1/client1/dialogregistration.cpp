#include "dialogregistration.h"

dialogRegistration::dialogRegistration(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(200);
    nam = new QLabel("Name: ");
    name = new QLineEdit;
    log = new QLabel("Login: ");
    login = new QLineEdit;
    pas = new QLabel("Password: ");
    password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    reg = new QPushButton("Registration");

    QVBoxLayout *vay = new QVBoxLayout;
    vay->addWidget(nam);
    vay->addWidget(name);
    vay->addWidget(log);
    vay->addWidget(login);
    vay->addWidget(pas);
    vay->addWidget(password);
    vay->addWidget(reg);
    setLayout(vay);

    setStyleSheet("background: #534942");
    nam->setStyleSheet(styleHelper::getStyleLabel());
    log->setStyleSheet(styleHelper::getStyleLabel());
    pas->setStyleSheet(styleHelper::getStyleLabel());
    name->setStyleSheet(styleHelper::getStyleLineEdit1());
    login->setStyleSheet(styleHelper::getStyleLineEdit1());
    password->setStyleSheet(styleHelper::getStyleLineEdit1());
    reg->setStyleSheet(styleHelper::getStylePushButton1());

    connect(reg, &QPushButton::clicked, this, &dialogRegistration::clicked_to_button);
}

void dialogRegistration::clicked_to_button()
{
    emit ready_values_reg(name->text(), login->text(), password->text());
    close();
}
