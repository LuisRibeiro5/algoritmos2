/*Escreva um programa que permita ao usu´ario inserir a quantidade total de chuva para
cada um dos 12 meses do ano em um array de n´umeros reais (double). O programa deve
calcular e exibir a quantidade total de chuva no ano, a m´edia mensal de chuva e os meses
com os maiores e menores ´ındices de chuva.
Valida¸c˜ao de Entrada: N˜ao aceite n´umeros negativos para os ´ındices mensais de chuva.*/

#include <iostream>

void inserir_chuva_cada_mes(double[], int);
double valida_entrada_chuva(double);
double calcula_chuva_do_ano(double[], int);
double calcula_media_mensal_chuva(double);
void copy(const double src[], double dest[], int tamanho);
void calcula_maiores_indices_chuva(double chuva[], double maiores[], int tamanho);
double calcula_maior(double chuva[], int tamanho);
void calcula_menores_indices_chuva(double chuva[],double maiores[], int tamanho);
double calcula_menor(double chuva[], int tamanho);


int main(){
    double chuva_cada_mes[12];
    inserir_chuva_cada_mes(chuva_cada_mes, 12);

    double chuva_total = calcula_chuva_do_ano(chuva_cada_mes, 12);
    double media_mensal_chuva = calcula_media_mensal_chuva(chuva_total);

    double copia[12];
    copy(chuva_cada_mes, copia, 12);

    double maiores[6], menores[6];
    calcula_maiores_indices_chuva(copia, maiores, 12);
    calcula_menores_indices_chuva(copia, menores, 12);

    

    return 0;
}

void inserir_chuva_cada_mes(double chuva[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "digite a chuva no " << i + 1 << "o mes";
        std::cin >> chuva[i];
        chuva[i] = valida_entrada_chuva(chuva[i]);
    }
    
};

double valida_entrada_chuva(double numero){
    while(true){
        if (numero < 0)
        {
            std::cout << "valor invalido, insira novamente :";
            std::cin >> numero;
        }
    }

    return numero; 
}

double calcula_chuva_do_ano(double chuva[], int tamanho){
    double chuva_total=0;
    for (int i = 0; i < tamanho; i++)
    {
        chuva_total += chuva[i];
    }
    return chuva_total;
};

double calcula_media_mensal_chuva(double chuva_total){
    return chuva_total / 12;
};

void calcula_maiores_indices_chuva(double chuva[], double maiores[], int tamanho){
    for (int i = 0; i < tamanho/2; i++)
    {
        maiores[i] = calcula_maior(chuva, tamanho);
        chuva[i] = INT8_MIN;
    }
};

double calcula_maior(double chuva[], int tamanho){
    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if(chuva[i] > chuva[maior]){
            maior = i;
        }
    }
    return chuva[maior];
}

void calcula_menores_indices_chuva(double chuva[],double maiores[], int tamanho){
    for (int i = 0; i < tamanho/2; i++)
    {
        maiores[i] = calcula_menor(chuva, tamanho);
        chuva[i] = INT8_MAX;
    }
}

double calcula_menor(double chuva[], int tamanho){
    int menor = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if(chuva[i] < chuva[menor]){
            menor = i;
        }
    }
    return chuva[menor];
}

void copy(const double src[], double dest[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        dest[i] = src[i];
    }
    
}