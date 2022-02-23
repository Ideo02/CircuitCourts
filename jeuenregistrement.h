#ifndef JEUENREGISTREMENT_H
#define JEUENREGISTREMENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QVariant>

class JeuEnregistrement : public QSqlQuery
{
public:
    JeuEnregistrement(QString chaineSQL);
    void suivant();
    bool fin();
    QVariant getValeur(QString nomChamp);
    void fermer();
};

#endif // JEUENREGISTREMENT_H
