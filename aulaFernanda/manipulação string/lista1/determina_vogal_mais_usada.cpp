// Faça um algoritmo que leia uma frase e determine qual a vogal mais usada.
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

/*int main()
{
    string frase;
    char letra;
    int cont = 0, qtdeVogal=0;
    char vogalMais = ' ';

    //Entrada com validacao da frase
    do
    {
        cout << "Digite uma frase: ";
        getline(cin, frase);
    } while (frase == "");

    //Loop passa por cade letra e deixa maiuscula
    for(int i = 0; i < frase.size(); ++i){
        frase.at(i) = toupper(frase.at(i));
    }

    //Verifica a volgal mais usada na frase
    for (int i = 0; i < frase.size(); i++)
    {
        letra = frase.at(i);

        if (letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U')
        {
            cont = 0;
            for (int j = 0; j < frase.size(); j++)
            {
                if (letra == frase.at(j))
                {
                    ++cont;
                }
            }

            if(cont > qtdeVogal){
                qtdeVogal = cont;
                vogalMais = frase.at(i);
            }
        }
    }
    cout << "A vogal mais usada nesse frase foi: " << vogalMais << "\n";
    cout << "A vogal *" << vogalMais << "* apareceu " << qtdeVogal << " vezes na frase.";
    return 0;
}*/

int main()
{
    char vogais[5] = {'a', 'e', 'i', 'o', 'u'}, vogalMaisChar;
    int vogalMais[5] = {0}, cont;
    string frase;

    //Entrada e validacao da frase
    do
    {
        cout << "Digite um frase: ";
        getline(cin, frase);
    } while (frase == "");

    //Deixa cada letra da frase maiuscula
    /*for (int i = 0; i < frase.size(); ++i)
    {
        frase.at(i) = tolower(frase.at(i));
        cout << frase.at(i);
    }
    cout << "\n";*/
    
    //Esse looping pega cada vogal no array vogais e depois a cada vogal na frase que for igual a vogal do looping ela armazena a quantidaade em um vetor 'vogalMaisUtilizada'
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < frase.size(); ++j)
        {
            if(isupper(frase.at(j))){
                frase.at(j) = tolower(frase.at(j));
            }
            if (vogais[i] == frase.at(j))
            {
                vogalMais[i]++;
            }
        }
    }

    /* Isso funciona, mas talvez nao é o ideal pois desorganiza os arrays
    for (int i = 1; i < 5; ++i)
    {
        if (vogalMais[0] < vogalMais[i])
        {
            swap(vogalMais[0], vogalMais[i]);
            swap(vogais[0], vogais[i]);

        }
    } */

    int indexador = 0;
    for(int i = 1; i < 5; ++i){

        if(vogalMais[i] > vogalMais[indexador]){
            indexador = i;
        }
    }

    cout << "A vogal mais usada foi " << vogais[indexador] << "\n";
    cout << "Ela apareceu " << vogalMais[indexador] << " vezes" << "\n";
}