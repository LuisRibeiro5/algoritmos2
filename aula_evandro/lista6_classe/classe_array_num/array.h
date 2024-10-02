#pragma once

class Array
{
private:
    double *array;
    int tam;

public:
    Array(/* args */);
    Array(int);
    ~Array();

    void inserir_num(int,double);
    double recuperar_num(int) const;
    double maior_num() const;
    double menor_num() const;
    double media_nuns() const;
};

