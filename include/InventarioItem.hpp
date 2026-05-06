#ifndef INVENTARIOITEM_H
#define INVENTARIOITEM_H

#include "Inventario.hpp"
#include "Item.hpp"

class InventarioItem : public Inventario{
    public:
        vector<Item> _itens;
        void mostrarInventario();
        void novoItem();
        void trocarItem();
        void descartarItem();
};

#endif