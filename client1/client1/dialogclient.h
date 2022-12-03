#ifndef DIALOGCLIENT_H
#define DIALOGCLIENT_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "stylehelper.h"
class dialogClient : public QWidget
{
    Q_OBJECT
public:
    explicit dialogClient(QWidget *parent = nullptr);
    QPushButton *send;
    QLineEdit *line;
    QTextEdit *text;
public slots:
    void clicked_to_send();
signals:
    void readySend();
};

#endif // DIALOGCLIENT_H
