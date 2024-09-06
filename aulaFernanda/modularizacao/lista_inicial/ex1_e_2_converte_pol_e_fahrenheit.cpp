/*Crie uma função que realize a conversão de Polegadas (pol) para Centímetros (cm), onde pol é passado como 
parâmetro e cm é retornado. Sabe-se que 1 polegada está para 2,54 centímetros. Crie também um programa para 
testar tal função. 
2. Elabore uma função que realize a conversão de Fahrenheit (F) para graus Celsius (C), onde F é passado como 
parâmetro e C é retornado. Sabe-se que os pontos de fusão e ebulição nas escalas Celsius e Fahrenheit são: 0ºC 
e 100ºC, e 32ºF e 212ºF, respectivamente. Crie também um programa para testar tal função. */
#include <iostream>

double convertePolCm(float);
float leNumRealPositivo(char[]);
float FahrParaCelsius(float);

int main(){
    float polegadas = leNumRealPositivo(" digite uma medida em polegadas: \n");
    std::cout << "Conversao para centimetros: "<< convertePolCm(polegadas) << "centimetros\n";
    float fahrenheit = leNumRealPositivo("digite uma medida em fahrenheit: \n");
    std::cout << "Conversao para celcius: " << FahrParaCelsius(fahrenheit);
    return 0;   
}

double convertePolCm(float polegadas){
    return polegadas * 2.54;
};

float leNumRealPositivo(char frase[]){
    std::cout << frase;
    float num;
    do
    {
        std::cin >> num;
    } while (num < 0);
    return num;
};

float FahrParaCelsius(float fahr){
    return 5/9.0 * (fahr - 32);
};
