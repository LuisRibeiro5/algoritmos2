#include <iostream>

struct Produto
    {
        int codigo;
        std::string nome;
        int quantidade_estoque;
        double preco_unit;
    };
void pegar_dados_produto(Produto&);
void mostra_produto(const Produto&);

int main(){
    
    
    Produto produtos[5];
    for(auto &produto : produtos){
        pegar_dados_produto(produto);
    }

    for(auto &produto : produtos){
        mostra_produto(produto);
    }
    
    return 0;
}

void pegar_dados_produto(Produto &p){
    std::cout << "Insira o codigo do produto: \n";
    do
    {
        std::cout << "codigo:";
        std::cin >> p.codigo;
        if (p.codigo < 0)
        {
            std::cout << "valor invalido insira novamente!\n";
        }
        
    } while (p.codigo < 0);
    

    std::cout << "Insira o nome do produto: \n";
    do
    {
        std::cout << "nome:";
        std::cin >> p.nome;
        if (p.nome == "")
        {
            std::cout << "insira nome valido!\n";
        }
        
    } while (p.nome == "");
    
    std::cout << "Insira quantidade em estoque do produto: \n";
    do
    {
        std::cout << "quantidade em estoque: ";
        std::cin >> p.quantidade_estoque;
        if (p.quantidade_estoque < 0)
        {
            std::cout << "valor inválido, insira novamente.\n";
        }
        
    } while (p.quantidade_estoque < 0);

    std::cout << "Insira o preço unitário do produto: \n";
    do
    {
        std::cout << "Preco unitario:";
        std::cin >> p.preco_unit;
        if (p.preco_unit < 0)
        {
            std::cout << "valor invalido, insira novamente.\n";
        }
        
    } while (p.preco_unit < 0);
        
}

void mostra_produto(const Produto &p){
    std::cout << " -" <<  p.codigo << "\n";
    std::cout << " -" <<  p.nome << "\n";
    std::cout << " -" <<  p.preco_unit << "\n";
    std::cout << " -" <<  p.quantidade_estoque<< "\n";
}