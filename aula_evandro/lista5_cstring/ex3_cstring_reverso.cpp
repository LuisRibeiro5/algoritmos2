/*Escreva uma fun¸c˜ao que aceite um ponteiro para uma C-string como argumento e exiba
seu conte´udo de tr´as para frente. Por exemplo, se o argumento da string for ”Gravidade”,
a fun¸c˜ao dever´a exibir ”edadivarG”. Demonstre a fun¸c˜ao em um programa que solicita
ao usu´ario que insira uma string e, em seguida, passe-a para a fun¸c˜ao.
*/

#include <iostream>
#include <cstring>

void imprime_cstring_reverso(char*);


int main(){
    char frase[] = "Ola";
    char frase2[] = {'l','u','i','s',' ','g','u','s','t','a','v','o'};
    //int ultimo_idx = (sizeof(frase) / sizeof(char)) -1;
    //std::cout << ultimo_idx << "\n";
    imprime_cstring_reverso(frase);
    imprime_cstring_reverso(frase2);

    return 0;
}

void imprime_cstring_reverso(char *frase){
    //int ultimo_idx = (sizeof(frase) / sizeof(char)) -1;
    //std::cout << ultimo_idx << "\n";
    int tamanho = std::strlen(frase);
    for (int i = tamanho - 1; i >= 0; i--)
    {
        std::cout << frase[i]; 
    }
    std::cout << '\n'; 
};

