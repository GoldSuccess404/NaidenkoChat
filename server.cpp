#include "server.h"

server::server()
{
    /*connect to DataBase*/
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setUserName("noname");
    db.setPassword("1111");
    db.setDatabaseName("chat");
    if (!db.open()){
           qDebug() << db.lastError().text();
           return;
         }

    if(this->listen(QHostAddress::Any, 3223)){
        qDebug() << "Listening!";
    }
    else qDebug() << "No listening :(";
}

/*send message to client*/
void server::sendToClient()
{
    qDebug() <<  "Connect" << userName;
    Sockets.insert(socket, userName);
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out << entry1; //1
    socket->write(data);
    userName.clear();
}

/*new connect*/
void server::incomingConnection(qintptr handle)
{
    socket = new QTcpSocket(this);
    socket->setSocketDescriptor(handle);

    connect(socket, &QTcpSocket::readyRead, this, &server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &server::slotDisc);
}

/*datas from client*/
void server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    if(in.status() == QDataStream::Ok){
        int state;
        QString login;
        QString password;
        QString name;
        in >> state >> login >> password >> name;
        if (state == reg1){
            /*если регестрация, то заносим в БД*/
          QString temp = "insert into naidenko_chat(name, login, password) values('%1', '%2', '%3')";
          QSqlQuery(temp.arg(name).arg(login).arg(password));
        }
        else if (state == entry1){
            /*если выполняется вход*/
            query = QSqlQuery(db);
            QString temp = "select name from naidenko_chat where login = '%1' and password = '%2'";

            if (!query.exec(temp.arg(login).arg(password))) {
            qDebug() << "Не удалось выполнить запрос!";
            return;
            }
                QSqlRecord rec = query.record();
                query.first();
                userName = query.value(rec.indexOf("name")).toString();
            if (!userName.isEmpty()) sendToClient();
            else {
                qDebug() << "Incorrect username or password!";
                data.clear();
                QDataStream out(&data, QIODevice::WriteOnly);
                out << errorEntry1;
                socket->write(data);
            }
        }
        else if (state == sendMessage1){
            /*рассылка сообщения всем клиентам*/
            auto it = Sockets.find(socket);
            data.clear();
            QDataStream out(&data, QIODevice::WriteOnly);
            out << sendMessage1 << *it << QTime::currentTime() << login; //сообщение
            qDebug() << *it << login;//сообщение

            for(auto iter : Sockets.keys()){
                iter->write(data);
            }
        }
    }
    else {
        qDebug() << "error";
    }


}

void server::slotDisc()
{
    auto it = Sockets.find(socket = (QTcpSocket*)sender());
    qDebug() << "Disconect" << *it;
    Sockets.erase(it);
    socket->deleteLater();

}

void server::discUsers()
{
    if(!Sockets.empty()){
       for(int i=0; i<Sockets.size(); i++){
           Sockets.firstKey()->deleteLater();
       }
    }
}



