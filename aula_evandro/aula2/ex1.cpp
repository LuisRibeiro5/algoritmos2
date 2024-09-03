#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{   
    int soma = 0;
    for(int i = 1; i < argc; i++){
        int num = stoi(argv[i]);
        soma += num;
    }

    float media = soma / (argc - 1.0);

    double desvioPadrao = 0.0;
    for(int i = 1; i < argc; i++){
        int num1 = stoi(argv[i]);
        desvioPadrao += pow(num1 - media , 2);
    }    

    float variancia = desvioPadrao / (argc - 1.0);
    float resultado = sqrt(variancia);
    cout << resultado << "\n";
    return 0;
}
