#ifndef DIALOGNOUVEAUMDP_H
#define DIALOGNOUVEAUMDP_H

#include <QDialog>

namespace Ui {
class DialogNouveauMDP;
}

class DialogNouveauMDP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNouveauMDP(QWidget *parent = nullptr);

    QString motDePasse;

    void setData(QString MDP);

    QString getMDP();

    ~DialogNouveauMDP();

private slots:
    void on_lineEditMDP_textEdited(const QString &arg1);

    void on_lineEditMDPConfirmer_textEdited(const QString &arg1);

    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogNouveauMDP *ui;
};

#endif // DIALOGNOUVEAUMDP_H
