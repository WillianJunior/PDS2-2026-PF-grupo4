#ifndef SALACOMBATE_H
#define SALACOMBATE_H

#include "SalaBase.hpp"
#include <iostream>
#include <string>
using namespace std;

class SalaCombate : public SalaBase{
    public:
        SalaCombate(int nome);
        void encerrarSala() override;
        void proximaSala() override;
        void mostrarSala() override;

        void controleDeTurnos();
        void alocarInimigo();
        
        
};

#endif