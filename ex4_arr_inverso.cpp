#include <iostream>

int *copia_inverso(int*,int);
void mostra_array(int*, int);

int main(){
    int arr[] = {1,2,31,1,4,5,2,5};
    int tamanho = sizeof(arr) / sizeof(int);
    
    int *arr_inverso = copia_inverso(arr,tamanho);
    mostra_array(arr_inverso,tamanho);


    delete[] arr_inverso;
    return 0;
}

int *copia_inverso(int *arr,int tamanho){
    int *novo_arr = new int[tamanho];

    for(int i = 0, j = tamanho - 1; i < tamanho; i++, j--){
        novo_arr[j] = arr[i]; 
    }

    return novo_arr;
};  

void mostra_array(int *arr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }
}