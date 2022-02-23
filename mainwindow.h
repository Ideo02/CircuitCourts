#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString semaine;
    QString idProducteur;
    explicit MainWindow(QWidget *parent = 0);
    void getNumProd(QString arg);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void brochurePDF();
};

#endif // MAINWINDOW_H
