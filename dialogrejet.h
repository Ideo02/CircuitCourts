#ifndef DIALOGREJET_H
#define DIALOGREJET_H

#include <QDialog>
#include <QDebug>

namespace Ui {
class DialogRejet;
}

class DialogRejet : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRejet(QWidget *parent = 0);
    QString texte;

    QString getTexteRejet();
    ~DialogRejet();



private slots:
    void on_textEditRejet_textChanged();

    void on_pushButtonOk_clicked();

    void on_pushButtonAnnuler_clicked();

private:
    Ui::DialogRejet *ui;
};

#endif // DIALOGREJET_H
