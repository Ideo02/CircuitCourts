#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString loginUtilisateur, MdpUtilisateur, req, numTypeUtilisateur, numUtilisateur, libelleTypeUtilisateur, nomUtilisateur, prenomUtilisateur, mailUtilisateur, telUtilisateur, adresseUtilisateur;
    QString numProducteur,loginProducteur,nomProducteur,prenomProducteur,adresseProducteur,telProducteur,mdpProducteur,dateInscriptionProducteur,valide;
    QString numRayon,nomRayon,numProduit,nomProduit;
    QString raisonRejet;
    int nb;
    ~MainWindow();

private slots:
    void on_lineEditConnexionLogin_textEdited(const QString &arg1);

    void on_pushButtonConnexion_clicked();

    void afficherProducteurs();

    void afficherTableauDeBord();

    void afficherRayons();

    void afficherProduits();

    void on_pushButtonValiderProducteur_clicked();

    void on_pushButtonRejeterProducteur_clicked();

    void on_pushButtonModifierInfoUser_clicked();

    void connexion();

    void on_lineEditConnexionMDP_textEdited(const QString &arg1);

    void on_pushButtonDeconnexion_clicked();

    void on_pushButtonAjoutRayon_clicked();

    void on_pushButtonAjoutProduit_clicked();

    void on_pushButtonModifRayon_clicked();

    void on_pushButtonSuppRayon_clicked();

    void on_pushButtonModifProduit_clicked();

    void on_pushButtonSuppProduit_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
