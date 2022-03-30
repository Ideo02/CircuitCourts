#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QSqlError>
#include "dialogrejet.h"
#include "dialogmodifuser.h"
#include "dialogajoutrayon.h"
#include "dialogajoutproduit.h"
#include "dialogmodifrayon.h"
#include "dialogmodifproduit.h"
#include <QCheckBox>
#include <QMessageBox>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidgetAction->setVisible(false);
    ui->pushButtonModifierInfoUser->setVisible(false);
    ui->pushButtonConnexion->setEnabled(false);
    ui->groupBoxInformations->setVisible(false);
    ui->pushButtonDeconnexion->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_lineEditConnexionLogin_textEdited(const QString &arg1)
{
    if(ui->lineEditConnexionLogin->text()!="" && ui->lineEditConnexionMDP->text()!="")
    {
        ui->pushButtonConnexion->setEnabled(true);
    }
    else
    {
        ui->pushButtonConnexion->setEnabled(false);
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_lineEditConnexionMDP_textEdited(const QString &arg1)
{
    if(ui->lineEditConnexionLogin->text()!="" && ui->lineEditConnexionMDP->text()!="")
    {
        ui->pushButtonConnexion->setEnabled(true);
    }
    else
    {
        ui->pushButtonConnexion->setEnabled(false);
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonConnexion_clicked()
{
    connexion();
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::connexion()
{
    loginUtilisateur = ui->lineEditConnexionLogin->text();
    MdpUtilisateur = ui->lineEditConnexionMDP->text();

    req = "SELECT numeroUtilisateur,numeroTypeUtilisateur,nomUtilisateur,prenomUtilisateur,mailUtilisateur,telUtilisateur,adresseUtilisateur FROM Utilisateur WHERE loginUtilisateur = '"+loginUtilisateur+"' AND mdpUtilisateur = password('"+MdpUtilisateur+"')";
    qDebug()<<req;
    QSqlQuery getInfoUtilisateur(req);

    if(getInfoUtilisateur.next())
    {
        ui->pushButtonDeconnexion->setVisible(true);
        ui->groupBoxInformations->setVisible(true);

        numUtilisateur = getInfoUtilisateur.value(0).toString();
        numTypeUtilisateur = getInfoUtilisateur.value(1).toString();
        nomUtilisateur = getInfoUtilisateur.value(2).toString();
        prenomUtilisateur = getInfoUtilisateur.value(3).toString();
        mailUtilisateur = getInfoUtilisateur.value(4).toString();
        telUtilisateur = getInfoUtilisateur.value(5).toString();
        adresseUtilisateur = getInfoUtilisateur.value(6).toString();

        req = "SELECT libelleTypeUtilisateur FROM TypeUtilisateur WHERE numeroTypeUtilisateur = "+numTypeUtilisateur;
        QSqlQuery query(req);

        query.first();

        libelleTypeUtilisateur = query.value(0).toString();

        ui->labelInfoNom->setText(nomUtilisateur);
        ui->labelInfoPrenom->setText(prenomUtilisateur);
        ui->labelInfoRole->setText(libelleTypeUtilisateur);
        ui->labelInfoMail->setText(mailUtilisateur);
        ui->labelInfoTel->setText(telUtilisateur);
        ui->labelInfoAdresse->setText(adresseUtilisateur);
        ui->pushButtonModifierInfoUser->setVisible(true);

        ui->tabWidgetAction->setVisible(true);
        if(numTypeUtilisateur == "3" || numTypeUtilisateur == "2")
            ui->tabTableauDeBord->setVisible(true);
        else
            ui->tabTableauDeBord->setVisible(false);
    }
    else
    {
        ui->tabWidgetAction->setVisible(false);
        ui->pushButtonModifierInfoUser->setVisible(false);
        ui->labelInfoNom->setVisible(false);
        ui->labelInfoPrenom->setVisible(false);
        ui->labelInfoRole->setVisible(false);
        ui->labelInfoMail->setVisible(false);
        ui->labelInfoTel->setVisible(false);
        ui->labelInfoAdresse->setVisible(false);
        ui->groupBoxInformations->setVisible(false);
    }
    afficherProducteurs();
    afficherTableauDeBord();
    afficherRayons();
    afficherProduits();
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::afficherProducteurs()
{
    qDebug()<<"void MainWindow::afficherProducteurs()";

    ui->tableWidgetProducteurs->setRowCount(0);

    ui->tableWidgetProducteurs->setColumnWidth(0,25);
    ui->tableWidgetProducteurs->setColumnWidth(1,100);
    ui->tableWidgetProducteurs->setColumnWidth(2,100);
    ui->tableWidgetProducteurs->setColumnWidth(3,100);
    ui->tableWidgetProducteurs->setColumnWidth(4,275);
    ui->tableWidgetProducteurs->setColumnWidth(5,118);
    ui->tableWidgetProducteurs->setColumnWidth(6,25);

    req = "SELECT numeroProducteur,loginProducteur,nomProducteur,prenomProducteur,adresseProducteur,telProducteur,statut FROM producteur";
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
        valide = query.value(6).toString();

        if(valide=="0")
        {
            ui->tableWidgetProducteurs->setRowCount(nb+1);

            ui->tableWidgetProducteurs->setItem(nb,0,new QTableWidgetItem(numProducteur));
            ui->tableWidgetProducteurs->setItem(nb,1,new QTableWidgetItem(loginProducteur));
            ui->tableWidgetProducteurs->setItem(nb,2,new QTableWidgetItem(nomProducteur));
            ui->tableWidgetProducteurs->setItem(nb,3,new QTableWidgetItem(prenomProducteur));
            ui->tableWidgetProducteurs->setItem(nb,4,new QTableWidgetItem(adresseProducteur));
            ui->tableWidgetProducteurs->setItem(nb,5,new QTableWidgetItem(telProducteur));
            ui->tableWidgetProducteurs->setCellWidget(nb,6, new QCheckBox);

            nb++;
        }
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::afficherTableauDeBord()
{
    req = "SELECT COUNT(*) FROM producteur WHERE DATEDIFF(dateInscriptionProducteur,NOW()) >= -28";
    QSqlQuery query(req);
    query.next();
    ui->labelNombreProdInscrits->setText(query.value(0).toString());

    req = "SELECT COUNT(*) FROM variete WHERE DATEDIFF(dateAjoutVariete,NOW()) >= -28";
    QSqlQuery query_1(req);
    query_1.next();
    ui->labelNombreNouvelleVarietes->setText(query_1.value(0).toString());

    ui->tableWidgetVarietesParRayon->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidgetVarietesParRayon->setRowCount(1);
    int colonne = 0;
    req = "SELECT numeroRayon,nomRayon FROM rayon";
    QSqlQuery query_6(req);
    while(query_6.next())
    {
        colonne++;
        ui->tableWidgetVarietesParRayon->setColumnCount(colonne);
        ui->tableWidgetVarietesParRayon->setHorizontalHeaderItem(colonne-1,new QTableWidgetItem(query_6.value(1).toString()));
        req = "SELECT COUNT(*) FROM variete INNER JOIN produit ON variete.numeroProduit = produit.numeroProduit INNER JOIN rayon ON produit.numeroRayon = rayon.numeroRayon WHERE rayon.numeroRayon = "+query_6.value(0).toString();
        QSqlQuery query_7(req);
        query_7.next();
        ui->tableWidgetVarietesParRayon->setItem(0,colonne-1,new QTableWidgetItem(query_7.value(0).toString()));
    }

    req = "SELECT COUNT(*) FROM Produire";
    QSqlQuery query_2(req);
    query_2.next();
    ui->labelnombreLotsVente->setText(query_2.value(0).toString());

    float chiffreDAffaire = 0;
    req = "SELECT numeroTypeAbonnement FROM abonnement WHERE DATEDIFF(dateDebutAbonnement,NOW()) >= -28";
    QSqlQuery query_3(req);
    while(query_3.next())
    {
        req = "SELECT prixTypeAbonnement FROM typeAbonnement WHERE numeroTypeAbonnement = "+query_3.value(0).toString();
        QSqlQuery query_4(req);
        query_4.next();
        chiffreDAffaire += query_4.value(0).toFloat();
    }
    ui->labelChiffreDAffaire->setText(QString::number(chiffreDAffaire));

    float ancienChiffreDAffaire = 0;
    req = "SELECT numeroTypeAbonnement FROM abonnement WHERE DATEDIFF(dateDebutAbonnement,NOW()) < -28 AND DATEDIFF(dateDebutAbonnement,NOW()) >= -56";
    QSqlQuery query_5(req);
    while(query_5.next())
    {
        req = "SELECT prixTypeAbonnement FROM typeAbonnement WHERE numeroTypeAbonnement = "+query_5.value(0).toString();
        QSqlQuery query_4(req);
        query_4.next();
        ancienChiffreDAffaire += query_4.value(0).toFloat();
    }
    float evolutionChiffreDAffaire = 0;
    if((chiffreDAffaire/ancienChiffreDAffaire)*100 >= 0)
        evolutionChiffreDAffaire = (chiffreDAffaire/ancienChiffreDAffaire)*100;

    ui->labelEvolution->setText(QString::number(evolutionChiffreDAffaire)+"%");

}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::afficherRayons()
{
    qDebug()<<"void MainWindow::afficherRayons()";
    ui->tableWidgetRayon->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    nb = 0;
    req = "SELECT numeroRayon,nomRayon FROM rayon";
    QSqlQuery afficheRayons(req);
    while(afficheRayons.next())
    {
        ui->tableWidgetRayon->setRowCount(nb+1);

        numRayon = afficheRayons.value(0).toString();
        nomRayon = afficheRayons.value(1).toString();

        ui->tableWidgetRayon->setItem(nb,0,new QTableWidgetItem(numRayon));
        ui->tableWidgetRayon->setItem(nb,1,new QTableWidgetItem(nomRayon));
        ui->tableWidgetRayon->setCellWidget(nb,2,new QCheckBox);

        nb++;
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::afficherProduits()
{
    qDebug()<<"void MainWindow::afficherProduits()";
    ui->tableWidgetProduit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    nb = 0;
    req = "SELECT produit.numeroProduit,produit.nomProduit,produit.numeroRayon,rayon.nomRayon FROM produit "
          "INNER JOIN rayon ON produit.numeroRayon = rayon.numeroRayon "
          "ORDER BY produit.nomProduit";
    QSqlQuery afficheProduit(req);
    while(afficheProduit.next())
    {
        ui->tableWidgetProduit->setRowCount(nb+1);

        numProduit = afficheProduit.value(0).toString();
        nomProduit = afficheProduit.value(1).toString();
        nomRayon = afficheProduit.value(3).toString();

        ui->tableWidgetProduit->setItem(nb,0,new QTableWidgetItem(numProduit));
        ui->tableWidgetProduit->setItem(nb,1,new QTableWidgetItem(nomProduit));
        ui->tableWidgetProduit->setItem(nb,2,new QTableWidgetItem(nomRayon));
        ui->tableWidgetProduit->setCellWidget(nb,3,new QCheckBox);

        nb++;
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonValiderProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonValiderProducteur_clicked()";
    int ligne = ui->tableWidgetProducteurs->rowCount()-1;
    int nbChecked = 0;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetProducteurs->cellWidget(noLigne,6)))->isChecked())
        {
            nbChecked++;
            numProducteur = ui->tableWidgetProducteurs->item(noLigne,0)->text();

            req = "UPDATE producteur SET statut = 1 WHERE numeroProducteur = "+numProducteur;
            QSqlQuery query(req);
        }
    }
    if(nbChecked == 0)
    {
        ui->statusbar->setStyleSheet("color:rgb(252, 62, 62)");
        ui->statusbar->showMessage("Aucune case cochée !",3000);
    }

    afficherProducteurs();
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonRejeterProducteur_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonRejeterProducteur_clicked()";
    int ligne = ui->tableWidgetProducteurs->rowCount()-1;
    int nbChecked = 0;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetProducteurs->cellWidget(noLigne,6)))->isChecked())
        {
            nbChecked++;
            numProducteur = ui->tableWidgetProducteurs->item(noLigne,0)->text();

            DialogRejet setRaisonRejet;
            if(setRaisonRejet.exec()==QDialog::Accepted)
            {
                raisonRejet = setRaisonRejet.getTexteRejet();
                raisonRejet.replace("'","''");

                req = "UPDATE producteur SET statut = 2 WHERE numeroProducteur = "+numProducteur;
                QSqlQuery query(req);

                req = "SELECT MAX(numeroRejet) FROM rejet";
                QSqlQuery query_2(req);
                query_2.next();
                int numRejet = query.value(0).toInt()+1;

                req = "INSERT INTO rejet VALUES("+QString::number(numRejet)+",'"+raisonRejet+"',"+numUtilisateur+","+numProducteur+")";
                QSqlQuery query_3(req);
            }
        }
    }
    if(nbChecked == 0)
    {
        ui->statusbar->setStyleSheet("color:rgb(252, 62, 62)");
        ui->statusbar->showMessage("Aucune case cochée !",3000);
    }

    afficherProducteurs();
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonModifierInfoUser_clicked()
{
    DialogModifUser modifierInfo;
    modifierInfo.setData(numUtilisateur, loginUtilisateur, MdpUtilisateur, adresseUtilisateur, telUtilisateur, mailUtilisateur);
    if(modifierInfo.exec()==QDialog::Accepted)
    {
        QSqlQuery query(modifierInfo.getRequete());
        ui->lineEditConnexionLogin->clear();
        ui->lineEditConnexionMDP->clear();
        ui->tabWidgetAction->setVisible(false);

        ui->labelInfoNom->setText("");
        ui->labelInfoPrenom->setText("");
        ui->labelInfoRole->setText("");
        ui->labelInfoMail->setText("");
        ui->labelInfoTel->setText("");
        ui->labelInfoAdresse->setText("");
        ui->pushButtonModifierInfoUser->setVisible(false);

        ui->lineEditConnexionLogin->setText(modifierInfo.getLogin());
        ui->lineEditConnexionMDP->setText(modifierInfo.getMDP());

        ui->statusbar->setStyleSheet("color:rgb(62, 190, 62)");
        ui->statusbar->showMessage("Informations de l'utilisateur modifiées avec succès.",5000);

        connexion();
    }

}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonDeconnexion_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonDeconnexion_clicked()";
    ui->lineEditConnexionLogin->clear();
    ui->lineEditConnexionMDP->clear();
    connexion();
    ui->pushButtonDeconnexion->setVisible(false);
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonAjoutRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjoutRayon_clicked()";
    req = "SELECT MAX(numeroRayon)+1 FROM rayon";
    QSqlQuery max(req);
    max.next();
    numRayon = max.value(0).toString();

    DialogAjoutRayon ajoutRayon;
    if(ajoutRayon.exec()==QDialog::Accepted)
    {
        nomRayon = ajoutRayon.getNom();

        req = "INSERT INTO rayon VALUES("+numRayon+",'"+nomRayon+"')";
        qDebug()<<req;
        QSqlQuery ajout(req);

        afficherRayons();
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonAjoutProduit_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonAjoutProduit_clicked()";
    req = "SELECT MAX(numeroProduit)+1 FROM produit";
    QSqlQuery max(req);
    max.next();
    numProduit = max.value(0).toString();

    DialogAjoutProduit ajoutProduit;
    if(ajoutProduit.exec()==QDialog::Accepted)
    {
        nomProduit = ajoutProduit.getNom();
        numRayon = ajoutProduit.getNumRayon();

        req = "INSERT INTO produit VALUES ("+numProduit+",'"+nomProduit+"',"+numRayon+")";
        qDebug()<<req;
        QSqlQuery ajoutrProduit(req);

        afficherProduits();
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonModifRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifRayon_clicked()";
    int ligne = ui->tableWidgetRayon->rowCount()-1;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetRayon->cellWidget(noLigne,2)))->isChecked())
        {
            DialogModifRayon modifRayon;
            modifRayon.setData(ui->tableWidgetRayon->item(noLigne,1)->text());
            if(modifRayon.exec()==QDialog::Accepted)
            {
                numRayon = ui->tableWidgetRayon->item(noLigne,0)->text();
                nomRayon = modifRayon.getNom();

                req = "UPDATE rayon SET nomRayon = '"+nomRayon+"' WHERE numeroRayon = "+numRayon;
                QSqlQuery modif(req);
                qDebug()<<req;
            }
        }
    }
    afficherRayons();
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonSuppRayon_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonSuppRayon_clicked()";
    int ligne = ui->tableWidgetRayon->rowCount()-1;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetRayon->cellWidget(noLigne,2)))->isChecked())
        {
            QString texteMessage = ui->tableWidgetRayon->item(noLigne,1)->text()+" - Voulez vous vraiment supprimer ce rayon ?";
            if(QMessageBox::warning(this,this->windowTitle(),texteMessage, QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)//Si l'utilisateur clique sur "oui"
            {
                numRayon = ui->tableWidgetRayon->item(noLigne,0)->text();
                req = "DELETE FROM rayon WHERE numeroRayon = "+numRayon;
                qDebug()<<req;
                QSqlQuery deleteRayon(req);

                QString errorMessage=deleteRayon.lastError().text();
                if(errorMessage.length()>=2)
                {
                    ui->statusbar->setStyleSheet("color:rgb(252, 62, 62)");
                    ui->statusbar->showMessage("Erreur, impossible de supprimer ce rayon !",8000);
                }
                afficherRayons();
            }
        }
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/



void MainWindow::on_pushButtonModifProduit_clicked()
{
    qDebug()<<"void MainWindow::on_pushButtonModifProduit_clicked()";
    int ligne = ui->tableWidgetProduit->rowCount()-1;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetProduit->cellWidget(noLigne,3)))->isChecked())
        {
            DialogModifProduit modifProduit;
            modifProduit.setData(ui->tableWidgetProduit->item(noLigne,0)->text());
            if(modifProduit.exec()==QDialog::Accepted)
            {
                numProduit = ui->tableWidgetProduit->item(noLigne,0)->text();
                nomProduit = modifProduit.getNom();
                numRayon = modifProduit.getNum();

                req = "UPDATE produit SET nomProduit = '"+nomProduit+"',numeroRayon = "+numRayon+" WHERE numeroProduit = "+numProduit;
                QSqlQuery modifProduit(req);

                afficherProduits();
            }
        }
    }
}


