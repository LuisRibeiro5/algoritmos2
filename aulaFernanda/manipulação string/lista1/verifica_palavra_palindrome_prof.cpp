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

// EXEMPLO DA FERNANDA
// int main(){
//     int n;
//     do
//     {
//         cout << "Quantas palavras ira ler?" << endl;
//         cin >> n;
//     } while (n <= 0);
//     cin.ignore();

//     bool palindrome = true;
//     for (int i = 0; i < n; i++)
//     {
//         string palavra;
//         cout << "DIgite a palavra: " << endl;
//         getline(cin,palavra);

//         for(int j = 0, k = palavra.size() -1; j < palavra.size()/2; j++, k--){
//             if(palavra.at(i) != palavra.at(k)){
//                 palindrome = false; break;
//             }
//         }

//         if(palindrome){
//             cout << palavra << " é palindrome";
//         } else {
//             cout << palavra << " nao é palindrome";
//     }
//     }
    
    
    
//     return 0;
// }
