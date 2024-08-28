//Faça um programa que leia uma string no formato “DD/MM/AAAA” e copie o dia, mês e ano para 3 variáveis inteiras. Antes disso, verifique se as barras estão no lugar certo, e se DD, MM e AAAA são numéricos.
#include <iostream>
#include <string>

using namespace std;

int main(){
    string data;
    bool barraCerta;
    do
    {
        barraCerta = true;

        cout << "digite o dia mes e ano nesse formato: dd/mm/aaaa" << endl;
        getline(cin,data);
        if(data[2] != '/'){
            cout << "o dia deve ser digitado corretamente, exemplo 03/11/2005" << endl;
            barraCerta = false;
        }else if (data[5] != '/')
        {
            cout << "o mes deve ser digitado corretamente, exemplo 20/01/2005" << endl;
            barraCerta = false;
        }else if (data.size() > 10 || data.size() < 10){
            cout << "o ano deve ser digitado corretamente, exemplo 20/01/2024" << endl;
        }
        
    } while (data.size() != 10 || !barraCerta);

    int dia,mes,ano;
    dia = stoi(data.substr(0,2)); 
    mes = stoi(data.substr(3,2)); 
    ano = stoi(data.substr(6,4)); 

    cout << "dia: " << dia << "\n mes: " << mes << "\n ano: " << ano << endl;
    
    
}