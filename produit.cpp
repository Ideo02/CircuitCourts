#include "produit.h"
#include <QDebug>

Produit::Produit(QString sonId, QString sonNom, QString sesInfos, QString sonImage, QString saQuantite)
{
    qDebug()<<"Produit::Produit(QString sonId, QString sonNom, QString sesInfos, QString sonImage, QString saQuantite)";
    idProduit = sonId;
    libProduit = sonNom;
    infoProduit = sesInfos;
    imageProduit = sonImage;
    quantiteProduit = saQuantite;
}

Produit::Produit()
{

}

QString Produit::versChaine()
{
    qDebug()<<"QString Produit::versChaine()";
    QString resultat;
    resultat += "<p><h3>Produit : </h3>"+libProduit+"</p>";
    resultat += "<p><h3>Informations : </h3>"+infoProduit+"</p>";
    resultat += "<p><img src='"+imageProduit+"'></p>";
    resultat += "<p><h3>Quantité : </h3>"+quantiteProduit+"</p>";
    qDebug()<<resultat;
    return resultat;
}
