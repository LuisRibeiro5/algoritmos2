/*Faça um programa que recebe uma string A e inteiros positivos I e J e mostre o 
segmento A[I..J].*/
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

int main(){
    std::string stringA;
    do
    {
        std::cout << "Digite uma frase " << std::endl;
        std::getline(std::cin,stringA);
    } while (stringA == "");

    int tam = stringA.size();

    std::cout << "Digite um intervalo de 1 até " << tam << ", sendo i o comeco do intervalo e j o final." << std::endl;

    int comeco,fim;
    do
    {
        std::cout << "Digite o comeco do intervalo, i= "; std::cin >> comeco;
    } while (comeco <= 0);

    do
    {
        std::cout << "Digite o final do intervalo, j= "; std::cin >> fim;
        if(fim <= comeco) std::cout << "j nao pode ser menor que i" << std::endl;
        if(fim > tam) std::cout << "j nao pode ser maior que " << tam <<std::endl;
    } while (fim <= comeco || fim > tam);
    
    std::cout << stringA.substr(comeco - 1, fim - comeco + 1) << "\n";

    // for (int i = comeco; i <= fim; i++)
    // {
    //     std::cout << stringA.at(i);
    // }
    
    return 0;
    
}