#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Item.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

using namespace std;

class Inventario{
    public:
        vector<Item> _lista_de_itens;
        void mostrarInventario();
        void novoItem();
        void trocarItem();
        void descartarItem();
};

#endif