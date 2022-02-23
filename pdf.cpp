#include "pdf.h"
#include <QPagedPaintDevice>
#include <QPdfWriter>
#include <QDebug>


PDF::PDF(QWidget *parent):QTextBrowser(parent)
{
    qDebug()<<"PDF::PDF(QWidget *parent):QTextBrowser(parent)";
}

void PDF::ecrireTexte(QString leTexte)
{
    qDebug()<<"void PDF::ecrireTexte(QString leTexte)";
    //écrit le texte
    setHtml(toHtml()+"<p>"+leTexte+"</p>");
}

void PDF::chargerImage(QString chemin)
{
    qDebug()<<"void PDF::chargerImage(QString chemin)";
    //écrit l'image
    setHtml(toHtml()+"<img src = \""+chemin+"\"/>");
}

void PDF::fermer()
{
    qDebug()<<"void PDF::fermer()";
    //ferme le PDF en l'enregistrant
    QPdfWriter* printer = new QPdfWriter(nomDoc);
    printer->newPage();
    printer->setTitle("Circuit Courts : Catalogue des produits");
    printer->setPageSize(QPagedPaintDevice::A4);
    print(printer);
}

void PDF::setName(QString nomDocument)
{
    qDebug()<<"void PDF::setName(QString nomDocument)";
    nomDoc = nomDocument;
}
