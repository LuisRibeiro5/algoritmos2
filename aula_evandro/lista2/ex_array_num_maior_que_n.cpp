#include <iostream>

void exibe_maiores_que_n(const int [], int, int = 12);

int main(){
    int array[] = {12,123,2,4,523,324,1,4,3,24673,74,23},n;

    std::cout << "Digite um valor para n: \n";
    std::cin >> n;

    exibe_maiores_que_n(array,n);

    return 0;
}

void exibe_maiores_que_n(const int array[], int n, int tamanho){
    std::cout << "Numeors maiores que n: \n";
    for (int i = 0; i < tamanho; i++)
    {
        if(array[i] > n){
            std::cout << array[i] << "\n";
        }
    }
    
};