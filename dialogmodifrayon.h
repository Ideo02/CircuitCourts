#ifndef DIALOGMODIFRAYON_H
#define DIALOGMODIFRAYON_H

#include <QDialog>

namespace Ui {
class DialogModifRayon;
}

class DialogModifRayon : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifRayon(QWidget *parent = nullptr);

    QString nom;

    QString getNom();

    void setData(QString nomRayon);

    ~DialogModifRayon();

private slots:
    void on_lineEditNom_textEdited(const QString &arg1);

    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogModifRayon *ui;
};

#endif // DIALOGMODIFRAYON_H
