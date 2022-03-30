#include "dialogmodifproduit.h"
#include "ui_dialogmodifproduit.h"
#include <QSqlQuery>
#include <QDebug>

DialogModifProduit::DialogModifProduit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifProduit)
{
    ui->setupUi(this);

    ui->pushButtonValider->setEnabled(false);

}

QString DialogModifProduit::getNom()
{
    return nomProduit;
}

QString DialogModifProduit::getNum()
{
    return numRayon;
}

void DialogModifProduit::setData(QString numProduit)
{
    qDebug()<<"void DialogModifProduit::setData(QString numProduit)";
    req = "SELECT numeroRayon,nomProduit FROM produit WHERE numeroProduit = "+numProduit;
    QSqlQuery selectRayon(req);
    selectRayon.next();
    numRayon = selectRayon.value(0).toString();

    ui->lineEditNom->setText(selectRayon.value(1).toString());

    int index = 0;
    req = "SELECT numeroRayon,nomRayon FROM rayon WHERE numeroRayon <"+numRayon;
    QSqlQuery query1(req);
    while(query1.next())
    {
        index++;
        listeNumero.append(query1.value(0).toString());
        ui->comboBoxRayon->addItem(query1.value(1).toString());
    }

    req = "SELECT numeroRayon,nomRayon FROM rayon WHERE numeroRayon ="+numRayon;
    QSqlQuery query2(req);
    query2.next();
    listeNumero.append(numRayon);
    ui->comboBoxRayon->addItem(query2.value(1).toString());

    req = "SELECT numeroRayon,nomRayon FROM rayon WHERE numeroRayon >"+numRayon;
    QSqlQuery query3(req);
    while(query3.next())
    {
        listeNumero.append(query3.value(0).toString());
        ui->comboBoxRayon->addItem(query3.value(1).toString());
    }

    ui->comboBoxRayon->setCurrentIndex(index);
}

DialogModifProduit::~DialogModifProduit()
{
    delete ui;
}

void DialogModifProduit::on_lineEditNom_textEdited(const QString &arg1)
{
    if(ui->lineEditNom->text()=="")
        ui->pushButtonValider->setEnabled(false);
    else
        ui->pushButtonValider->setEnabled(true);
}


void DialogModifProduit::on_pushButton_2_clicked()
{
    reject();
}


void DialogModifProduit::on_pushButtonValider_clicked()
{
    nomProduit = ui->lineEditNom->text();
    numRayon = listeNumero.at(ui->comboBoxRayon->currentIndex());

    accept();
}

