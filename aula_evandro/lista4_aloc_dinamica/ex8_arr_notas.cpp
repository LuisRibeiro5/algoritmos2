#include <iostream>

void preenche_arr(double*,std::string*,int);
void quick_sort(double*,std::string*,int,int);
void mostra_array(double *arr,std::string *nomes, int tamanho){
    for(int i = 0; i < tamanho; i++){
        std::cout << "\n"<< arr[i] << " - ";
        std::cout << nomes[i] << " ";
    }
    std::cout << "\n";
};
double *remove_menor_nota(double*, int);
std::string *remove_menor_nota(std::string *arr, int tamanho);
double calcula_media(double*, int);

int main(){
    int qtde;
    std::cout << "qtde de aulnos: ";
    std::cin >> qtde;

    double *arr = new double[qtde];
    std::string *nomes = new std::string[qtde];

    preenche_arr(arr,nomes,qtde);
    quick_sort(arr,nomes,0, qtde - 1);
    mostra_array(arr,nomes,qtde);
    double media = calcula_media(arr,qtde);
    std::cout << "\n A media com todas as notas foi: " << media << "\n"; 

    arr = remove_menor_nota(arr, qtde);
    nomes = remove_menor_nota(nomes,qtde);
    qtde--;
    media = calcula_media(arr,qtde);
    mostra_array(arr,nomes,qtde);
    std::cout << "\n A media sem a menor nota foi: " << media << "\n"; 

    delete[] arr;
    return 0;
}

void preenche_arr(double *arr, std::string *nomes, int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "\nNota " << i+1 << ": ";
        std::cin >> arr[i];
        std::cin.ignore();
        std::cout << "\nNome " << i+1 << ": ";
        std::getline(std::cin, nomes[i]);
    }
    
};

void quick_sort(double *arr, std::string *nomes, int ini, int fim){
    if (ini < fim){
        double pivot = arr[fim];
        int menor_indice = ini - 1;

        for (int i = ini; i <= fim - 1 ; i++)
        {
            if(arr[i] < pivot){
                menor_indice++;
                std::swap(arr[i],arr[menor_indice]);
                std::swap(nomes[i],nomes[menor_indice]);
            }
        }
        
        std::swap(arr[menor_indice + 1], arr[fim]);
        int idx_pivot = menor_indice + 1;

        quick_sort(arr,nomes,ini,idx_pivot - 1);
        quick_sort(arr,nomes,idx_pivot + 1,fim);
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
std::string *remove_menor_nota(std::string *arr, int tamanho){
    std::string *novo = new std::string[tamanho - 1];
    
    for (int i = 1; i < tamanho; i++)
    {
        novo[i - 1] = arr[i];
    }
    
    delete[] arr;
    
    return novo;
};
