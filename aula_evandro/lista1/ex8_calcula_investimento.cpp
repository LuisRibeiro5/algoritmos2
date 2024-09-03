#include <iostream>
#include <string>
#include <cmath>

double valorPresente(float, float, int);

int main(){
    std::cout << "esse é um programa que te permite digitar um valor de investimento presente, colocar quanto voce que chegar  e em quanto tempo voce alcancar esse dinheiro, dependendo da taxa de juros. O programa retorna o valor que voce deve investir para alcancar o valor que voce quer chegar.\n";

    float valorFuturo, taxaAnual;
    int anos;

    do{
        std::cout << "digite o valor futuro que quer ter: \n";
        std::cin >> valorFuturo;
    }while(valorFuturo <= 0);
    
    do
    {
        std::cout << "digite o valor da taxa anual em porcentagem, ex: 10 para representar 10% \n";
        std::cin >> taxaAnual;
        taxaAnual /= 100;
    } while (taxaAnual <= 0);

    do
    {
        std::cout << "digite em quantos anos quer alcancar esse valor \n";
        std::cin >> anos;
    } while (anos < 0);

    double investimento = valorPresente(valorFuturo,taxaAnual,anos);

    std::cout << "Para alcancar sua meta voce precisa investir " << investimento <<  "\n";

    return 0;
}

double valorPresente(float valorFuturo, float taxaAnual, int anos){
    double valorPresente;
    valorPresente = valorFuturo / (std::pow((1 + taxaAnual),anos));
    return valorPresente;
};