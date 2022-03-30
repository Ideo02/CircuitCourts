#ifndef DIALOGAJOUTRAYON_H
#define DIALOGAJOUTRAYON_H

#include <QDialog>

namespace Ui {
class DialogAjoutRayon;
}

class DialogAjoutRayon : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAjoutRayon(QWidget *parent = nullptr);

    QString nom;

    QString getNom();

    ~DialogAjoutRayon();

private slots:
    void on_lineEditNom_textEdited(const QString &arg1);

    void on_pushButtonValider_clicked();

private:
    Ui::DialogAjoutRayon *ui;
};

#endif // DIALOGAJOUTRAYON_H
