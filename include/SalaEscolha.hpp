#ifndef SALAESCOLHA_H
#define SALAESCOLHA_H

#include "SalaBase.hpp"
#include <iostream>
#include <string>
using namespace std;

class SalaEscolha : public SalaBase{
    public:
        SalaEscolha(int nome);
        void encerrarSala() override;
        void proximaSala() override;
        void mostrarSala() override;

        void mostrarOpçoes();
        void executarEvento();
};

#endif