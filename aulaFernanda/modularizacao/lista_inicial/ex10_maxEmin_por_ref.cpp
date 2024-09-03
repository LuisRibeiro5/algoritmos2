/*Elabore uma função que recebe três valores inteiros e devolve por referência o maior e o menor valor desses três. Deve ser criado um programa para utilizar tal função lendo os valores e escrevendo o maior e o menor valor 
computado*/
#include <iostream>

void pegaMaxEMin(int,int,int,int&,int&);

int main(){
    int v1,v2,v3;
    std::cout << "v1: "; std::cin >> v1;
    std::cout << "v2: "; std::cin >> v2;
    std::cout << "v3: "; std::cin >> v3;

    std::cout << "\n" << v1 << ", " << v2 << ", " << v3 << "\n";

    int max,min;

    pegaMaxEMin(v1,v2,v3,max,min);

    std::cout << "max= "  << max << ", min= " << min << "\n"; 
}

void pegaMaxEMin(int v1,int v2,int v3,int& max,int& min){
    max = v1;
    min = v1;

    if(v2 > max) max = v2;
    if(v2 < min) min = v2;

    if(v3 > max) max = v3;
    if(v3 < min) min = v3;
};
