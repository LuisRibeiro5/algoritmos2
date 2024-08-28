#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    string palavra1, palavra2;

    do
    {
        cout << "Digite a primeira palavra" << endl;
        getline(cin, palavra1);
    } while (palavra1 == " ");

    do
    {
        cout << "Digite a segunda palavra" << endl;
        getline(cin, palavra2);
    } while (palavra2 == " ");

    bool ePermutavel = true;
    if (palavra1.size() != palavra2.size())
    {
        ePermutavel = false;
    }
    else if (palavra1 != palavra2)
    {
        char aux = palavra1.at(0);
        for (int i = 0; i < palavra1.size(); i++)
        {

            for (int j = 0; j < palavra1.size() - 1; j++)
                palavra1.at(j) = palavra1.at(j + 1);
        }
        palavra2.at(palavra2.size() - 1) = aux;

        if (palavra2 == palavra1)
        {
            ePermutavel = true;
        }
        else
        {
            ePermutavel = false;
        }
    }

    if(ePermutavel){
        cout << "e permutavel";
    }else{
        cout << "nao e permutavel";
    }
    return 0;
}