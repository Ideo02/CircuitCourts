#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("circuitCourts");
    db.setUserName("ncasanelli");
    db.setPassword("oversea15623!");
    bool ok = db.open();
    MainWindow w;
    w.show();

    return a.exec();
}
