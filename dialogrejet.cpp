#include "dialogrejet.h"
#include "ui_dialogrejet.h"

DialogRejet::DialogRejet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogRejet)
{
    ui->setupUi(this);

    ui->pushButtonOk->setEnabled(false);

}

QString DialogRejet::getTexteRejet()
{
    return texte;
}

DialogRejet::~DialogRejet()
{
    delete ui;
}

void DialogRejet::on_textEditRejet_textChanged()
{
    texte = ui->textEditRejet->toPlainText();
    if(texte != "")
        ui->pushButtonOk->setEnabled(true);
    else
        ui->pushButtonOk->setEnabled(false);
}

void DialogRejet::on_pushButtonOk_clicked()
{
    accept();
}


void DialogRejet::on_pushButtonAnnuler_clicked()
{
    reject();
}
