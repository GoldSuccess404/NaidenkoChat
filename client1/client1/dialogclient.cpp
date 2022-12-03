#include "dialogclient.h"

dialogClient::dialogClient(QWidget *parent) : QWidget(parent)
{
    setMaximumHeight(320);
    setMinimumHeight(320);
    setWindowIcon(QIcon("://images/main.png"));
    send = new QPushButton("->");
    send->setMinimumWidth(67);
    send->setMinimumHeight(21);
    line = new QLineEdit;
    text = new QTextEdit;
    text->setReadOnly(true);

    QHBoxLayout *hay = new QHBoxLayout;
    QVBoxLayout *vay = new QVBoxLayout;

    hay->addWidget(line);
    hay->addWidget(send);

    vay->addWidget(text);
    vay->addLayout(hay);
    setLayout(vay);

    connect(send, &QPushButton::clicked, this, &dialogClient::clicked_to_send);
    connect(line, &QLineEdit::returnPressed, this, &dialogClient::clicked_to_send);

    setStyleSheet("background: #7D44D6");
    text->setStyleSheet(styleHelper::getStyleTextEdit());
    line->setStyleSheet(styleHelper::getStyleLineEdit());
    send->setStyleSheet(styleHelper::getStylePushButton());
}

void dialogClient::clicked_to_send()
{
    emit readySend();
}
