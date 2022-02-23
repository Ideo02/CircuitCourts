#ifndef PASSERELLE_H
#define PASSERELLE_H
#include "rayon.h"
#include "produit.h"
#include <QVector>

class Passerelle
{
public:
    Passerelle();
    static QVector<Rayon> chargerLesRayons(QString idProducteur);
    static QVector<Produit> chargerLesProduits(QString idVariete,QString idProducteur);
    static QVector<Variete> chargerLesVarietes(QString idRayon,QString idProducteur);
};

#endif // PASSERELLE_H
