#pragma once

class Estoque {
    private:
        int codigo;
        int qtde;
        double custo_unit;
        double custo_tot;

    public:
        Estoque();
        Estoque(int,int,double);

        void definir_codigo_item(int);
        void definir_quantidade(int);
        void definir_custo(double);
        void definir_custo_total();

        int obter_codigo_item();
        int obter_quantidade();
        double obter_custo();
        double obter_custo_total();
};