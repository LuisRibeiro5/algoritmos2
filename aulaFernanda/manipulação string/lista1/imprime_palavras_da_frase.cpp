/*Considere que uma frase tem no máximo 80 caracteres, cada palavra é separada por um espaço
em branco e finalizada com ponto final. Faça um algoritmo que leia várias frases e, para cada
uma imprima as palavras contidas nela e seu número de caracteres. Por exemplo, a partir da
frase “Vamos resolver exercícios.”, o resultado será:
“Vamos resolver exercícios.”
Vamos 5 resolver 8 exercícios 10*/

#include <iostream>
#include <cstring>
#include <cctype>
#include <vector>

int main(int argc, char const *argv[])
{
    std::string frase;
    int numberOfSenteces;
    std::vector<std::string> frases;

    std::cout << "How many sentences do you want write? : ";
    std::cin >> numberOfSenteces;
    std::cin.ignore();
    for (int i = 0; i < numberOfSenteces; i++)
    {
        std::cout << "Write a sentence e finish with '.' -" << i + 1 << "\n";
        std::getline(std::cin, frase);
        frases.push_back(frase);
    }

    for (unsigned int i = 0; i < frases.size(); i++)
    {
        frase = frases.at(i);

        int cont = 0;
        for (auto it = frase.begin(); it != frase.end(); ++it)
        {
            cont++;
            if (*it == ' ' || *it == '.')
            {
                std::cout << " " << cont - 1;
                cont = 0;
            };
            if (*it == '.')
                break;
            std::cout << *it << "";
        }

        std::cout << "\n";
    }

    return 0;
}

/*using namespace std; // exercicio 1 DA PROFESSORA
int main()
{
    int cont = 0;
    string frase;
    char letra;
    do
    {
        do
        {
            cout << "Informe a frase (finalize com .): ";
            getline(cin, frase);
        } while (frase == "" or frase[frase.size() - 1] != '.'); // vazia e sem . fim
        cout << frase << endl;
        for (unsigned int i = 0; i < frase.size(); i++)
        {
            letra = frase.at(i);
            if (letra != ' ' and letra != '.')
            {
                cout << letra;
                cont++;
            }
            else
            {
                cout << " " << cont << "\t";
                cont = 0;
            }
        }
        cout << "\nMais uma? S/N" << endl;
        cin.get(letra); // fazer validacao de entrada, S ou N
        cin.ignore();
    } while (toupper(letra) == 'S');
    return 0;
}*/