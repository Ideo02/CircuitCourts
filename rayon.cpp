#include "rayon.h"

Rayon::Rayon(QString unId, QString unNom, QVector<Variete> uneCollecVarietes)
{
    idRayon = unId;
    nomRayon = unNom;
    lesVarietes = uneCollecVarietes;
}

Rayon::Rayon()
{

}

QString Rayon::versChaine()
{
    QString resultat;
    resultat += "<p><h1>Rayon "+nomRayon+"</h1></p>";
    resultat += "<p><h2>Les variétés : </h2>";
    for(int no=0;no<lesVarietes.size();no++)
    {
        resultat += lesVarietes[no].versChaine();
    }
    return resultat;
}
