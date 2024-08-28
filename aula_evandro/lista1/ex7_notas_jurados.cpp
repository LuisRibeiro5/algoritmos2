#include <iostream>
#include <string>

void obterNotaJurado(float&);
void calcularNotaFinal(float [], int);
double encontrarMenor(float [], int);
double encontrarMaior(float [], int);

int main(){
    float notaJurados[5]={0};
    for (int i = 0; i < 5; i++)
    {
        std::cout << " nota do " << i+1 << "o jurado: \n";
        obterNotaJurado(notaJurados[i]);
    }

    // for(float item:notaJurados){
    //     std::cout << " nota do " << item << "o jurado: \n";
    //     obterNotaJurado(item);
    // }

    calcularNotaFinal(notaJurados, 5);

    return 0;
}

void obterNotaJurado(float &nota){
    do
    {
        std::cout << "Digite a nota:\n";
        std::cin >> nota;
    } while (nota  < 0 || nota > 10);
}

void calcularNotaFinal(float notaJurados[], int tamanho){
    int itMaior = encontrarMaior(notaJurados, tamanho);
    int itMenor = encontrarMenor(notaJurados, tamanho);

    double media = 0;

    for (int i = 0; i < tamanho; i++)
    {
        if(i != itMaior && i != itMenor)
        media += notaJurados[i];
    }
    media = media/3;

    std::cout << "A media das notas é " << media << "\n";
}

double encontrarMaior(float notaJurados[], int tamanho){
    int itMaior = 0;
    for (int i = 1; i < tamanho; i++){
        if (notaJurados[i] > notaJurados[itMaior]){
            itMaior = i;
        }
    }
    return itMaior;
}

double encontrarMenor(float notaJurados[], int tamanho){
    int itMenor = 0;
    for (int i = 1; i < tamanho; i++){
        if (notaJurados[i] < notaJurados[itMenor]){
            itMenor = i;
        }
    }
    return itMenor;
}

