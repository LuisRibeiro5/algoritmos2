#pragma once

class Circulo
{
private:
    double raio;
    double pi;

public:
    Circulo(/* args */);
    Circulo(double);
    
    void set_raio(double);
    double get_raio() const;
    double get_area() const;
    double get_diametro() const;
    double get_circunferencia() const;
    
};
