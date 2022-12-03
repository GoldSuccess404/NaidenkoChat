#ifndef DIALOGREGISTRATION_H
#define DIALOGREGISTRATION_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "stylehelper.h"
class dialogRegistration : public QWidget
{
    Q_OBJECT
public:
    explicit dialogRegistration(QWidget *parent = nullptr);
private:
    QLabel *nam;
    QLineEdit *name;
    QLabel *log;
    QLineEdit *login;
    QLabel *pas;
    QLineEdit *password;
    QPushButton *reg;
private slots:
    void clicked_to_button();
signals:
    void ready_values_reg(QString name, QString login, QString password);

};

#endif // DIALOGREGISTRATION_H
