#include <iostream>
#include <string>

using namespace std;

float obter_vendas(string filial){
    float venda; 
    do
    {
        cout << "Digite quantas vendas a filial " << filial << " obteve nesse trimestre: " << endl;
        cin >> venda;
    } while (venda < 0);
    
    return venda;
} 

int encontra_maior(float vetor_de_vendas[4]){
    int maior_venda = 0;
    for(int i = 1; i < 4; i++){
        if(vetor_de_vendas[i] > vetor_de_vendas[maior_venda]){
            maior_venda = i;
        }
    }

    return maior_venda;
}

int main(){
    string filiais [4] = {"Nordeste","Sudeste","Noroeste","Sudoeste"};
    cout << filiais[0];

    float vendas[4];

    for(int i= 0; i < 4; i++){
        vendas[i] = obter_vendas(filiais[i]);
    }

    int it_maior = encontra_maior(vendas);

    cout << " A maior venda foi da filial " << filiais[it_maior] << " com um total de vendas de " << vendas[it_maior] << endl;

    return 0;   
}