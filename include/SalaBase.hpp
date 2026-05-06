#ifndef SALABASE_H
#define SALABASE_H

#include <iostream>
#include <string>
using namespace std;

class SalaBase{
    protected:
        string _nome;
        SalaBase(string nome);
        virtual void encerrarSala() = 0;
        virtual void proximaSala() = 0;
        virtual void mostrarSala() = 0;
        virtual ~SalaBase();
};

#endif