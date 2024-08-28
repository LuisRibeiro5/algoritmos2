/*Dado uma string A e um número n, retorne uma string B que consiste na reprodução de A n
vezes. Por exemplo, se A = “tchau” e n = 2 então B = “tchau tchau”*/
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{
    string frase;
    int n;

    do
    {
        cout << "Digite uma frase: ";
        getline(cin, frase);
        cout << "Digite um numero: ";
        cin >> n;
    } while (frase == "" || n < 1);

    string fraseB = "";
    for (int i = 0; i < n; i++)
    {
        fraseB += (frase + " ");
    }

    cout << fraseB;

    return 0;
}