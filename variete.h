#ifndef VARIETE_H
#define VARIETE_H
#include <QString>
#include "jeuenregistrement.h"
#include "produit.h"
#include <QVector>

class Variete
{
private:
    QString idVariete;
    QString libVariete;
    QVector<Produit> sesProduits;
public:
    Variete(QString sonId,QString sonLibelle,QVector<Produit> uneCollecProduit);
    Variete();
    QString versChaine();

};

#endif // VARIETE_H
