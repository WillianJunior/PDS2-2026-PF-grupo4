#include "Acao.hpp"
#include <fstream>
#include <sstream>

Acao::Acao(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo)
    : _nome(nome), _tipo(tipo), _valor(valor), _efeito(efeito), _alvo(alvo){}

int Acao::calcularImpacto(){
    if(this->_tipo == false){
        //causa dano
        return -this->_valor;
    }else{
        //cura
        return this->_valor;
    }
}

void Acao::mostrarDescricao(){
}

int aplicarEfeito(bool alvo, Efeito efeito){
    return 0;
}

std::string Acao::getNome(){
    return this->_nome;
}

bool Acao::getTipo(){
    return this->_tipo;
}

int Acao::getValor(){
    return this->_valor;
}

bool Acao::getAlvo(){
    return this->_alvo;
}

Efeito Acao::getEfeito(){
    return this->_efeito;
}

Acao::~Acao(){}