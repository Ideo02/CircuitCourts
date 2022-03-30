#include "dialogajoutrayon.h"
#include "ui_dialogajoutrayon.h"

DialogAjoutRayon::DialogAjoutRayon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAjoutRayon)
{
    ui->setupUi(this);

    ui->pushButtonValider->setEnabled(false);
}

QString DialogAjoutRayon::getNom()
{
    return nom;
}

DialogAjoutRayon::~DialogAjoutRayon()
{
    delete ui;
}

void DialogAjoutRayon::on_lineEditNom_textEdited(const QString &arg1)
{
    if(ui->lineEditNom->text()!="")
        ui->pushButtonValider->setEnabled(true);
    else
        ui->pushButtonValider->setEnabled(false);

}


void DialogAjoutRayon::on_pushButtonValider_clicked()
{
    nom = ui->lineEditNom->text();
    accept();
}

