#include <iostream>

int recebeMaiorQueZero(); 
double calculaHorasDeTrabalho(double); 
double calculaQtdLitros(double);
double calculaCustoTinta(double, double);
double calculaCustoHorasTrabalhadas(double);
double calculaCustoTotal(double, double);

int main() {
    int comodos;
    double precoTinta, metrosQuadrados = 0;

    std::cout << "Digite o número de cômodos da casa: \n";
    comodos = recebeMaiorQueZero();

    do {
        std::cout << "Digite o preço da tinta (mínimo R$10,00): \n";
        std::cin >> precoTinta;
        if(precoTinta < 10) std::cout << "O preço da tinta deve ser no mínimo R$10,00.\n";
    } while (precoTinta < 10);

    for (int i = 0; i < comodos; i++) {
        std::cout << "Digite o tamanho em metros quadrados da parede " << i + 1 << ": \n";
        metrosQuadrados += recebeMaiorQueZero();
    }

    double litrosTinta = calculaQtdLitros(metrosQuadrados);
    double horasTrabalhadas = calculaHorasDeTrabalho(metrosQuadrados);
    double custoTotalTinta = calculaCustoTinta(litrosTinta, precoTinta);
    double custoHorasTrabalhadas = calculaCustoHorasTrabalhadas(horasTrabalhadas);
    double custoTotalTrabalho = calculaCustoTotal(custoTotalTinta, custoHorasTrabalhadas);

    std::cout << "A quantidade de litros necessária é: " << litrosTinta << " litros\n";
    std::cout << "As horas de trabalho necessárias são: " << horasTrabalhadas << " horas\n";
    std::cout << "O custo da tinta é: R$ " << custoTotalTinta << "\n";
    std::cout << "O custo do trabalho é: R$ " << custoHorasTrabalhadas << "\n";
    std::cout << "O custo total do serviço de pintura é: R$ " << custoTotalTrabalho << "\n";

    return 0;
}

int recebeMaiorQueZero() {
    int valor;
    do {
        std::cin >> valor;
        if (valor <= 0) std::cout << "O valor precisa ser maior que 0!\n";
    } while (valor <= 0);

    return valor;
}

double calculaHorasDeTrabalho(double metrosQuadrados) {
    return 8 * metrosQuadrados / 10;
}

double calculaQtdLitros(double metros) {
    return metros / 10;
}

double calculaCustoTinta(double litros, double precoTinta) {
    return litros * precoTinta;
}

double calculaCustoHorasTrabalhadas(double horasDeTrabalho) {
    return horasDeTrabalho * 25;
}

double calculaCustoTotal(double custoTinta, double custoHoras) {
    return custoTinta + custoHoras;
}
