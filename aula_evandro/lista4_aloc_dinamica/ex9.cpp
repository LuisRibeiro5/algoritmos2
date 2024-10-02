#include <iostream>

struct Aluno {
    std::string nome;
    double *notas = nullptr;
    double media;
};

void recebe_qtdes(int&,int&);
void recebe_dados_aluno(Aluno&, int);
void coloca_media(Aluno &, int);


int main(){
    int qtde_alunos, notas;
    recebe_qtdes(qtde_alunos,notas);

    Aluno *alunos = new Aluno[qtde_alunos];

    for (int i = 0; i < qtde_alunos; i++)
    {
        
        recebe_dados_aluno(alunos[i], notas);
        coloca_media(alunos[i],notas);
    }
    
    for (int i = 0; i < qtde_alunos; i++)
    {
        std::cout << "\nNome: " << alunos[i].nome << " - Media: " << alunos[i].media;
    }

    for (int i = 0; i < qtde_alunos; i++)
    {
        delete[] alunos[i].notas;
    }
    
    delete[] alunos;
    return 0;
}

void recebe_qtdes(int &alunos, int &notas){
        
    std::cin.ignore();
    do
    {
        std::cout << "qtde alunos: ";
        std::cin >> alunos;
    } while (alunos < 1);
    
    do
    {
        std::cout << "qtde notas: ";
        std::cin >> notas;
    } while (notas < 1);
    
};


void recebe_dados_aluno(Aluno &a, int qtde){
    std::cout << "\nNome:";
    std::getline(std::cin,a.nome);

    double *arr_notas = new double[qtde];

    for (int i = 0; i < qtde; i++)
    {
        do
        {
            std::cout << "\nNota " << i + 1;
            std::cin >> arr_notas[i];
        } while (arr_notas[i] < 0);
        
    }
    
    a.notas = arr_notas;
};

void coloca_media(Aluno &a, int qtde){
    double soma = 0;
    for (int i = 0; i < qtde; i++)
    {
        soma += a.notas[i];
    }
    
    a.media = soma / qtde;
}
