#include <iostream>

const int COLUNAS = 5;

int somar(const int lista[], int tamanho);
double media(const int lista[], int tamanho);
void calcular_media_linhas(const int matriz[][COLUNAS], double media_linhas[], int tamanho);
void calcular_media_colunas(const int matriz[][COLUNAS],double media_colunas[], int linhas);
void print_matriz(const int matriz[][COLUNAS], int linhas);
void print_array(const double media_linhas[], int linhas);
double calcular_media_matriz(const int  matriz[][COLUNAS], int tamanho);

int main() {
    int matriz[][COLUNAS] = {12,24,32,21,42,14,67,87,65,90,19,1,24,12,8};
    double media_linhas[3];
    double media_colunas[COLUNAS] ={0};

    calcular_media_linhas(matriz, media_linhas, 3);
    calcular_media_colunas(matriz, media_colunas, 3);

    std::cout << "Matriz\n";
    print_matriz(matriz, 3);
    std::cout << "Valor médio das linhas\n";
    print_array(media_linhas, 3);
    std::cout << "Valor médio das colunas\n";
    print_array(media_colunas, 5);
    std::cout << "Valor médio da matriz\n";
    std::cout << calcular_media_matriz(matriz,3) << '\n';

    return 0;
}

int somar(const int lista[], int tamanho) {
    int total = 0;
    for (int i = 0; i < tamanho; i++) {
        total += lista[i];
    }

    return total;
}

double media(const int lista[], int tamanho) {
    double total = somar(lista, tamanho);
    return total / tamanho; 
}

void calcular_media_linhas(const int matriz[][COLUNAS], double media_linhas[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        media_linhas[i] = media(matriz[i], COLUNAS);
    }
};

void calcular_media_colunas(const int matriz[][COLUNAS],double media_colunas[], int linhas){
    for (int j = 0; j < COLUNAS; j++)
    {
        for (int i = 0; i < linhas; i++)
        {
            media_colunas[j] += matriz[i][j];
        }
        media_colunas[j] /= linhas;
    }
    
};

void print_matriz(const int matriz[][COLUNAS], int linhas){
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            std::cout << matriz[i][j] << "\t";
        }
        std::cout << "\n";
        
    }
    
};

void print_array(const double media[], int linhas){
    for (int i = 0; i < linhas; i++)
    {
        std::cout << media[i] << "\t";
    }
};

double calcular_media_matriz(const int  matriz[][COLUNAS], int tamanho){
    double soma = 0;
    int cont = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            soma += matriz[i][j];
            cont++;
        }
        
    }
    return soma / cont;
};