#include "Habilidade.hpp"

Habilidade::Habilidade(std::string nome, bool tipo, int valor, bool alvo, Efeito efeito)
    : Acao(nome, tipo, valor, efeito, alvo){}

bool Habilidade::operator==(const Habilidade& outro) const{

return (this->_nome == outro._nome && 
            this->_tipo == outro._tipo && 
            this->_valor == outro._valor && 
            this->_alvo == outro._alvo && 
            this->_efeito == outro._efeito);
}

Habilidade::~Habilidade(){
}