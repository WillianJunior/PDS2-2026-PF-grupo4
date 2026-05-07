#ifndef SALABASE_H
#define SALABASE_H

#include <iostream>
#include <string>

class SalaBase{
    protected:
        std::string _nome;
        SalaBase(std::string nome);
    public:
        virtual void encerrarSala() = 0;
        virtual void proximaSala() = 0;
        virtual void mostrarSala() = 0;
        virtual ~SalaBase();
};

#endif