#ifndef DIALOGAJOUTPRODUIT_H
#define DIALOGAJOUTPRODUIT_H

#include <QDialog>

namespace Ui {
class DialogAjoutProduit;
}

class DialogAjoutProduit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjoutProduit(QWidget *parent = nullptr);

    QString req,nomProduit,nomRayon,numRayon;

    QList<QString> listeNumero;

    QString getNom();

    QString getNumRayon();

    ~DialogAjoutProduit();

private slots:
    void on_lineEditNom_textEdited(const QString &arg1);

    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogAjoutProduit *ui;
};

#endif // DIALOGAJOUTPRODUIT_H
