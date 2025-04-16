#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kalkulator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton0_clicked();
    void on_pushButton1_clicked();
    void on_pushButton2_clicked();
    void on_pushButton3_clicked();
    void on_pushButton4_clicked();
    void on_pushButton5_clicked();
    void on_pushButton6_clicked();
    void on_pushButton7_clicked();
    void on_pushButton8_clicked();
    void on_pushButton9_clicked();

    void on_pushButtonDodaj_clicked();
    void on_pushButtonOdejmij_clicked();
    void on_pushButtonMnoz_clicked();
    void on_pushButtonDziel_clicked();
    void on_pushButtonModulo_clicked();

    void on_pushButtonRownaSie_clicked();
    void on_pushButtonClear_clicked();

    void on_przecinek_clicked();
    void aktualizujSystemyLiczbowe(QString tekstLiczby);

    void on_pushButtonkon_clicked();

    void on_pushButtoni_clicked();

private:
    Ui::MainWindow *ui;
    QString aktualnyTekst;
    double pierwszaLiczba = 0;
    QString operacja;
    Kalkulator kalkulator;
};
#endif // MAINWINDOW_H
