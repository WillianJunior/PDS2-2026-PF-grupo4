#include "Entidade.hpp"

Entidade::Entidade(int vida, std::string nome, InventarioHabilidade inventarioHabilidade)
    : _vida(vida), _nome(nome), _inventarioHabilidade(inventarioHabilidade){}

int Entidade::getVida(){
    return this->_vida;
}

std::string Entidade::getNome(){
    return this->_nome;
}

InventarioHabilidade Entidade::getInventarioHabilidade(){
    return this->_inventarioHabilidade;
}

Entidade::~Entidade(){}