#include "variete.h"
#include <QDebug>

Variete::Variete(QString sonId,QString sonLibelle,QVector<Produit> uneCollecProduit)
{
    qDebug()<<"Variete::Variete(QString sonId,QString sonLibelle)";
    idVariete = sonId;
    libVariete = sonLibelle;
    sesProduits = uneCollecProduit;
}

Variete::Variete()
{
    qDebug()<<"Variete::Variete()";
}

QString Variete::versChaine()
{
    qDebug()<<"QString Variete::versChaine()";
    QString resultat = "<p>"+libVariete+"</p>";
    for(int no=0;no<sesProduits.size();no++)
    {
        resultat += sesProduits[no].versChaine();
    }
    return resultat;
}

