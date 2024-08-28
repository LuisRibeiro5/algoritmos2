#include <iostream>
#include <string>

using namespace std;

int main()
{
    string palavra;
    char resp;
    do
    {
        do
        {
            cout << "Digite uma cadeia de caracteres: \n";
            getline(cin, palavra);
        } while (palavra == "");

        string palavra_ao_contrario = "";
        
        for(int i = palavra.size() - 1; i >= 0; --i){
            palavra_ao_contrario += palavra.at(i);
        }

        if(palavra_ao_contrario == palavra){
            cout << palavra_ao_contrario << "---" << palavra << ": PALINDROME" << endl;
        }else{
            cout << palavra_ao_contrario << "---" << palavra << ": NAO E PALINDROME" << endl;
        }

        do
        {
            cout << "Deseja ver outra palavra?" << endl;
            resp = toupper(cin.get());
        } while (resp != 'S' and resp != 'N');
        cin.ignore();
    } while (resp != 'N');
    return 0;
}
