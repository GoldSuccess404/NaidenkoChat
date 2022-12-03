#ifndef SERVER_H
#define SERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QMap>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDataStream>
#include <QDebug>
#include <QTime>
class server : public QTcpServer
{
    Q_OBJECT
public:
    server();
    QSqlDatabase db;
    QTcpSocket *socket;
    QByteArray data;
    QSqlQuery query;
    QString userName;
    void sendToClient();
    void send_To_Client_Message();
    enum status{
        reg1 = 0,
        entry1 = 1,
        sendMessage1 = 2,
        errorEntry1 = 3
    };
private:
    QMap<QTcpSocket*, QString> Sockets;
public slots:
    void incomingConnection(qintptr handle) override;
    void slotReadyRead();
    void slotDisc();
    void discUsers();

};

#endif // SERVER_H
