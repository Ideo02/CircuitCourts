#ifndef DIALOGMODIFUSER_H
#define DIALOGMODIFUSER_H

#include <QDialog>

namespace Ui {
class DialogModifUser;
}

class DialogModifUser : public QDialog
{
    Q_OBJECT

public:
    explicit DialogModifUser(QWidget *parent = nullptr);

    QString motDePasseUser,loginUser,mailUser,adresseUser,telUser,numUser,requete;

    void setData(QString num,QString login, QString MDP, QString adresse, QString tel, QString mail);

    QString getRequete();

    QString getLogin();

    QString getMDP();

    ~DialogModifUser();

private slots:


    void on_pushButtonModifMDP_clicked();

    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();


    private:
    Ui::DialogModifUser *ui;
};

#endif // DIALOGMODIFUSER_H
