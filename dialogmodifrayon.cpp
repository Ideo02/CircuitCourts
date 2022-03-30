#include "dialogmodifrayon.h"
#include "ui_dialogmodifrayon.h"

DialogModifRayon::DialogModifRayon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifRayon)
{
    ui->setupUi(this);


    ui->pushButtonValider->setEnabled(false);
}

QString DialogModifRayon::getNom()
{
    return nom;
}

void DialogModifRayon::setData(QString nomRayon)
{
    ui->lineEditNom->setText(nomRayon);
}

DialogModifRayon::~DialogModifRayon()
{
    delete ui;
}

void DialogModifRayon::on_lineEditNom_textEdited(const QString &arg1)
{
    if(ui->lineEditNom->text()=="")
        ui->pushButtonValider->setEnabled(false);
    else
        ui->pushButtonValider->setEnabled(true);
}


void DialogModifRayon::on_pushButtonValider_clicked()
{
    nom = ui->lineEditNom->text();

    accept();
}


void DialogModifRayon::on_pushButtonAnnuler_clicked()
{
    reject();
}

