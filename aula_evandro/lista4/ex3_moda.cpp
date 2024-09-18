#include <iostream>

void preenche_array(int*, int);
void mostra_array(int*, int);
int moda_array(int*, int);
int moda(int*, int);
void faz_contagem(int*, int*, int&, int);
int retorna_maior(int*,int);

int main(){
    int tamanho;
    std::cout << " Digite o tamanho do array: ";
    std::cin >> tamanho;

    int *arr = new int[tamanho];

    preenche_array(arr,tamanho);
    mostra_array(arr,tamanho);
    int moda = moda_array(arr,tamanho);

    if(moda != -1){
        std::cout << "\nA moda é :" << moda;
    }else{
        std::cout << "Nao tem moda.";
    }

    delete[] arr;
    return 0;
}

void preenche_array(int *arr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << "elemento " << i << ": ";
        std::cin >> arr[i];
    }
};

void mostra_array(int *arr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }
}

int moda_array(int *arr, int tamanho){
    int num_moda = 0;
    int mais_vezes = 0;
    int vezes = 0;

    for (int i = 0; i < tamanho; i++){
        vezes = 0;
        for(int j = 0; j < tamanho; j++){
            if (arr[i] == arr[j]){
                vezes++;
            }
        }
        if(vezes > mais_vezes){
            mais_vezes = vezes;
            num_moda = arr[i];
        }
    }
    if (mais_vezes == 1){
        return -1;
    }
    return num_moda;
};

int moda(int *arr, int tamanho){
    int *valores,*contagem;
    valores = new int[tamanho];
    contagem = new int [tamanho];

    int tam =0 ;
    for (int i = 0; i < tamanho; i++){
        faz_contagem(valores,contagem,tam,arr[i]);
    }

    int idx_maior = retorna_maior(contagem,tamanho);
    int moda = valores[idx_maior];

    delete[] valores;
    delete[] contagem;
    
    return moda == 1 ? -1 : moda;
};

void faz_contagem(int *valores, int *contagem, int &tamanho,int valor){
    for (int i = 0; i < tamanho; i++){
        if(valores[i] == valor){
            contagem[i]++;
            return;
        }
    }

    valores[tamanho] = valor;
    contagem[tamanho] = 1;
    tamanho++;
};

int retorna_maior(int *arr,int tamanho){
    int max = arr[0];
    int idx_max = 0;

    for (int i = 1; i < tamanho; i++)
    {
        if (arr[i] > max){
            max = arr[i];
            idx_max = i;
        }
    }
    
    return idx_max;
};
