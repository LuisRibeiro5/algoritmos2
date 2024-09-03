#include <iostream>

float calcula_preco(float valor, float porcentagem){
    porcentagem /= 100;
    float lucro = valor * porcentagem;
    return valor + lucro;
}

int main(){
    float valor,porcentagem;
    do
    {
        std::cout << "Qual o custo do item? " << std::endl;
        std::cin >> valor;
    } while (valor < 0);
    do
    {
        std::cout << "Qual a porcentagem de lucro do item? " << std::endl;
        std::cin >> porcentagem;
    } while (porcentagem <= 0);

    float preco_varejo = calcula_preco(valor,porcentagem);
    
    std::cout << "O preco de varejo é " << preco_varejo << std::endl;
    
    return 0;

}