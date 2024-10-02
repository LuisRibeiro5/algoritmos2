#include "notas.h"
#include <iostream>

Notas::Notas(){
    for (int i = 0; i < 3; i++){
        notas[i] = 0.0;
    }
}

Notas::Notas(int idx, double nota){
    set_nota(idx,nota);
}

double Notas::obter_nota(int idx) const{
    return notas[idx];
}

void Notas::set_nota(int idx, double nota){
    if (idx >= 0 && idx < 3)
    {
        notas[idx] = nota > 0 ? nota : 0.0;
    }

}

double Notas::media_notas(){
    double soma = 0;
    for (int i = 0; i < 3; i++)
    {
        soma += notas[i];
    }
    
    return soma / 3;
}