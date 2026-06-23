#include "Entidade.hpp"

Entidade::Entidade(int vida, std::string nome, InventarioHabilidade inventarioHabilidade)
    : _vida(vida), _nome(nome), _inventarioHabilidade(inventarioHabilidade){}

void Entidade::receberEfeito(Efeito novoEfeito){
    this->_efeitosAtivos.push_back(novoEfeito);
}

void Entidade::processarEfeitosAtivos(){
    for(int i = _efeitosAtivos.size() - 1; i >= 0; i--){
        this->alterarVida(_efeitosAtivos[i].getValor()); 
        _efeitosAtivos[i].mostrarEfeito(); 
        _efeitosAtivos[i].atualizarDuracao();
        if(_efeitosAtivos[i].isEncerrado()){
            _efeitosAtivos.erase(_efeitosAtivos.begin() + i);
        }
    }
}

void Entidade::limparEfeitos(){
    this->_efeitosAtivos.clear();
}

int Entidade::getVida(){
    return this->_vida;
}

std::string Entidade::getNome(){
    return this->_nome;
}

InventarioHabilidade& Entidade::getInventarioHabilidade(){
    return this->_inventarioHabilidade;
}

Entidade::~Entidade(){}