/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/
/*****************************************************************************************************************************************************/


void MainWindow::on_pushButtonSuppProduit_clicked()
{
    int ligne = ui->tableWidgetProduit->rowCount()-1;
    for (int noLigne = ligne;noLigne >= 0;noLigne--)
    {
        if(((QCheckBox*)(ui->tableWidgetProduit->cellWidget(noLigne,3)))->isChecked())
        {
            QString texteMessage = ui->tableWidgetProduit->item(noLigne,1)->text()+" - Voulez vous vraiment supprimer ce produit ?";
            if(QMessageBox::warning(this,this->windowTitle(),texteMessage, QMessageBox::Yes|QMessageBox::No)==QMessageBox::Yes)//Si l'utilisateur clique sur "oui"
            {
                numProduit = ui->tableWidgetProduit->item(noLigne,0)->text();
                req = "DELETE FROM produit WHERE numeroproduit = "+numProduit;
                qDebug()<<req;
                QSqlQuery deleteProduit(req);

                QString errorMessage=deleteProduit.lastError().text();
                if(errorMessage.length()>=2)
                {
                    ui->statusbar->setStyleSheet("color:rgb(252, 62, 62)");
                    ui->statusbar->showMessage("Erreur, impossible de supprimer ce produit !",8000);
                }
                afficherProduits();
            }
        }
    }
}

