#include <iostream>

struct Refrigerante {
    std::string nome;
    double preco;
    int qtde;
};

void cadastraRefrigerante(Refrigerante &);
int recebeQtdeRefri();
void exibeRefrisDisponivel(Refrigerante[], int);
void compraRefrigerante(Refrigerante[],int);
int recebeCodigoDoRefri(int);
double recebeDinheiroPagamento();
bool temRefriDisponivel(Refrigerante&);
bool verificaPagamentoSuficiente(Refrigerante&, double);

int main(){
    int qtdeRefri = recebeQtdeRefri();
    Refrigerante refrigerantes[5] ={""};
    for(int i = 0; i < qtdeRefri; i++){
        cadastraRefrigerante(refrigerantes[i]);
    } 

    for(int i = 0; i < 5; i++){
        std::cout << "\nREFRIGERANTE " << i << " : \n";
        std::cout << "nome: " << refrigerantes[i].nome << "\n";
        std::cout << "preco: " << refrigerantes[i].preco << "\n";
        std::cout << "qtde: " << refrigerantes[i].qtde << "\n";
    }

    while(true){
        std::cout << "refrigerantes disponiveis: \n";
        exibeRefrisDisponivel(refrigerantes, qtdeRefri);

        
        break;
    }

    return 0;
}

void cadastraRefrigerante(Refrigerante& refri){
    std::cout << "digite as informacoes do refri a ser cadastrado: \n";
    do{
        std::cout << "nome: ";
        std::cin >> refri.nome;
    }while(refri.nome == "");
    
    do{
        std::cout << "preco unitario: ";
        std::cin >> refri.preco;
    }while(refri.preco <= 0);

    do{
        std::cout << "quantidade disponivel: ";
        std::cin >> refri.qtde;
    }while(refri.qtde < 0);
};

int recebeQtdeRefri(){
    int qtde;
    std::cout << "Digite a quantidade de refrigerantes a ser cadastrados: \n";
    do{
        std::cout << "Maximo a ser cadastrado é 5!\n";
        std::cout << "quantidade: ";
        std::cin >> qtde;
    }while(qtde <= 0);
    return qtde;
};

void exibeRefrisDisponivel(Refrigerante refris[], int tamanho){
    for(int i = 0; i < tamanho; i++ ){
        if(refris[i].qtde > 0){
            std::cout << [i] << "-" << refris[i].nome << " - " << refris[i].qtde << "\n";
        } else {
            std::cout << refris[i].nome << "- indisponivel.\n";
        }
    }
};

void compraRefrigerante(Refrigerante refris[],int refrisExistentes){
    int codigo = recebeCodigoDoRefri(refrisExistentes);
    double dinheiroPagamento = recebeDinheiroPagamento();

    bool temRefri = temRefriDisponivel(refris[codigo]);
    if(temRefri){
        bool pagamentoESuficiente = verificaPagamentoSuficiente(refris[codigo], dinheiroPagamento)
    }
   for(int i = 0; i < refrisExistentes; i++){
    if(i == codigo){
        if(refris[i].preco > dinheiroPagamento){
            std::cout << "Saldo insuficiente para comprar o refri!\n";
        }
    }
   }
    
};

int recebeCodigoDoRefri(int refrisExistentes){
    int codigo;
    std::cout << "===============================\n";
    std::cout << "insira o codigo do refrigerante que voce deseja comprar./n";
    do{
        std::cout << "digite o codigo, de 1 á " << refrisExistentes << ": "; 
        std::cin >> codigo;
    }while(codigo < 1 or codigo > refrisExistentes)

    return --codigo;
};

double recebeDinheiroPagamento(){
    double valor;
    std::cout << "Insira o valor para o pagamento: \n";
    do{
        std::cout << "insira um valor maior que 0: ";
        std::cin >> valor;
    }while(valor <= 0)

    return valor;
};

bool temRefriDisponivel(Refrigerante& refri){
    if(refri.qtde == 0){
        std::cout << "refrigerante indisponivel!\n";
        return false;
    }else{
        return true;
    }

}

bool verificaPagamentoSuficiente(Refrigerante&, double){
    
};
