#include "data.h"
#include <string>

Data::Data(int v_dia, int v_mes, int v_ano)
    : dia{v_dia}, mes{v_mes}, ano{v_ano}
{}

Data::Data()
    : dia{0}, mes{0}, ano{0}
{}

std::string Data::data_padrao(){
    std::string dia_str = std::to_string(dia);
    std::string mes_str = std::to_string(mes);
    std::string ano_str = std::to_string(ano);

    return dia_str + "/" + mes_str + "/" + ano_str;
}

std::string Data::data_extenso(){
    std::string meses[12] = {"janeiro","fevereiro","marco","abril","maio","junho","julho","agosto","setembro","outubro","novembro","desembro"};

    std::string data = std::to_string(dia) + " de " + meses[mes - 1] + " de " + std::to_string(ano);
    return data;
}