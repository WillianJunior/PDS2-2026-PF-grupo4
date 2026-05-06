#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Inventario{
    public:
        virtual void mostrarInventario() = 0;
        virtual void novoItem() = 0;
        virtual void trocarItem() = 0;
        virtual void descartarItem() = 0;
};

#endif