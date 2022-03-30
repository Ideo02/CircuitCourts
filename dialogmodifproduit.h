#ifndef DIALOGMODIFPRODUIT_H
#define DIALOGMODIFPRODUIT_H

#include <QDialog>

namespace Ui {
class DialogModifProduit;
}

class DialogModifProduit : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifProduit(QWidget *parent = nullptr);

    QString req,numProduit,nomProduit,numRayon,nomRayon;
    QList<QString> listeNumero;

    QString getNom();
    QString getNum();

    void setData(QString num);

    ~DialogModifProduit();

private slots:
    void on_lineEditNom_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButtonValider_clicked();

private:
    Ui::DialogModifProduit *ui;
};

#endif // DIALOGMODIFPRODUIT_H
