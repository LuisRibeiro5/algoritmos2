/*. Escreva uma fun¸c˜ao que aceite um ponteiro para uma C-string como argumento e reverta
seu conte´udo. Por exemplo, se o argumento da string for ”Gravidade”, a fun¸c˜ao dever´a
alter´a-la para ”edadivarG”. Demonstre a fun¸c˜ao em um programa que solicita ao usu´ario
que insira uma string e, em seguida, passe-a para a fun¸c˜ao.
*/

#include <iostream>
#include <cstring>

void reverte_string(char*);

int main(){
    const int tamanho = 21;
    char string1[tamanho] = "";

    std::cout << "digite a frase, ate 20 chars \n";
    std::cin.getline(string1, tamanho);

    if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
    }

    reverte_string(string1);
    std::cout << string1;

    return 0;
}

void reverte_string(char *frase){
    int tamanho = std::strlen(frase);

    char *suporte = new char[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        suporte[i] = frase[i];
    }
    
    for (int j = 0,i = tamanho - 1; i >= 0; i--,j++)
    {
        frase[j] = suporte[i];
    }
    
    delete[] suporte;
};
