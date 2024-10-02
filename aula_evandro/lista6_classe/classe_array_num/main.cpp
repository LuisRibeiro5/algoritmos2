#include "array.h"
#include <iostream>

int main(){
    Array numeros;

    numeros.inserir_num(0,12);
    std::cout << numeros.recuperar_num(0) << std::endl;
    std::cout << numeros.maior_num() << std::endl;
    std::cout << numeros.menor_num() << std::endl;
    std::cout << numeros.media_nuns();
    numeros.inserir_num(1,12);

    int qtde;
    std::cout << "numero de pos: ";
    std::cin >> qtde;

    Array nuns(qtde);

    double num;
    for (int i = 0; i < qtde; i++)
    {
        std::cout << "num da pos " << i << ": ";
        std::cin >> num; 
        nuns.inserir_num(i,num);
    }

    std::cout << nuns.maior_num() << std::endl;
    std::cout << nuns.menor_num() << std::endl;
    std::cout << nuns.media_nuns() << std::endl;   

    for (int i = 0; i < qtde; i++)
    {
        std::cout << "\n" << nuns.recuperar_num(i);
    }
    
    return 0;
}