/*Escreva um programa que permita ao usu´ario inserir a quantidade total de chuva para
cada um dos 12 meses do ano em um array de n´umeros reais (double). O programa deve
calcular e exibir a quantidade total de chuva no ano, a m´edia mensal de chuva e os meses
com os maiores e menores ´ındices de chuva.
Valida¸c˜ao de Entrada: N˜ao aceite n´umeros negativos para os ´ındices mensais de chuva.*/

#include <iostream>

void inserir_chuva_cada_mes(double[], int);
double valida_entrada_chuva(double);
double calcula_chuva_do_ano(double[], int);
double calcula_media_mensal_chuva(double);
void copy(const double src[], double dest[], int tamanho);
void calcula_maiores_indices_chuva(double chuva[], double maiores[], int tamanho);
double calcula_maior(double chuva[], int tamanho);
void calcula_menores_indices_chuva(double chuva[],double maiores[], int tamanho);
double calcula_menor(double chuva[], int tamanho);
void mostra_meses_menores(double chuva[], double menores[], std::string meses[], int tamanhoChuva, int tamanhoMenores);
void mostra_meses_maiores(double chuva[], double maiores[], std::string meses[], int tamanhoChuva, int tamanhoMaiores);

int main(){
    double chuva_cada_mes[12];
    std::string meses[] = {"janeiro","fevereiro","março","abril","maio","junho","julho","agosto","setembro","outubro","novembro","dezembro",};
    inserir_chuva_cada_mes(chuva_cada_mes, 12);

    double chuva_total = calcula_chuva_do_ano(chuva_cada_mes, 12);
    double media_mensal_chuva = calcula_media_mensal_chuva(chuva_total);

    double copia[12];

    double maiores[6], menores[6];
    copy(chuva_cada_mes, copia, 12);
    calcula_maiores_indices_chuva(copia, maiores, 12);
    copy(chuva_cada_mes, copia, 12);
    calcula_menores_indices_chuva(copia, menores, 12);

    std::cout << "A quantidade total de chuva no ano foi: " << chuva_total << "\n A media mensal de chuva foi: " << media_mensal_chuva << "\n";
    std::cout << "Os meses com maiores indices foram: \n"; mostra_meses_maiores(chuva_cada_mes, maiores, meses, 12, 6);
    std::cout << "Os meses com menores indices foram: \n"; mostra_meses_menores(chuva_cada_mes, menores, meses, 12, 6);

    return 0;
}

void inserir_chuva_cada_mes(double chuva[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        std::cout << "digite a chuva no " << i + 1 << "o mes";
        std::cin >> chuva[i];
        chuva[i] = valida_entrada_chuva(chuva[i]);
    }
    
};

double valida_entrada_chuva(double numero){
    while(numero < 0){
        std::cout << "valor invalido, insira novamente :";
        std::cin >> numero;
    }
    return numero; 
}

double calcula_chuva_do_ano(double chuva[], int tamanho){
    double chuva_total=0;
    for (int i = 0; i < tamanho; i++)
    {
        chuva_total += chuva[i];
    }
    return chuva_total;
};

double calcula_media_mensal_chuva(double chuva_total){
    return chuva_total / 12;
};

void calcula_maiores_indices_chuva(double chuva[], double maiores[], int tamanho){
    for (int i = 0; i < tamanho/2; i++)
    {
        maiores[i] = calcula_maior(chuva, tamanho);
        
        for (int j = 0; j < tamanho; j++)
        {
            if(maiores[i] == chuva[j]){
                chuva[j] = INT16_MIN;
                break;
            }
        }
        
    }
};

double calcula_maior(double chuva[], int tamanho){
    int maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if(chuva[i] > chuva[maior]){
            maior = i;
        }
    }
    return chuva[maior];
}

void calcula_menores_indices_chuva(double chuva[],double menores[], int tamanho){
    for (int i = 0; i < tamanho/2; i++)
    {
        menores[i] = calcula_menor(chuva, tamanho);
        
        for (int j = 0; j < tamanho; j++)
        {
            if (menores[i] == chuva[j])
            {
                chuva[j] = INT16_MAX;
                break;
            }
            
        }
        
    }
}

double calcula_menor(double chuva[], int tamanho){
    int menor = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if(chuva[i] < chuva[menor]){
            menor = i;
        }
    }
    return chuva[menor];
}

void copy(const double src[], double dest[], int tamanho){
    for (int i = 0; i < tamanho; i++)
    {
        dest[i] = src[i];
    }
    
}

void mostra_meses_maiores(double chuva[], double maiores[], std::string meses[], int tamanhoChuva, int tamanhoMaiores){
    for (int i = 0; i < tamanhoMaiores; i++)
    {
        for (int j = 0; j < tamanhoChuva; j++)
        {
            if (maiores[i] == chuva[j])
            {
                std::cout << meses[j] << " - " << maiores[i] << "\n";
            }
            
        }
        
    }
    
}

void mostra_meses_menores(double chuva[], double menores[], std::string meses[], int tamanhoChuva, int tamanhoMenores){
    for (int i = 0; i < tamanhoMenores; i++)
    {
        for (int j = 0; j < tamanhoChuva; j++)
        {
            if (menores[i] == chuva[j])
            {
                std::cout << meses[j] << " - " << menores[i] << "\n";
            }
            
        }
        
    }
    
}