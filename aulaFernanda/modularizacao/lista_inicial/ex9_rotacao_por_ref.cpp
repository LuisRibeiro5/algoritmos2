/*Faça uma função que faça a rotação de valor entre três números passados como parâmetros, por referência. Por exemplo, se a função receber os valores 5 8 e 9, nesta ordem, os valores de saída nessas variáveis serão 8, 9 e 5, 
respectivamente. */
#include <iostream>

void rotacaoDeValores(int&,int&,int&);

int main(){
    int v1,v2,v3;
    std::cout << "v1: "; std::cin >> v1;
    std::cout << "v2: "; std::cin >> v2;
    std::cout << "v3: "; std::cin >> v3;

    std::cout << "\n" << v1 << ", " << v2 << ", " << v3 << "\n";


    rotacaoDeValores(v1,v2,v3);

    std::cout << "\n" << v1 << ", " << v2 << ", " << v3 << "\n";
    return 0;
}

void rotacaoDeValores(int& v1,int& v2,int& v3){
    int aux = v1;
    v1 = v2;
    v2 = v3;
    v3 = aux;
};
