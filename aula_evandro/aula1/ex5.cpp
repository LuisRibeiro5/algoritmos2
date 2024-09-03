#include <iostream>

bool ehPrimo(int);
void listarPrimos(int);

int main(){
    int n;
    do{
        std::cout << "Digite um numero maior que 1 para verificar " << std::endl;
        std::cin >> n;
    }while(n < 2);
    
    listarPrimos(n);

    return 0;
}

bool ehPrimo(int numero){
    bool ehPrimo = true;
    for(int i= 2; i < numero/2 + 1; i++){
        if(numero % i == 0){
            ehPrimo = false;
            break;
        }
    }

    return ehPrimo;
}

void listarPrimos(int numero){
    std::string numeros = "";
    for(int i = 0; i <= numero; i++){
        if(ehPrimo(i)){
            std::cout << i + ", ";
        }
    }
}
