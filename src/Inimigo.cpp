#include "Inimigo.hpp"

Inimigo::Inimigo(int vida, InventarioHabilidade habilidade, std::string nome, bool tipo)
    : Entidade(vida, nome, habilidade), tipo(tipo), _vidaMaxima(vida){}

Habilidade Inimigo::escolherHabilidade(int posicaoHabilidade){
    Habilidade habilidade = this->_inventarioHabilidade.getHabilidade(posicaoHabilidade);
    habilidade.mostrarDescricao();
    return habilidade;
}

void Inimigo::alterarVida(int valor){
    this->_vida += valor;
    if(this->_vida > this->_vidaMaxima){
        this->_vida = this->_vidaMaxima;
    }
}

bool Inimigo::isMorto(){
    return this->_vida <= 0;
}

bool Inimigo::getTipo(){
    return this->tipo;
}

Inimigo::~Inimigo(){}