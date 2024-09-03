/*Escreva um procedimento que receba um número inteiro e o imprima na forma extensa (p.ex. para 1 a saída 
desejada é “Um”). O código deve gerar o extenso dos números de 0 até 10, inclusive. Caso um número não 
compatível seja recebido, deve-se mostrar uma mensagem de erro. Crie também um programa que leia um valor 
inteiro e chame o procedimento criado para mostrar o número extenso. */
#include <iostream>

void recebeInteiroPositivo(int&);
void formaExtensa(int);

int main(){
    int num;
    recebeInteiroPositivo(num);
    formaExtensa(num);

    return 0;
}

void recebeInteiroPositivo(int& num){
    do
    {
        std::cout << "numero de 0 a 10\n";
        std::cin >> num;
    } while (num < 0);
};

void formaExtensa(int num){
    if(num > 10) std::cout << "erro\n";
    else{
        std::string nums[] = {"\"zero\"","\"um\"","\"dois\"","\"tres\"","\"quatro\"","\"cinco\"","\"seis\"","\"sete\"","\"oito\"","\"nove\"","\"dez\"",};
        std::cout << nums[num];
    }
    
};

