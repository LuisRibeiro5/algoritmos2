//Escreva um programa que receba do usuário uma string S, um caractere C e uma posição I, e mostre o índice da primeira ocorrência do caractere C procurado a partir da posição I.
#include <iostream>
#include <string>

using namespace std;

int main(){
    string frase;
    do
    {
        cout << "digite uma frase" << endl;
        getline(cin,frase);
    } while (empty(frase));
    
    char c;
    do
    {
        cout << "digite um caracter da sua frase" << endl;
        c = tolower(cin.get());
        
    } while (isspace(c) || frase.find(c) == string::npos);

    int pos;
    do
    {
        cout << "digite uma posicao da sua frase" << endl;
        cin >> pos;
    } while (pos > frase.size() || pos <= 0);
    --pos;
    
    int primeiaOcorrencia = -1;
    //frase = frase.substr(pos);
    //cout << "a primera ocorrencia de "<< c << " no intervalo que vai de "<< pos+1 << " ate" << frase.size()<< " acontece em " <<  frase.find_first_of(c,pos) + 1;
    for (int i = pos ; i < frase.size(); i++)
    {
        if (tolower(frase.at(i)) == c)
        {
            primeiaOcorrencia = i;
            break;
        }
        
    }
    
    if (primeiaOcorrencia == -1)
    {
        cout << "caracter nao encontrado na frase."; //-1 é usado como sinalizador caso caracter nao esteja na frase.
    } else {
        cout << "a primera ocorrencia de "<< c << " no intervalo que vai de "<< pos+1 << " ate" << frase.size()<< " acontece em " << primeiaOcorrencia + 1 << endl;
    }

    return 0;
}