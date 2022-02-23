#include "jeuenregistrement.h"
#include <QDebug>

JeuEnregistrement::JeuEnregistrement(QString chaineSQL):QSqlQuery(chaineSQL)
{
    qDebug()<<"JeuEnregistrement::JeuEnregistrement(QString chaineSQL):QSqlQuery(chaineSQL)";
    //ouvre la requête et place sur le premier enregistrement
    first();
}

void JeuEnregistrement::suivant()
{
    qDebug()<<"void JeuEnregistrement::suivant()";
    next();
}

bool JeuEnregistrement::fin()
{
    qDebug()<<"bool JeuEnregistrement::fin()";
    return !isValid();
}

QVariant JeuEnregistrement::getValeur(QString nomChamp)
{
    qDebug()<<"QVariant JeuEnregistrement::getValeur(QString nomChamp)";
    return value(nomChamp);
}

void JeuEnregistrement::fermer()
{
    qDebug()<<"void JeuEnregistrement::fermer()";
    //fermeture de la requête
}
