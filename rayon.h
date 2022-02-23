#ifndef RAYON_H
#define RAYON_H
//#include "rayon.h"
#include "variete.h"
#include "produit.h"
#include <QVector>
#include <QString>
class Rayon
{
private :
    QString idRayon;
    QString nomRayon;
    QVector<Variete> lesVarietes;
    QVector<Produit> sesProduits;
public:
    Rayon(QString unId,QString unNom,QVector<Variete> uneCollecVarietes);
    Rayon();
    QString versChaine();
};

#endif // RAYON_H
