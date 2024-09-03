//Faça um programa que receba uma string A e duas letras L1 e L2, e troque todas as ocorrências da letra L1 pela letra L2. Ao final mostre a string A atualizada.
#include <iostream>
#include <string>

using namespace std;
int main(){
    string frase;
    char l1,l2;
    do
    {
        cout << "digite uma frase" << endl;
        getline(cin,frase);
    } while (frase == "");

    do
    {
        cout << "digite uma letra da frase" << endl;
        l1 = tolower(cin.get());
        cin.ignore();
    } while (l1 == ' ' || isdigit(l1));

    do
    {
        cout << "digite uma outra letra da frase" << endl;
        l2 = tolower(cin.get());
        cin.ignore();
    } while (l2 == l1 || isdigit(l2) || l2 == ' ');

    for (int i = 0; i < frase.size(); i++)
    {
        if(frase.at(i) == l1){
            frase[i] = l2;

        }else if(frase.at(i) == l2){
            frase[i] = l1;
        }
       
    }
    
    /*
    CORRETO ERA: APENAS TROCAR LETRA 'X' POR 'Y' E TRATAR MAIUSC/MINUSC =
        for(int i = 0; i < frase.size(); i++){
            if(toupper(frase[i] == toupper(l1)){
                if(isupper(frase[i])){
                    frase[i] = toupper(l2)
                } else {
                    frase[i] = to lower(l2)
                }
            }
        }
    */


    cout << "\n" << frase << endl;
    
    
    
}