#include "Item.hpp"

Item::Item(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo, int usos)
    : Acao(nome, tipo, valor, efeito, alvo), _usosRestantes(usos){}

void Item::atualizarUsos(){
    if(this->_usosRestantes > 0){
        this->_usosRestantes--;
    }
}

int Item::getUsosRestantes(){
    return this->_usosRestantes;
}

bool Item::operator==(const Item& outro) const{

return (this->_nome == outro._nome && 
            this->_tipo == outro._tipo && 
            this->_valor == outro._valor && 
            this->_efeito == outro._efeito && 
            this->_alvo == outro._alvo);
}

Item::~Item() {
}