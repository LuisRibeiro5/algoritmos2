#include <iostream>

struct Produto {
    int codigo;
    std::string nome;
    int qtde_estoque;
    double preco;
};

Produto registrar_produto();
void imprimir_relatorio(const Produto &p);

int main() {
    int quantidade;
    std::cout << "Digite a quantidade de produtos a ser registrada: ";
    std::cin >> quantidade;
    Produto *produtos = new Produto[quantidade];
    // alocar produtos

    // Registre os produtos
    for (int i = 0; i < quantidade; i++) {
        produtos[i] = registrar_produto();
        std::cout << "\n";
    }

    std::cout << "Relatório de Produtos\n";
    for (int i = 0; i < quantidade; i++) {
        imprimir_relatorio(*(produtos + i));
    }

    // desalocar produtos
    delete[] produtos;
    return 0;
}

Produto registrar_produto(){
    Produto p;
    std::cout << "Digite o codigo do produto: ";
    std::cin >> p.codigo;

    std::cout << "Nome: ";
    std::cin >> p.nome;

    std::cout << "qtde em estoque: ";
    std::cin >> p.qtde_estoque;

    std::cout << "preco: ";
    std::cin >> p.preco;

    return p;
};

void imprimir_relatorio(const Produto &p){
    double valor_total = p.qtde_estoque * p.preco;
    std::cout << "Código: " << p.codigo << " | Nome: " << p.nome << " | Quantidade: " << p.qtde_estoque << " | Preço: " << p.preco << " | Valor Total: " << valor_total << std::endl;
};
