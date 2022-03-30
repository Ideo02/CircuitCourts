#include "dialognouveaumdp.h"
#include "ui_dialognouveaumdp.h"

DialogNouveauMDP::DialogNouveauMDP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogNouveauMDP)
{
    ui->setupUi(this);

    ui->labelCorrespondre->setVisible(false);
    ui->labelDifferent->setVisible(false);
    ui->pushButtonValider->setEnabled(false);

}

void DialogNouveauMDP::setData(QString MDP)
{
    motDePasse = MDP;
}

QString DialogNouveauMDP::getMDP()
{
    return motDePasse;
}

DialogNouveauMDP::~DialogNouveauMDP()
{
    delete ui;
}

void DialogNouveauMDP::on_lineEditMDP_textEdited(const QString &arg1)
{
    if(ui->lineEditMDP->text()!="" && ui->lineEditMDPConfirmer->text()!="")
    {
        ui->pushButtonValider->setEnabled(true);
    }
    else
    {
        ui->pushButtonValider->setEnabled(false);
    }
}


void DialogNouveauMDP::on_lineEditMDPConfirmer_textEdited(const QString &arg1)
{
    if(ui->lineEditMDP->text()!="" && ui->lineEditMDPConfirmer->text()!="")
    {
        ui->pushButtonValider->setEnabled(true);
    }
    else
    {
        ui->pushButtonValider->setEnabled(false);
    }
}


void DialogNouveauMDP::on_pushButtonValider_clicked()
{
    ui->labelCorrespondre->setVisible(false);
    ui->labelDifferent->setVisible(false);
    if(ui->lineEditMDP->text()!=ui->lineEditMDPConfirmer->text())
    {
        ui->labelCorrespondre->setVisible(true);
        ui->lineEditMDP->clear();
        ui->lineEditMDPConfirmer->clear();
    }
    else if(ui->lineEditMDP->text()==motDePasse)
    {
        ui->labelDifferent->setVisible(true);
        ui->lineEditMDP->clear();
        ui->lineEditMDPConfirmer->clear();
    }
    else
    {
        motDePasse = ui->lineEditMDP->text();
        ui->lineEditMDP->clear();
        ui->lineEditMDPConfirmer->clear();
        accept();
    }
}


void DialogNouveauMDP::on_pushButtonAnnuler_clicked()
{
    reject();
}

