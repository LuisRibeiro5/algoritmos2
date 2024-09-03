// Faça um programa que receba uma frase e imprima esta frase de maneira invertida, 
// trocando também as letras A por *. 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int main(){
    std::string frase;
    do
    {
        std::cout << "Digite uma frase " << std::endl;
        std::getline(std::cin,frase);
    } while (empty(frase));
    
    std::string fraseInvertida;
    for(int i = frase.size() - 1; i > -1; --i){
        if(frase.at(i) == 'a' || frase.at(i) == 'A'){
            fraseInvertida += '*';
        }else {
            fraseInvertida += frase.at(i);
        }
    }

    std::cout << fraseInvertida << "\n" << std::endl;

    return 0;
}