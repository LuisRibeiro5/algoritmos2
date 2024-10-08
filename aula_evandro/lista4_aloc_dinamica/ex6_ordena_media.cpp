#include <iostream>

void preenche_arr(double*,int);
void quick_sort(double*,int,int);
void mostra_array(double *arr, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
};
double *remove_menor_nota(double*, int);
double calcula_media(double*, int);

int main(){
    int qtde;
    std::cout << "qtde notas: ";
    std::cin >> qtde;

    double *arr = new double[qtde];

    preenche_arr(arr,qtde);
    quick_sort(arr,0, qtde - 1);
    mostra_array(arr,qtde);
    double media = calcula_media(arr,qtde);
    std::cout << "\n A media com todas as notas foi: " << media << "\n"; 

    arr = remove_menor_nota(arr, qtde);
    qtde--;
    media = calcula_media(arr,qtde);
    mostra_array(arr,qtde);
    std::cout << "\n A media sem a menor nota foi: " << media << "\n"; 

    delete[] arr;
    return 0;
}

void preenche_arr(double *arr,int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "\nNota " << i+1 << ": ";
        std::cin >> arr[i];
    }
    
};

void quick_sort(double *arr,int ini, int fim){
    if (ini < fim){
        double pivot = arr[fim];
        int menor_indice = ini - 1;

        for (int i = ini; i <= fim - 1 ; i++)
        {
            if(arr[i] < pivot){
                menor_indice++;
                std::swap(arr[i],arr[menor_indice]);
            }
        }
        
        std::swap(arr[menor_indice + 1], arr[fim]);
        int idx_pivot = menor_indice + 1;

        quick_sort(arr,ini,idx_pivot - 1);
        quick_sort(arr,idx_pivot + 1,fim);
    };
};

double calcula_media(double *arr, int tamanho){
    double total = 0;
    for (int i = 0; i < tamanho; i++)
    {
        total += arr[i];
    }
    
    return total / tamanho;
};

double *remove_menor_nota(double *arr, int tamanho){
    double *novo = new double[tamanho - 1];
    
    for (int i = 1; i < tamanho; i++)
    {
        novo[i - 1] = arr[i];
    }
    
    delete[] arr;
    
    return novo;
};
