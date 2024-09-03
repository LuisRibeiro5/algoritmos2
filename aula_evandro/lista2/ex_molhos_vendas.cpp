#include <iostream>
#include <string>



void obter_vendas(std::string molhos[],int potes_vendidos[], int = 5);
void relatorio(std::string molhos[], int potes_vendidos[], int = 5);
int vendas_totais(int potes_vendidos[], int tamanho);
void constroi_idx_maior_to_menor(int [],int [], int = 5);
int calcula_maior(int [], int);
void copy(const int src[], int dest[], int = 5);

int main(){
    std::string molhos[] = { "suave", "medio", "doce", "picante","apimentado"};
    int potes_vendidos[5];
    int idx_potes_maior_to_menor[5];
    int copia[5];

    obter_vendas(molhos,potes_vendidos);
    relatorio(molhos,potes_vendidos);
    copy(potes_vendidos, copia);
    constroi_idx_maior_to_menor(copia,idx_potes_maior_to_menor);

    std::cout << "Os maiores valores foram: \n";
    int idx;
    for (int i = 0; i < 2; i++)
    {   
        idx = idx_potes_maior_to_menor[i];
        std::cout << molhos[idx] << ":" << potes_vendidos[idx] << "\n";
    }

    std::cout << "Os menores valores foram: \n";
    for (int i = 2; i < 5; i++)
    {   
        idx = idx_potes_maior_to_menor[i];
        std::cout << molhos[idx] << ":" << potes_vendidos[idx] << "\n";
    }
     
    
    return 0;
}

void obter_vendas(std::string molhos[],int potes_vendidos[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        do
        {
            std::cout << "quantos potes vendidos de " << molhos[i] << "? ";
            std::cin >> potes_vendidos[i];
            if (potes_vendidos[i] < 0)
            {
                std::cout << "valor invalido!\n";
            }
            
        } while (potes_vendidos[i] < 0);
        
    }
}

void relatorio(std::string molhos[], int potes_vendidos[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << molhos[i] << "teve " << potes_vendidos[i] << " vendas\n";
    }
    
    std::cout << "as vendas totais foram de: " << vendas_totais(potes_vendidos, tamanho);
     
    
}

int vendas_totais(int potes_vendidos[], int tamanho){
    int total = 0;
    for (int i = 0; i < tamanho; i++)
    {
        total += potes_vendidos[i];
    }
    return total;
}

void constroi_idx_maior_to_menor(int potes_vendidos[],int idx_array[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        int idx = calcula_maior(potes_vendidos, tamanho);
        idx_array[i] = idx;
        potes_vendidos[idx] = INT16_MIN;
    }
}

int calcula_maior(int array[], int tamanho){
    int idx = 0;
    for (int i = 1; i < tamanho; i++)
    {
        if(array[i] > array[idx]){
            idx = i;
        }
    }
    return idx;
}

void copy(const int src[], int dest[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        dest[i] = src[i];
    }
}