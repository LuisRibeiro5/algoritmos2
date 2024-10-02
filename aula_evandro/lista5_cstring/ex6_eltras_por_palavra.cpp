#include <iostream>

int *conta_letras_por_palavra(char*, int&);
int *aloca_array_dinamico(int *, int);
int soma_letras_das_palavras(int*, int);

int main(){
    char frase[] = "O rato roeu a roupa do rei de roma.";
    int cont_palavras = 0;

    int *qtde_letras_por_palavra = conta_letras_por_palavra(frase,cont_palavras);

    std::cout << "\nqtde palavras: " << cont_palavras << "\nqtde_letras_por_palavra: " << qtde_letras_por_palavra << "\n";

    int soma = soma_letras_das_palavras(qtde_letras_por_palavra,cont_palavras);

    std::cout << "\nA media de letras por palavras eh " << soma << "/" << cont_palavras << " = " << static_cast<float>(soma)/cont_palavras << std::endl;

    delete[] qtde_letras_por_palavra;
    return 0;
}

int *conta_letras_por_palavra(char *arr, int& cont_palavras){
    int *letras_por_palavra = nullptr;
        std::cout << "\nentrou na func\n";
        std::cout << "\n" << arr << " " << *arr << "\n";
    while(*arr != '\0'){

        if (*arr == ' '){
            std::cout << "\neh espaço\n";
            arr++;
            continue;
        }
        
        if (isalnum(*arr)){
            std::cout << "\neh uma palavra\n";
            cont_palavras++;
            letras_por_palavra = aloca_array_dinamico(letras_por_palavra,cont_palavras);
            while (isalnum(*arr))
            {
                letras_por_palavra[cont_palavras - 1]++;
                std::cout << letras_por_palavra[cont_palavras - 1] << " ";
                arr++;
            }
        }else{
            arr++;
        }

        
    }
    std::cout << "\nSaindo da func\n";
    return letras_por_palavra;
};

int *aloca_array_dinamico(int *letras_por_palavra, int cont_palavras){
    std::cout << "\nAlocou novo arr\n";
    int *novo_array = new int[cont_palavras]();

    for (int i = 0; i < cont_palavras - 1; i++)
    {
        novo_array[i] = letras_por_palavra[i];
    }
    
    delete[] letras_por_palavra;
    return novo_array;

};

int soma_letras_das_palavras(int *letras, int palavras){
    int soma= 0;

    for (int i = 0; i < palavras; i++)
    {
        soma += letras[i];
    }
    
    return soma;
};