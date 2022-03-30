#include "dialogancienmdp.h"
#include "ui_dialogancienmdp.h"
#include <QDebug>

DialogAncienMDP::DialogAncienMDP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAncienMDP)
{
    qDebug()<<"DialogAncienMDP::DialogAncienMDP(QWidget *parent)";
    ui->setupUi(this);
    ui->labelIncorrect->setVisible(false);
    ui->pushButtonValider->setEnabled(false);
}

void DialogAncienMDP::setAncienMDP(QString ancienMDP)
{
    qDebug()<<"void DialogAncienMDP::setAncienMDP(QString ancienMDP)";
    motDePasse = ancienMDP;
}

DialogAncienMDP::~DialogAncienMDP()
{
    qDebug()<<"DialogAncienMDP::~DialogAncienMDP()";
    delete ui;
}

void DialogAncienMDP::on_pushButtonValider_clicked()
{
    qDebug()<<"void DialogAncienMDP::on_pushButtonValider_clicked()";
    if(ui->lineEditMDP->text()==motDePasse)
    {
        ui->labelIncorrect->setVisible(false);
        accept();
    }
    else
    {
        ui->labelIncorrect->setVisible(true);
    }
}


void DialogAncienMDP::on_pushButtonAnnuler_clicked()
{
    qDebug()<<"void DialogAncienMDP::on_pushButtonAnnuler_clicked()";
    reject();
}


void DialogAncienMDP::on_lineEditMDP_textEdited(const QString &arg1)
{
    qDebug()<<"void DialogAncienMDP::on_lineEditMDP_textEdited(const QString &arg1)";
    if(ui->lineEditMDP->text()!="")
    {
        ui->pushButtonValider->setEnabled(true);
    }
    else
    {
        ui->pushButtonValider->setEnabled(false);
    }
}

