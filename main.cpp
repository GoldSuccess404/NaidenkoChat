#include <QCoreApplication>
#include "server.h"


int main(int argc, char *argv[])
{   QCoreApplication a(argc, argv);
    setlocale(0, "");
    server myserver;
    QObject::connect(&a, &QCoreApplication::aboutToQuit, &myserver, &server::discUsers);
    return a.exec();
}
