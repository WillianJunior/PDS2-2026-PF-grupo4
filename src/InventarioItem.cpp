#include "InventarioItem.hpp"
#include "Excecoes.hpp"

void InventarioItem::mostrarInventario(){
    for (long unsigned int i = 0; i < _itens.size(); i++)
    {
        Utils::coutDigitado(15) << std::to_string(i+1) << ". "<< _itens[i].getNome() << "\n";
    }
}

void InventarioItem::novaAcao(Item item){
    this->_itens.push_back(item);
}

void InventarioItem::trocarAcao(int posicao, Item novoItem){
    _itens[posicao] = novoItem;
}

void InventarioItem::descartarAcao(int posicao){
    _itens.erase(_itens.begin() + posicao);
}

int InventarioItem::getTamanho(){
    return _itens.size();
}

Item InventarioItem::getItem(int posicao){
    if (posicao < 0 || posicao >= (int)_itens.size()){
        throw IndiceInvalidoException();
    }
    return _itens[posicao];
}

bool InventarioItem::operator==(const InventarioItem& outro) const{
    return (this->_itens == outro._itens);
}

bool InventarioItem::operator!=(const InventarioItem& outro) const{
    return (this->_itens != outro._itens);
}