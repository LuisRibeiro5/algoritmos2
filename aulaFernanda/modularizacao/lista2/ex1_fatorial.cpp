/*Faça um programa que leia um número inteiro n maior ou igual a zero e calcule o fatorial de n (usualmente escrito como n!). O fatorial é calculado como o produto n * (n -1) * (n - 2) * ... * 2 * 1. Isto nada mais é do que uma série de multiplicações repetidas, onde o multiplicador é reduzido de 1 antes de cada multiplicação. Defina uma função para calcular o fatorial. */
#include <iostream>

int leNumPositivo();
int calculaFatorial(int);

int main(){
    int n = leNumPositivo();
    int fatN = calculaFatorial(n);

    std::cout << "O fatorial de " << n << " é " << fatN;

    return 0;
}

int leNumPositivo(){
    int n;
    do
    {
        std::cout << "digite um numero positivo: ";
        std::cin >> n;
    } while (n < 0);
    return n;
};

int calculaFatorial(int num){
    if(num == 1 || num == 0){
        return 1;
    }
    return num * calculaFatorial(num - 1);
};

