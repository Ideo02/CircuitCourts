#include "dialogmodifuser.h"
#include "ui_dialogmodifuser.h"
#include "dialogancienmdp.h"
#include "dialognouveaumdp.h"
#include <QDebug>
#include <QMessageBox>

DialogModifUser::DialogModifUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogModifUser)
{
    ui->setupUi(this);
    ui->labelModifMDP->setVisible(false);
}

void DialogModifUser::setData(QString num,QString login, QString MDP, QString adresse, QString tel, QString mail)
{
    qDebug()<<"void DialogModifUser::setData(QString num,QString login, QString MDP, QString adresse, QString tel, QString mail)";
    numUser = num;
    loginUser = login;
    motDePasseUser = MDP;
    adresseUser = adresse;
    telUser = tel;
    mailUser = mail;

    ui->lineEditLogin->setText(loginUser);
    ui->lineEditAdresse->setText(adresseUser);
    ui->lineEditMail->setText(mailUser);
    ui->lineEditTel->setText(telUser);
}

QString DialogModifUser::getRequete()
{
    return requete;
}

QString DialogModifUser::getLogin()
{
    return loginUser;
}

QString DialogModifUser::getMDP()
{
    return motDePasseUser;
}

DialogModifUser::~DialogModifUser()
{
    delete ui;
}

void DialogModifUser::on_pushButtonModifMDP_clicked()
{
    qDebug()<<"void DialogModifUser::on_pushButtonModifMDP_clicked()";
    DialogAncienMDP ancienMDP;
    ancienMDP.setAncienMDP(motDePasseUser);
    if(ancienMDP.exec()==QDialog::Accepted)
    {
        DialogNouveauMDP nouveauMDP;
        nouveauMDP.setData(motDePasseUser);
        if(nouveauMDP.exec()==QDialog::Accepted)
        {
            motDePasseUser = nouveauMDP.getMDP();
            qDebug()<<"nouveau mot de passe = "<<motDePasseUser;
            ui->labelModifMDP->setVisible(true);
        }
    }
}


void DialogModifUser::on_pushButtonValider_clicked()
{
    qDebug()<<"void DialogModifUser::on_pushButtonValider_clicked()";

    loginUser = ui->lineEditLogin->text();
    adresseUser = ui->lineEditAdresse->text();
    telUser = ui->lineEditTel->text();
    mailUser = ui->lineEditMail->text();

    requete = "UPDATE Utilisateur SET loginUtilisateur='"+loginUser+"',adresseUtilisateur='"+adresseUser+"',mailUtilisateur='"+mailUser+"',telUtilisateur='"+telUser+"',mdpUtilisateur=password('"+motDePasseUser+"') WHERE numeroUtilisateur='"+numUser+"'";
    qDebug()<<requete;
    accept();
}


void DialogModifUser::on_pushButtonAnnuler_clicked()
{
    qDebug()<<"void DialogModifUser::on_pushButtonAnnuler_clicked()";
    if(QMessageBox::warning(this,this->windowTitle(),"Voulez-vous vraiment quitter ? Toutes les modifications seront perdues.", QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)//Si l'utilisateur clique sur "oui"
    {
        reject();
    }
}

