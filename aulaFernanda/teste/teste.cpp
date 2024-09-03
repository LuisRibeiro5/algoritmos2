#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string frase; 
    int cont = 0, vogalVezes=0;
    char vogal, letra;

    do
    {
        cout << "digite uma frase\n";
        getline(cin, frase);
    } while (frase == "");
    for(int i = 0; i < frase.size(); i++){
        frase.at(i) = toupper(frase.at(i));
    }
   

    for (int i = 0; i < frase.size(); i++)
    {
        letra = frase.at(i);
        if (letra == 'A' or letra == 'E' or letra == 'I' or letra == 'O' or letra == 'U')
        {
            for (int j = 0; j < frase.size(); j++)
            {
                if(letra == frase.at(j)){
                    cont++;
                }
            }
            if(cont > vogalVezes ){
                vogalVezes = cont; 
                vogal = frase.at(i);
            }
            cont = 0;
        }
    }

    cout << "quantidade de vezes da vogal: " << vogalVezes << "\n";
    cout <<"vogal mais usada " << vogal << '\n';
    cout << cont << "\n";
}