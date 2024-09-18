#include <iostream>

int *cria_array_aumentado(int*,int);
void mostra_array(int *arr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }
};

int main(){
    int arr[] = {1,431,1,24,2,5,1,2,4};
    int tamanho = sizeof(arr) / sizeof(int);

    int *novo_arr = cria_array_aumentado(arr,tamanho);
    mostra_array(novo_arr, tamanho * 2);
    delete[] novo_arr;
    return 0;
}

int *cria_array_aumentado(int *arr,int tamanho){
    int *novo_arr = new int[tamanho * 2];

    for(int i = 0; i < tamanho; i++){
        novo_arr[i] = arr[i];
    }

    return novo_arr;
};
