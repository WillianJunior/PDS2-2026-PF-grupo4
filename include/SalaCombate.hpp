#ifndef SALACOMBATE_H
#define SALACOMBATE_H

#include "SalaBase.hpp"
#include <iostream>
#include <string>

class SalaCombate : public SalaBase{
    public:
        SalaCombate(std::string nome);
        void encerrarSala() override;
        void proximaSala() override;
        void mostrarSala() override;

        void controleDeTurnos();
        void alocarInimigo();
        
        
};

#endif