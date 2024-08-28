#include <iostream>
#include <string>

void solicitaNotaEPeso(float&, float&);
float calcularMediaPonderada(float[], float[], int tamanho);

int main(){
    float nota[3], peso[3];

    for (int i = 0; i < 3; i++)
    {
        std::cout << "digite a nota e peso da prova " << i << "\n";
        solicitaNotaEPeso(nota[i], peso[i]);
    }
    
    std::cout << "a media ponderada é : " << calcularMediaPonderada(nota,peso,3);
    return 0;
}

void solicitaNotaEPeso(float& nota, float& peso){
    do
    {
        std::cout << "Nota: "; std::cin >> nota;
    } while (nota < 0 || nota > 10);

    do
    {
        std::cout << "Peso: "; std::cin >> peso;
    } while (peso <= 0);    
}

float calcularMediaPonderada(float nota[], float peso[], int tamanho){
    float somaDosPesos = 0;
    float mediaPonderada = 0;
    for (int i = 0; i < tamanho; i++)
    {   
        somaDosPesos = peso[i];
        mediaPonderada += nota[i] * peso[i];
    }

   
    return mediaPonderada / somaDosPesos;
    
};