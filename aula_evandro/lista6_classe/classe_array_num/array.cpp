#include "array.h"
#include <iostream>

Array::Array(){
    Array(1);
}

Array::Array(int tam){
    this->tam = tam <= 0 ? 1 : tam;
    array = new double[this->tam]();
}

Array::~Array(){
    delete[] array;
}

void Array::inserir_num(int idx, double num){
    if (idx >= 0 && idx < tam)
    {
        array[idx] = num;
        return;
    }
    std::cout << "\nposicao invalida.";
}

double Array::recuperar_num(int idx) const{
    if (idx >= 0 && idx < tam)
    {
        return array[idx];
    }

    return -1;
}

double Array::maior_num() const{
    int idx_max = 0;
    double max = array[idx_max];

    for (int i = 1; i < tam; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
            idx_max = i;
        }
        
    }
    
    return recuperar_num(idx_max);
}

double Array::menor_num() const{
    int idx_min = 0;
    double min = array[idx_min];

    for (int i = 1; i < tam; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
            idx_min = i;
        }
        
    }
    
    return recuperar_num(idx_min);
}

double Array::media_nuns() const{
    double soma = 0;
    for (int i = 0; i < tam; i++)
    {
        soma += array[i];
    }

    return soma / tam;
}