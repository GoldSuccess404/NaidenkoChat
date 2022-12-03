#ifndef CLIENT1_H
#define CLIENT1_H

#include <QWidget>
#include <QTcpSocket>
#include <QDataStream>
#include <QDebug>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>
#include <QTime>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "dialogregistration.h"
#include "dialogclient.h"
#include "stylehelper.h"
class client1 : public QWidget
{
    Q_OBJECT

public:
    client1(QWidget *parent = nullptr);
    ~client1(){};
    QTcpSocket *socket;
    QByteArray data;

    QLabel *labLogin;
    QLineEdit *login;
    QLabel *labPassword;
    QLineEdit *password;
    QPushButton *entry;
    QPushButton *reg;

    dialogRegistration dReg;
    dialogClient dClient;

    enum status{
        reg1 = 0,
        entry1 = 1,
        sendMessage1 = 2,
        errorEntry = 3
    };

public slots:
    void clicked_registration();
    void reg_datas_to_Server(QString name, QString login, QString password);
    void entry_datas_to_Server();
    void sendToServer();
    void slotReadyRead();
    void discUsers();

};
#endif // CLIENT1_H
