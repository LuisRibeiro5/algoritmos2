/*Criar uma função que determine se um caractere, recebido como parâmetro, é ou não uma letra do alfabeto. A 
função deve retornar 1 caso positivo e 0 em caso contrário. Crie também um programa para testar tal função.*/
#include <iostream>

bool eCaracter(const char[]);

int main(){
    char letra;
    std::cout << eCaracter("Digite uma letra\n") << "\n";
}

bool eCaracter(const char msg[]){
    std::cout << msg;
    char letra; std::cin >> letra;
    return isalpha(letra);
};
