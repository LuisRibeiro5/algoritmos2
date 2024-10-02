#pragma once
#include <iostream>

class Notas {

private:
    double notas[3];

public:
    Notas(/* args */);
    Notas(int,double);
    
    double obter_nota(int) const;
    void set_nota(int,double);

    double media_notas();
};