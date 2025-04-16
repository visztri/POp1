#include "kalkulator.h"
#include <cmath>

double Kalkulator::dodaj(double a, double b) { return a + b; }
double Kalkulator::odejmij(double a, double b) { return a - b; }
double Kalkulator::mnoz(double a, double b) { return a * b; }

double Kalkulator::dziel(double a, double b) {
    return (b != 0) ? a / b : 0;
}

double Kalkulator::modulo(double a, double b) {
    return (b != 0) ? std::fmod(a, b) : 0;
}