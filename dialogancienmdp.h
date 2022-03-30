#ifndef DIALOGANCIENMDP_H
#define DIALOGANCIENMDP_H

#include <QDialog>

namespace Ui {
class DialogAncienMDP;
}

class DialogAncienMDP : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAncienMDP(QWidget *parent = nullptr);

    QString motDePasse;

    void setAncienMDP(QString ancienMDP);

    ~DialogAncienMDP();

private slots:
    void on_pushButtonValider_clicked();

    void on_pushButtonAnnuler_clicked();

    void on_lineEditMDP_textEdited(const QString &arg1);

private:
    Ui::DialogAncienMDP *ui;
};

#endif // DIALOGANCIENMDP_H
