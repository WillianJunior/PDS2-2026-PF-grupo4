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

std::string Acao::mostrarDescricao(){
    std::string descricao = "";
    if(this->_tipo == false){
        descricao += "Causa " + std::to_string(this->_valor) + " de dano";
    }
    else{
        descricao += "Cura " + std::to_string(this->_valor) + " de vida";
    }

    if(this->_efeito.getNome() != "Nenhum" && this->_efeito.getNome() != "Vazio"){
        descricao += " e aplica " + this->_efeito.getNome();
    }

    return descricao += ".";
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