#include <iostream>
#include <vector>

struct Livro {
    std::string titulo;
    std::string autor;
    std::string isbn;
    std::string status;
};

void cadastra_novo_livro(std::vector<Livro>&);
void listar_livros_disponiveis(const std::vector<Livro>&);
void emprestar_livro(std::vector<Livro>&);

int main(){
    std::vector<Livro> livros;
    int opcao;

    do{
        std::cout << "\nMenu:\n";
        std::cout << "1. cadastra novo livro.\n";
        std::cout << "2. Listar livros disponiveis.\n";
        std::cout << "3. Emprestar livro.\n";
        std::cout << "4. sair.\n";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao)
        {
        case 1:
            cadastra_novo_livro(livros);
            break;
        
        case 2:
            listar_livros_disponiveis(livros);
            break;

        case 3:
            emprestar_livro(livros);
            break;

        case 4: 
            std::cout << "saindo.";
        }
    }while (opcao != 4);

    return 0;
}

void cadastra_novo_livro(std::vector<Livro>& livros){
    Livro novo_livro;

    std::cout << "Digite os dados do novo livro:\n";

    std::cout << "Titulo: ";
    std::getline(std::cin,novo_livro.titulo);

    std::cout << "Autor: ";
    std::getline(std::cin,novo_livro.autor);
    
    std::cout << "ISBN: ";
    std::getline(std::cin,novo_livro.isbn);

    do
    {
        std::cout << "disponivel ou indisponivel? \n";
        std::cout << "Status: ";
        std::getline(std::cin,novo_livro.status);
        if(novo_livro.status != "disponivel" || novo_livro.status != "indisponivel"){
            std::cout << "O status deve ser examente escrito como: disponivel ou indisponivel\n";
        }
    } while (novo_livro.status != "disponivel" && novo_livro.status != "indisponivel");
    
    livros.push_back(novo_livro);
};

void listar_livros_disponiveis(const std::vector<Livro>& livros){
    for(auto& livro : livros){
        if(livro.status == "disponivel"){
            std::cout << livro.titulo << std::endl;
            std::cout << livro.autor << std::endl;
            std::cout << livro.isbn << std::endl;
        }
        std::cout << "\n";
    }
};

void emprestar_livro(std::vector<Livro>& livros){
    std::string titulo_emprestado;
    listar_livros_disponiveis(livros);
    std::cout << "digite o titulo do livro que gostaria de emprestar: ";
    std::getline(std::cin,titulo_emprestado);
    bool conseguiu_emprestar = false;

    for(auto& livro : livros){
        if(livro.titulo == titulo_emprestado){

            if(livro.status == "disponivel"){
                std::cout << "livro emprestado com sucesso!";
                livro.status = "indisponivel";
                conseguiu_emprestar = true;
                break; 
            }
        }
    }

    if(!conseguiu_emprestar){
        std::cout << "Livro nao encontrado.";
    }

};

