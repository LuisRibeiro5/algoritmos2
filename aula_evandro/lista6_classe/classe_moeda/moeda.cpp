#include "moeda.h"
#include <iostream>
#include <random>
#include <cstring>

Moeda::Moeda() : distr_int(0,11), lado_pra_cima(nullptr) {
    jogar();
}

void Moeda::jogar(){
    int num = distr_int(gen);
    set_lado(num);
}

void Moeda::set_lado(int num){
    if (lado_pra_cima != nullptr){
        delete[] lado_pra_cima;
    }
    
    if (num % 2 == 0){

        lado_pra_cima = new char[5];
        strcpy(lado_pra_cima,"cara");

    }else{
        lado_pra_cima = new char[6];
        strcpy(lado_pra_cima,"coroa");
    }
}

char* Moeda::get_lado(){
    return lado_pra_cima;
}

Moeda::~Moeda(){
    delete[] lado_pra_cima;
}