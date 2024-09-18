#include <iostream>

long double calcula_e(int);
int fatorial(int);

int main(){
    int n;
    long double e;
    do{
        std::cout << "termos a ser calculados na serie: ";
        std::cin >> n;
    }while(n < 1);

    e = calcula_e(n);
    std::cout << "\nO valor de e é " << e << "\n" ;

    return 0;
}

long double calcula_e(int n){
    double e = 1;
    std::cout << "Termo 0: 1\n"; 
    for (int i = 1; i < n; i++)
    {
        std::cout << "Termo " << i << ": " << 1.0 / fatorial(i) << "\n";
        e += 1.0 / fatorial(i);
    }
    return e;
};

int fatorial(int n){
    if(n == 0 || n == 1){
        return 1;
    }
    return n * fatorial(n - 1);
};