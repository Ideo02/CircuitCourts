#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include "jeuenregistrement.h"

class Produit
{
private:
    QString idProduit;
    QString libProduit;
    QString infoProduit;
    QString imageProduit;
    QString quantiteProduit;
public:
    Produit(QString sonId,QString sonNom,QString sesInfos,QString sonImage,QString saQuantite);
    Produit();
    QString versChaine();

};

#endif // PRODUIT_H
