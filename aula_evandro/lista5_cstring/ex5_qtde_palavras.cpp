/*Escreva uma fun¸c˜ao que aceite um ponteiro para uma C-string como argumento e retorne
o n´umero de palavras contidas na string. Por exemplo, se o argumento da string for “O
rato roeu a roupa do rei de Roma”, a fun¸c˜ao dever´a retornar o n´umero 9. Demonstre
a fun¸c˜ao em um programa que solicita ao usu´ario que insira uma string e, em seguida,
passe-a para a fun¸c˜ao. O n´umero de palavras na string dever´a ser exibido na tela.
*/

#include <iostream>
#include <cstring>

int conta_palavras(char *frase);


int main(){
    const int tamanho = 21;
    char frase[tamanho];

    std::cout << "frase: ";
    std::cin.getline(frase,tamanho);

    int qtde = conta_palavras(frase);

    std::cout << frase << '\n' << qtde << '\n'; 
    return 0;
}

int conta_palavras(char *frase){
   int end = (std::strlen(frase) + 1);
    int qtde = 0;
    for (int i = 0; i < end; i++)
    {
        if (!isspace(frase[i]))
        {
            if(isspace(frase[i + 1])){
                qtde++;
            }
        }
    }
    
    return ++qtde;
};
