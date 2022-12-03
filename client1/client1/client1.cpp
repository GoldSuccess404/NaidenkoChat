#include "client1.h"

client1::client1(QWidget *parent)
    : QWidget(parent)
{
    setMaximumHeight(150);
    setMinimumHeight(150);
    setWindowIcon(QIcon("://images/main.png"));
    labLogin = new QLabel("Login: ");
    login = new QLineEdit;
    labPassword = new QLabel("Password: ");
    password = new QLineEdit;
    password->setEchoMode(QLineEdit::Password);
    entry = new QPushButton("Entry");
    reg = new QPushButton("Registration");
    entry->setDefault(true);

    QHBoxLayout *hay = new QHBoxLayout;
    QVBoxLayout *vay = new QVBoxLayout;

    hay->addWidget(entry);
    hay->addWidget(reg);

    vay->addWidget(labLogin);
    vay->addWidget(login);
    vay->addWidget(labPassword);
    vay->addWidget(password);
    vay->addLayout(hay);
    setLayout(vay);
    socket = new QTcpSocket(this);
    labLogin->setStyleSheet(styleHelper::getStyleLabel());
    labPassword->setStyleSheet(styleHelper::getStyleLabel());
    login->setStyleSheet(styleHelper::getStyleLineEdit1());
    password->setStyleSheet(styleHelper::getStyleLineEdit1());
    entry->setStyleSheet(styleHelper::getStylePushButton1());
    reg->setStyleSheet(styleHelper::getStylePushButton1());
    setStyleSheet("background: #534942");

    connect(reg, &QPushButton::clicked, this, &client1::clicked_registration);
    connect(&dReg, &dialogRegistration::ready_values_reg, this, &client1::reg_datas_to_Server);
    connect(socket, &QTcpSocket::readyRead, this, &client1::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &client1::discUsers);
    connect(entry, &QPushButton::clicked, this, &client1::entry_datas_to_Server);
    connect(&dClient, &dialogClient::readySend, this, &client1::sendToServer);
}
/*вызываем диалоговое окно с регестрацией*/
void client1::clicked_registration()
{
    dReg.show();
}

/*отправка данных на сервер при регестрации*/
void client1::reg_datas_to_Server(QString name, QString login, QString password)
{
    socket->connectToHost("127.0.0.1", 3223);
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << reg1 << login << password << name;
    socket->write(data);
    //socket->disconnectFromHost();
}

/*отправка данных на сервер при входе*/
void client1::entry_datas_to_Server()
{
    socket->connectToHost("127.0.0.1", 3223);
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << entry1 << login->text() << password->text();
    socket->write(data);
}

/*отправка сообщения на сревер*/
void client1::sendToServer()
{
    if(!dClient.line->text().isEmpty()){
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << sendMessage1 << dClient.line->text();
    socket->write(data);
    dClient.line->clear();
    }
}

/*получение данных с сервера*/
void client1::slotReadyRead()
{
    QDataStream in(socket);
    if(in.status() == QDataStream::Ok){
        int state;
        QString name;
        QTime time;
        QString message;
        in >> state >> name >> time >> message;

        if(state == entry1){
            close();
            dClient.show();
        }
        else if(state == sendMessage1){
            dClient.text->append(name + " " + "[" + time.toString() + "]" + " " + message);
        }
        else if(state == errorEntry){
            QMessageBox::critical(this, "Error", "Incorrect login or password!");
        }
    }
}

void client1::discUsers()
{
    socket->deleteLater();
    dClient.close();
}




