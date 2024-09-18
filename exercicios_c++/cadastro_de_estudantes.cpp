#include <iostream>
#include <vector>

struct Estudante
{
    std::string nome;
    int idade;
    std::string matricula;
    std::vector<double> notas;
};

Estudante cadastra_novo_estudante();
void mostra_Estudantes(Estudante &aluno);
void mostra_media_aluno(const std::vector<Estudante>&, std::string);


int main(){
    std::vector<Estudante> Estudantes;
    int opcao;

    do{
        std::string matricula_busca;
        std::cout << "escolha uma opcao: \n";
        std::cout << "opcao 1: cadastra novo estudante.\n";
        std::cout << "opcao 2: mostra estudantes cadastrados.\n";
        std::cout << "opcao 3: mostrar media de um estudante.\n";
        std::cout << "opcao 4: sair.\n";
        std::cin >> opcao;
        std::cin.ignore();
        switch (opcao)
        {
        case 1:
            Estudantes.push_back(cadastra_novo_estudante());
            break;
        
        case 2:
            for(auto& aluno : Estudantes){
            mostra_Estudantes(aluno);
            }
            break;

        case 3:
            std::cout << "Digite a matricula do aluno que deseja ver a media das notas: ";
            std::cin >> matricula_busca;
            mostra_media_aluno(Estudantes,matricula_busca);
            break;
        
        case 4:
            std::cout << "Programa finalizado\n";
            break;
        
        default:
            std::cout << "Opcao invalida.\n";
            break;
        }
    }while(opcao != 4);

    return 0;
}

Estudante cadastra_novo_estudante(){
    Estudante aluno;
    do
    {
        std::cout << "Digite o nome do aluno: ";
        std::getline(std::cin,aluno.nome);
    } while (aluno.nome == "" || aluno.nome == " ");

    do
    {
        std::cout << "Digite a idade do aluno: ";
        std::cin >> aluno.idade;
    } while (aluno.idade < 5 || aluno.idade > 21);
    std::cin.ignore();
    do
    {
        std::cout << "Digite a matricula do aluno: ";
        std::cin.ignore();
        std::getline(std::cin,aluno.matricula);
    } while (aluno.matricula == "" || aluno.matricula == " ");

    int cont;
    std::cout << "Quantas notas o aluno teve? \n";
    std::cin >> cont;
    aluno.notas.resize(cont);
    for (int i = 0; i < cont; i++)
    {
        std::cout << "Nota " << i + 1 << " :";
        std::cin >> aluno.notas[i];
    }
    
    std::cin.ignore();
    return aluno;
}

void mostra_Estudantes(Estudante &aluno){
    std::cout <<"Nome:"<< aluno.nome << "\n";
    std::cout << aluno.idade << "\n";
    std::cout << aluno.matricula << "\n";
    for(double nota : aluno.notas){
        std::cout << "Nota" << nota << "\n";
    }

    
};

void mostra_media_aluno(const std::vector<Estudante>& Estudantes,std::string matricula){
    double media = 0;
    for(auto& aluno : Estudantes){
        if(aluno.matricula == matricula){
             
            for(int i = 0; i < aluno.notas.size(); i++){
                media += aluno.notas[i];
            }
            media /= aluno.notas.size();

            std::cout << "Media do aluno " << matricula << ": " << media;
            break;
        }
    }
    std::cout << "Aluno nao encontrado.\n";
};
