#ifndef PDF_H
#define PDF_H
#include <QTextBrowser>
#include <QString>


class PDF : public QTextBrowser
{
private:
    QString nomDoc;
public:
    PDF(QWidget * parent);
    void ecrireTexte(QString leTexte);
    void chargerImage(QString chemin);
    void fermer();
    void setName(QString nomDocument);
};

#endif // PDF_H
