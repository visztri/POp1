#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lcdNumber->display("0");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton0_clicked(){
    aktualnyTekst += "0"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton1_clicked(){
    aktualnyTekst += "1"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton2_clicked(){
    aktualnyTekst += "2"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton3_clicked(){
    aktualnyTekst += "3"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton4_clicked(){
    aktualnyTekst += "4"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton5_clicked(){
    aktualnyTekst += "5"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton6_clicked(){
    aktualnyTekst += "6"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton7_clicked(){
    aktualnyTekst += "7"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton8_clicked(){
    aktualnyTekst += "8"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_pushButton9_clicked(){
    aktualnyTekst += "9"; ui->lcdNumber->display(aktualnyTekst);
}
void MainWindow::on_przecinek_clicked(){
   aktualnyTekst += "."; ui->lcdNumber->display(aktualnyTekst);
}

void MainWindow::on_pushButtonClear_clicked() {
    ui->wysop->setText("");
    ui->memory->display("0");
    aktualnyTekst = "";
    pierwszaLiczba = 0;
    operacja = "";
    ui->lcdNumber->display("0");
}

void MainWindow::on_pushButtonDodaj_clicked() {
    ui->wysop->setText("+");
    pierwszaLiczba = aktualnyTekst.toDouble();
    aktualnyTekst = "";
    operacja = "+";
}

void MainWindow::on_pushButtonOdejmij_clicked() {
    ui->wysop->setText("-");
    pierwszaLiczba = aktualnyTekst.toDouble();
    aktualnyTekst = "";
    operacja = "-";
}

void MainWindow::on_pushButtonMnoz_clicked() {
    ui->wysop->setText("*");
    pierwszaLiczba = aktualnyTekst.toDouble();
    aktualnyTekst = "";
    operacja = "*";
}

void MainWindow::on_pushButtonDziel_clicked() {
    ui->wysop->setText("/");
    pierwszaLiczba = aktualnyTekst.toDouble();
    aktualnyTekst = "";
    operacja = "/";
}

void MainWindow::on_pushButtonModulo_clicked() {
    ui->wysop->setText("%");
    pierwszaLiczba = aktualnyTekst.toDouble();
    aktualnyTekst = "";
    operacja = "%";
}

void MainWindow::on_pushButtonRownaSie_clicked() {
    ui->wysop->setText("");
    double drugaLiczba = aktualnyTekst.toDouble();
    double wynik = 0;

    if (operacja == "+") wynik = kalkulator.dodaj(pierwszaLiczba, drugaLiczba);
    else if (operacja == "-") wynik = kalkulator.odejmij(pierwszaLiczba, drugaLiczba);
    else if (operacja == "*") wynik = kalkulator.mnoz(pierwszaLiczba, drugaLiczba);
    else if (operacja == "/"){
        if(drugaLiczba==0){
            QMessageBox::critical(this, "Błąd dzielenia", "Nie mozna dzielić przez 0!");
            wynik = pierwszaLiczba;
        }else wynik = kalkulator.dziel(pierwszaLiczba, drugaLiczba);
    }
    else if (operacja == "%"){
        if (drugaLiczba == 0) {
            QMessageBox::critical(this, "Błąd", "Nie można dzielić przez 0!");
            wynik = pierwszaLiczba;
        }
        else wynik = kalkulator.modulo(pierwszaLiczba, drugaLiczba);
    }
    ui->lcdNumber->display(QString::number(wynik));
    ui->memory->display(QString::number(wynik));
    aktualnyTekst = QString::number(wynik);
}

void MainWindow::aktualizujSystemyLiczbowe(QString tekstLiczby) {
    bool ok;
    int liczba = tekstLiczby.toInt(&ok, 10);

    if (!ok) {
        ui->lineEditbin->setText("Błąd");
        ui->lineEditoct->setText("Błąd");
        ui->lineEdithex->setText("Błąd");
        return;
    }

    ui->lineEditbin->setText(QString::number(liczba, 2));
    ui->lineEditoct->setText(QString::number(liczba, 8));
    ui->lineEdithex->setText(QString::number(liczba, 16).toUpper());
}


void MainWindow::on_pushButtonkon_clicked()
{
    QString tekst = ui->lineEditdec->text();
    aktualizujSystemyLiczbowe(tekst);
}


void MainWindow::on_pushButtoni_clicked()
{
    QMessageBox::information(this, "Autor", "Autor: Jakub Hojeński\nNr indeksu: 287173");
}

