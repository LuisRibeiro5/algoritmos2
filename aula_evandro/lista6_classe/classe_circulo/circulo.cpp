#include "circulo.h"
#include <iostream>

Circulo::Circulo() : raio(0), pi(3.14159) {}

Circulo::Circulo(double raio){
    set_raio(raio);
    pi = 3.14159;
}

void Circulo::set_raio(double raio) {this->raio = raio < 0 ? 0 : raio;}

double Circulo::get_raio() const {return raio;}

double Circulo::get_area() const {return pi * (raio * raio);}

double Circulo::get_diametro() const {return 2 * raio;}

double Circulo::get_circunferencia() const {return 2 * pi * raio;}