#include "circulo.h"
#include <iostream>

int main(){
    Circulo c(2);

    std::cout  << c.get_raio() << "\n";
    std::cout  << c.get_area() << "\n";
    std::cout  << c.get_diametro() << "\n";
    std::cout  << c.get_circunferencia() << "\n";

    return 0;
}