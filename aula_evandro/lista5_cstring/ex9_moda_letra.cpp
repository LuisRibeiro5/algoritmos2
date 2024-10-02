#include <iostream>
#include <cstring>

int caracter_moda(char*);
void conta_letras(char, char*, int*, int&);
// char *aumenta_array(char *, int);
// int *aumenta_array(int *, int);
int mais_vezes(int *, char*, int);
char caracter_mais_frequente(const char *letras);

int main(){
    char frase[] = "Ola Mundo, sou garoto de programa";

    int idx_moda = caracter_moda(frase);

    std::cout << "O caracter que mais aparece eh: " << frase[idx_moda] << "\n";

    char letra = caracter_mais_frequente(frase);

    std::cout << "\n" << letra << std::endl;
    return 0;
}

// int caracter_moda(char *str){
//     int cont = 0, idx_mais = -1, cont_mais = 0;
//     char atual;
//     char *inicio = str;
//     char *aux = str;
//     int i = 0;
//     while(*str != '\0'){
        
//         if(*str == ' '){
//             str++;
//             i++;
//             continue;
//         }

//         cont = 0;
//         atual = *str;
//         aux = inicio;
//         while (*aux != '\0')
//         {
//             if (atual == *aux){
//                 cont++;
//             }
//             aux++;
//         }
//         if(cont > cont_mais){
//             cont_mais = cont;
//             idx_mais = i;
//         }

//         str++;
//         i++;
//     }

//     return idx_mais;
// };


int caracter_moda(char *str){
    char letras[std::strlen(str)] = {'0'};
    int vezes[std::strlen(str)] = {0};
    int tamanho = 0;
    for (auto i = 0; i < strlen(str); i++)
    {
        
        conta_letras(str[i],letras,vezes,tamanho);
    }
    
    int idx_mais_vezes = mais_vezes(vezes,letras,tamanho);

    // delete[] letras;
    // delete[] vezes;

    return idx_mais_vezes;
}

void conta_letras(char atual,char *letras, int *vezes, int& tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        if(atual == letras[i]){
            vezes[i]++;
            return;
        }
    }

    letras[tamanho] = atual; 
    vezes[tamanho] = 1;
    tamanho++;
    
}   

// char *aumenta_array(char *letras, int tamanho){
//     char *novo_arr = new char[tamanho]();

//     for (int i = 0; i < tamanho - 1; i++)
//     {
//         novo_arr[i] = letras[i];
//     }
    
//     delete[] letras;

//     return novo_arr;
// };
// int *aumenta_array(int *vezes, int tamanho){
//     int *novo_arr = new int[tamanho]();

//     for (int i = 0; i < tamanho - 1; i++)
//     {
//         novo_arr[i] = vezes[i];
//     }
    
//     delete[] vezes;

//     return novo_arr;
// };

int mais_vezes(int *vezes, char *letras, int tamanho){
    int idx_maior = 0;
    int maior = vezes[idx_maior];
    for (int i = 1; i < tamanho; i++)
    {
        if(vezes[i] > maior && letras[i] != ' '){
            maior = vezes[i];
            idx_maior = i;
        }
    }
    
    return idx_maior;
};


char caracter_mais_frequente(const char *letras){
    int chars[256] = {0};
    char char_mais_frequente = '\0';
    int frequencia_max = 0;


    while (*letras)
    {
        chars[*letras]++;
        if (chars[*letras] > frequencia_max && *letras != ' ')
        {
            frequencia_max = chars[*letras];
            char_mais_frequente = *letras;
        }

        letras++;
    }
    
    return char_mais_frequente;
}