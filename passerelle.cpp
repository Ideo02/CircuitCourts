#include "passerelle.h"
#include "jeuenregistrement.h"
//#include "equipement.h"
//#include "bateauvoyageur.h"
#include <QDebug>

Passerelle::Passerelle()
{

}

QVector<Rayon> Passerelle::chargerLesRayons(QString idProducteur)
{
    qDebug()<<"QVector<Rayon> Passerelle::chargerLesRayons()";
    QVector<Rayon> resultat;
    //on remplit le vector
    JeuEnregistrement monJeu("SELECT DISTINCT rayon.numeroRayon,rayon.nomRayon FROM rayon INNER JOIN variete ON rayon.numeroRayon = variete.numeroRayon INNER JOIN produit ON variete.numeroVariete = produit.numeroVariete INNER JOIN Produire ON produit.numeroProduit = Produire.numeroProduit WHERE Produire.numeroProducteur = "+idProducteur);

    while(!monJeu.fin())
    {
        qDebug()<<"next()";
        QString sonId = monJeu.value("numeroRayon").toString();
        QString sonNom = monJeu.value("nomRayon").toString();

        QVector<Variete> sesVarietes;
        sesVarietes = chargerLesVarietes(sonId,idProducteur);
        Rayon unRayon(sonId,sonNom,sesVarietes);
        resultat.append(unRayon);
        monJeu.suivant();
    }
    return resultat;
}


QVector<Variete> Passerelle::chargerLesVarietes(QString idRayon, QString idProducteur)
{
    qDebug()<<"QVector<Variete> Passerelle::chargerLesVarietes(QString sonId)";
    QVector<Variete> resultat;
    JeuEnregistrement monJeu("SELECT variete.numeroVariete,variete.nomVariete FROM variete INNER JOIN produit ON variete.numeroVariete = produit.numeroVariete INNER JOIN Produire ON produit.numeroProduit = Produire.numeroProduit WHERE Produire.numeroProducteur = "+idProducteur+" AND numeroRayon = "+idRayon);
    while(!monJeu.fin())
    {
        QString idVariete = monJeu.value("numeroVariete").toString();
        QString nomVariete = monJeu.value("nomVariete").toString();
        //obtenir le vecteur des produits correspondants à la variété et vendus par le producteur
        QVector<Produit> sesProduits;
        sesProduits = chargerLesProduits(idVariete,idProducteur);
        Variete uneVariete(idVariete,nomVariete,sesProduits);
        resultat.append(uneVariete);
        monJeu.suivant();
    }
    return resultat;
}


QVector<Produit> Passerelle::chargerLesProduits(QString idVariete,QString idProducteur)
{
    qDebug()<<"QVector<Produit> Passerelle::chargerLesProduits(QString sonId)";
    QVector<Produit> resultat;
    QString req = "SELECT produit.numeroProduit,produit.nomProduit,produit.informationProduit,produit.imageProduit,(SELECT quantite FROM Produire WHERE numeroProduit = produit.numeroProduit AND numeroProducteur = "+idProducteur+") as laQuantite FROM produit INNER JOIN Produire ON produit.numeroProduit = Produire.numeroProduit WHERE Produire.numeroProducteur = "+idProducteur+" AND numeroVariete = "+idVariete;
    qDebug()<<req;
    JeuEnregistrement monJeu(req);

    while(!monJeu.fin())
    {
        QString idProduit = monJeu.value("numeroProduit").toString();
        QString nomProduit = monJeu.value("nomProduit").toString();
        QString infoProduit = monJeu.value("informationProduit").toString();
        QString imageProduit = monJeu.value("imageProduit").toString();
        //qDebug()<<"image = "<<imageProduit;
        QString quantiteProduit = monJeu.value("laQuantite").toString();
        Produit unProduit(idProduit,nomProduit,infoProduit,imageProduit,quantiteProduit);
        resultat.append(unProduit);
        monJeu.suivant();
    }
    return resultat;
}















/*
  SELECT DISTINCT rayon.numeroRayon FROM rayon INNER JOIN variete
  ON rayon.numeroRayon = variete.numeroRayon INNER JOIN produit
  ON variete.numeroVariete = produit.numeroVariete INNER JOIN Produire
  ON produit.numeroProduit = Produire.numeroProduit
  WHERE Produire.numeroProducteur = 1;

  INSERT INTO typeAbonnement VALUES(1,"Classique",90,3);
  INSERT INTO abonnement VALUES(1,"2021-12-01","2022-03-01",1);
  INSERT INTO producteur VALUES(1,"ncasanelli","Casanelli","Nolann","12 rue des papillotes","06 99 66 99 66","motdepasse","2014-03-31",1);
  INSERT INTO unite VALUES(1,"kg");
  INSERT INTO semaine VALUES("2021-11-29","2021-12-05");
  INSERT INTO Produire VALUES(15,16.99,1,5,"2021-11-29",1);
*/

