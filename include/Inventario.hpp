#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>

class Inventario{
    public:
        virtual void mostrarInventario() = 0;
        virtual void novaAcao() = 0;
        virtual void trocarAcao() = 0;
        virtual void descartarAcao() = 0;
};

#endif