#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidgetAction->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEditConnexionLogin_textEdited(const QString &arg1)
{

}

void MainWindow::on_pushButtonConnexion_clicked()
{
    loginUtilisateur = ui->lineEditConnexionLogin->text();
    MdpUtilisateur = ui->lineEditConnexionMDP->text();

    req = "SELECT numeroUtilisateur,numeroTypeUtilisateur,nomUtilisateur,prenomUtilisateur,mailUtilisateur,telUtilisateur FROM Utilisateur WHERE loginUtilisateur = '"+loginUtilisateur+"' AND mdpUtilisateur = password('"+MdpUtilisateur+"')";
    qDebug()<<req;
    QSqlQuery getInfoUtilisateur(req);

    if(getInfoUtilisateur.next())
    {
        numUtilisateur = getInfoUtilisateur.value(0).toString();
        numTypeUtilisateur = getInfoUtilisateur.value(1).toString();
        nomUtilisateur = getInfoUtilisateur.value(2).toString();
        prenomUtilisateur = getInfoUtilisateur.value(3).toString();
        mailUtilisateur = getInfoUtilisateur.value(4).toString();
        telUtilisateur = getInfoUtilisateur.value(5).toString();

        req = "SELECT libelleTypeUtilisateur FROM TypeUtilisateur WHERE numeroTypeUtilisateur = "+numTypeUtilisateur;
        qDebug()<<req;
        QSqlQuery query(req);

        query.first();

        libelleTypeUtilisateur = query.value(0).toString();

        ui->labelInfoNom->setText(nomUtilisateur);
        ui->labelInfoPrenom->setText(prenomUtilisateur);
        ui->labelInfoRole->setText(libelleTypeUtilisateur);
        ui->labelInfoMail->setText(mailUtilisateur);
        ui->labelInfoTel->setText(telUtilisateur);

        ui->tabWidgetAction->setVisible(true);
        if(numTypeUtilisateur == "3" || numTypeUtilisateur == "2")
            ui->tabTableauDeBord->setVisible(true);
        else
            ui->tabTableauDeBord->setVisible(false);
    }

    afficherProducteurs();
}

void MainWindow::afficherProducteurs()
{
    qDebug()<<"void MainWindow::afficherProducteurs()";

    ui->tableWidgetProducteurs->setColumnWidth(0,25);
    ui->tableWidgetProducteurs->setColumnWidth(1,100);
    ui->tableWidgetProducteurs->setColumnWidth(2,100);
    ui->tableWidgetProducteurs->setColumnWidth(3,100);
    ui->tableWidgetProducteurs->setColumnWidth(4,300);
    ui->tableWidgetProducteurs->setColumnWidth(5,118);

    req = "SELECT numeroProducteur,loginProducteur,nomProducteur,prenomProducteur,adresseProducteur,telProducteur FROM producteur";
    QSqlQuery query(req);
    nb = 0;
    while(query.next())
    {
        numProducteur = query.value(0).toString();
        loginProducteur = query.value(1).toString();
        nomProducteur = query.value(2).toString();
        prenomProducteur = query.value(3).toString();
        adresseProducteur = query.value(4).toString();
        telProducteur = query.value(5).toString();

        ui->tableWidgetProducteurs->setRowCount(nb+1);

        ui->tableWidgetProducteurs->setItem(nb,0,new QTableWidgetItem(numProducteur));
        ui->tableWidgetProducteurs->setItem(nb,1,new QTableWidgetItem(loginProducteur));
        ui->tableWidgetProducteurs->setItem(nb,2,new QTableWidgetItem(nomProducteur));
        ui->tableWidgetProducteurs->setItem(nb,3,new QTableWidgetItem(prenomProducteur));
        ui->tableWidgetProducteurs->setItem(nb,4,new QTableWidgetItem(adresseProducteur));
        ui->tableWidgetProducteurs->setItem(nb,5,new QTableWidgetItem(telProducteur));

        nb++;
    }
}

