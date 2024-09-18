#include <iostream>

void preenche_array(int*, int);
void mostra_array(int*, int);
int moda_array(int*, int);

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
