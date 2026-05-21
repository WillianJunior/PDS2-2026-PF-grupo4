#include "Item.hpp"

Item::Item(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo)
    : Acao(nome, tipo, valor, efeito, alvo){}

bool Item::operator==(const Item& outro) const{

return (this->_nome == outro._nome && 
            this->_tipo == outro._tipo && 
            this->_valor == outro._valor && 
            this->_efeito == outro._efeito && 
            this->_alvo == outro._alvo);
}

Item::~Item() {
}