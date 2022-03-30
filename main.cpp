#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("circuitCourts");
    db.setUserName("ncasanelli");
    db.setPassword("oversea15623!");
    bool ok = db.open();
    qDebug()<<ok;
    MainWindow w;
    w.show();

    return a.exec();
}
