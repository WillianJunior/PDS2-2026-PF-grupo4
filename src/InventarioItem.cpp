#include "InventarioItem.hpp"

void InventarioItem::mostrarInventario(){
}

void InventarioItem::novaAcao(Item item){
}

void InventarioItem::trocarAcao(int posicao, Item novoItem){
}

void InventarioItem::descartarAcao(int posicao){
}

int InventarioItem::getTamanho(){
    return _itens.size();
}

Item InventarioItem::getItem(int posicao){
    return _itens[posicao];
}