#ifndef INVENTARIOITEM_H
#define INVENTARIOITEM_H

#include "Inventario.hpp"
#include "Item.hpp"

class InventarioItem : public Inventario{
    private:
        std::vector<Item> _itens;
    public:
        void mostrarInventario() override;
        void novaAcao() override;
        void trocarAcao() override;
        void descartarAcao() override;
};

#endif