/*Faça uma função que verifique se um número é ou não é primo. Crie também um programa para testar tal função. 
*/
#include <iostream>

int recebeNumValido();
bool ehPrimo(int);

int main(){
    int num = recebeNumValido();
    std::cout << "é primo: \n" << ehPrimo(num) << "\n";

    return 0;
}

int recebeNumValido(){
    int num;
    do
    {
        std::cout << "digite um numero maior que 1: \n";
        std::cin >> num;
    } while (num <= 1);
    return num;
};

bool ehPrimo(int num){
    if (num <= 3)
    {
        return true;
    }
    if (num % 2 ==0 || num%3 ==0)
    {
        return false;
    }
    for (int i = 5; i * i <= num; i+6)
    {
        if (num % i == 0 || num % (i + 2) == 0)
        {
            return false;
        }
        
    }
    return true;
    
};

