#include <iostream>
#include <cstring>
#include <cctype> // Para isupper

char* separation(char* frase);
int conta_espacos(char* frase);

int main() {
    char frase[] = "PareEObserveAsRosas";
    char* nova_frase = separation(frase);

    std::cout << nova_frase << std::endl;

    delete[] nova_frase; // Libera a memória alocada
    return 0;
}

char* separation(char* frase) {
    int tamanho = conta_espacos(frase) + std::strlen(frase) + 1; // +1 para o terminador nulo
    char* nova_frase = new char[tamanho];
    char* p = nova_frase; // Ponteiro temporário para manipular nova_frase
    bool primeira = true;

    while (*frase != '\0') {
        if (isupper(*frase) && !primeira) {
            *p++ = ' '; // Adiciona espaço antes de letras maiúsculas, exceto no início
        }
        *p++ = *frase; // Adiciona o caractere atual
        frase++;
        primeira = false; // Após o primeiro caractere, altera para false
    }

    *p = '\0'; // Adiciona o terminador nulo

    return nova_frase; // Retorna o ponteiro que aponta para o início da nova string
}

int conta_espacos(char* frase) {
    int maiusc = 0;
    while (*frase) {
        if (isupper(*frase)) {
            maiusc++;
        }
        frase++;
    }
    return maiusc;
}
