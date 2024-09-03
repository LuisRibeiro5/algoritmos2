//. Escreva um programa que permita ao usu´ario inserir 10 valores em um array. O programa
//deve ent˜ao exibir os maiores e menores valores armazenados no array.

#include <iostream>
#include <string>
#include <vector>

void inserir_array(float[], int);
bool valida_numero(std::string);
void organiza_array(float[], int);
void mostra_array(float[], int);

int main(){
    float array[10];

    inserir_array(array, 10);
    organiza_array(array, 10);
    mostra_array(array, 10);
    /*int maior = 0, menor= 0;
    for (int i = 1; i < 10; i++)
    {
        if(array[i] > array[maior]){
            maior = i;
        }
        if (array[i] < array[menor]){
            menor = i;
        }
        
    }*/
  
    return 0;
}

void inserir_array(float array[], int tamanho){
    std::string numero;
    for (int i = 0; i < tamanho; i++)
    {
        
        std::cout << "\ndigite o " << i + 1 << "o valor :";
        std::cin >> numero;
        
        while (true)
        {
            bool eValido = valida_numero(numero);

            if(eValido){
                array[i] = stoi(numero);
                break;
            }else {
                std::cout << "Valor invalido, insira novamente: ";
                std::cin >> numero;
            }
            
        }
        
    }
}

void organiza_array(float array[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        /* code */
    }
    
    for (int i = 0; i < tamanho; i++)
   {    
        for(int j = i; j < tamanho - 1; j++){
            if(array[i] < array[j + 1]){
            std::swap(array[i],array[j + 1]);
            }
        }
   }
}

void mostra_array(float array[] , int tamanho){
     std::cout << "Os maiores valores são :";
   for(int i = 0; i < tamanho/2; i++){
        std::cout << array[i] << "\n";
   }
    std::cout << "\n\n Os menores valores são :";
    for(int i = tamanho/2; i < tamanho; i++){
        std::cout << array[i] << "\n";
   }

}

bool valida_numero(std::string numero){
    bool eValido = true;
        
        for (int i = 0; i < numero.size(); i++)
        {
            if(!isdigit(numero.at(i))){
                eValido = false;
                break;
            }
        }

        return eValido;
};




