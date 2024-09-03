/*Elabore um procedimento que receba um número inteiro e escreva o mês correspondente ao número. Por exemplo, 2 corresponde a “fevereiro”. Não aceitar valores inválidos. Faça um programa que leia um valor e chame o procedimento criado.*/ 
#include <iostream>

void retornaMesCorrespondente(const char[]);

int main(){
    retornaMesCorrespondente("Digite um numero de 1 á 12\n");

    return 0;
}

void retornaMesCorrespondente(const char msg[]){
    int num;
    do
    {
        std::cout << msg;
        std::cin >> num;
    } while (num <= 0);
    std::string meses[] = {"\"janeiro\"","fevereiro","marco","abril","maio","junho","julho","agosto","setembro","outubro","novembro","dezembro"};

    std::cout << meses[num - 1] << '\n';
};
