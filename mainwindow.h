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
    QString loginUtilisateur, MdpUtilisateur, req, numTypeUtilisateur, numUtilisateur, libelleTypeUtilisateur, nomUtilisateur, prenomUtilisateur, mailUtilisateur, telUtilisateur;
    QString numProducteur,loginProducteur,nomProducteur,prenomProducteur,adresseProducteur,telProducteur,mdpProducteur,dateInscriptionProducteur;
    int nb;
    ~MainWindow();

private slots:
    void on_lineEditConnexionLogin_textEdited(const QString &arg1);

    void on_pushButtonConnexion_clicked();

    void afficherProducteurs();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
