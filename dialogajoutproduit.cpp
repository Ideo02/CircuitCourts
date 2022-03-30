#include "dialogajoutproduit.h"
#include "ui_dialogajoutproduit.h"
#include <QSqlQuery>
#include <QDebug>
#include <QList>

DialogAjoutProduit::DialogAjoutProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjoutProduit)
{
    ui->setupUi(this);
    ui->pushButtonValider->setEnabled(false);

    int nb = 0;
    req = "SELECT numeroRayon,nomRayon FROM rayon";
    QSqlQuery query(req);
    while(query.next())
    {
        listeNumero.append(query.value(0).toString());

        ui->comboBoxRayon->addItem(query.value(1).toString());
    }
    ui->comboBoxRayon->setCurrentIndex(0);

}

QString DialogAjoutProduit::getNom()
{
    return nomProduit;
}

QString DialogAjoutProduit::getNumRayon()
{
    return numRayon;
}


DialogAjoutProduit::~DialogAjoutProduit()
{
    delete ui;
}

void DialogAjoutProduit::on_lineEditNom_textEdited(const QString &arg1)
{
    if(ui->lineEditNom->text()=="")
        ui->pushButtonValider->setEnabled(false);
    else
        ui->pushButtonValider->setEnabled(true);

}


void DialogAjoutProduit::on_pushButtonValider_clicked()
{
    numRayon = listeNumero.at(ui->comboBoxRayon->currentIndex());
    nomProduit = ui->lineEditNom->text();

    accept();
}


void DialogAjoutProduit::on_pushButtonAnnuler_clicked()
{
    reject();
}

