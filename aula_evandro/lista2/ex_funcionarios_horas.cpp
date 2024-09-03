#include <iostream>
#include <iomanip>

int recebe_horas();
double recebe_valor_hora();
double calcula_salario(int,double);

int main(){
    int emp_id[] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489},horas[7];
    double valor_hora[7],salario[7];

    for (int i = 0; i < 7; i++)
    {
        std::cout << "Funcionario: " << emp_id[i] << " - insira dados:\n";
        horas[i] = recebe_horas();
        valor_hora[i] = recebe_valor_hora();
        salario[i] = calcula_salario(horas[i],valor_hora[i]);
    }
    
    for (int i = 0; i < 7; i++)
    {
        std::cout << "funcionário " << emp_id[i] << ": salario -" << std::fixed << std::setprecision(2)<< salario[i] << "\n";
    }
    return 0;
}

int recebe_horas(){
    int horas;
    do
    {
        std::cout << "insira as horas trabalhadas: ";
        std::cin >> horas;
        if (horas <= 0)
        {
            std::cout << "invalido, insira novamente!\n";
        }
    } while (horas <= 0);
    return horas;
}

double recebe_valor_hora(){
    double valor_hora;
    do
    {
        std::cout << "digite quanto recebe por hora: ";
        std::cin >> valor_hora;
        if (valor_hora < 80)
        {
            std::cout << "valor invalido, insira novamente!\n";
        }
        
    } while (valor_hora < 80);
    return valor_hora;
}

double calcula_salario(int horas,double valor_hora){
    return horas * valor_hora;
}