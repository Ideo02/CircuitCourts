#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pdf.h"
#include "rayon.h"
#include "passerelle.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug()<<"MainWindow::MainWindow(QWidget *parent) :";
    ui->setupUi(this);
    brochurePDF();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::brochurePDF()
{
    qDebug()<<"void MainWindow::brochurePDF()";
    idProducteur = "1";
    QString titre = idProducteur;
    JeuEnregistrement monJeu("SELECT MAX(dateDebutSemaine) AS noSemaine FROM semaine");
    while(!monJeu.fin())
    {
        qDebug()<<"!fin()";
        semaine = monJeu.value("noSemaine").toString();
        monJeu.suivant();
    }
    titre += "_";
    titre += semaine;
    titre += ".pdf";
    ui->monPDF->setName(titre);
    QVector<Rayon> collectionRayon;
    collectionRayon = Passerelle::chargerLesRayons(idProducteur);
    for(int num = 0;num<collectionRayon.size();num++)
    {
        Rayon unRayon = collectionRayon.at(num);
        QString texte;
        texte = unRayon.versChaine();
        ui->monPDF->ecrireTexte(texte);
    }
}

void MainWindow::getNumProd(QString arg)
{
    qDebug()<<"void MainWindow::getNumProd(QString arg)";
    idProducteur = arg;
}

