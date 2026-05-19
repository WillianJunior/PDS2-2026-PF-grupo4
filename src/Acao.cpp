#include "Acao.hpp"

Acao::Acao(std::string nome, bool tipo, int valor, Efeito efeito, bool alvo)
    : _nome(nome), _tipo(tipo), _valor(valor), _efeito(efeito), _alvo(alvo){}

int Acao::alterarVida(bool alvo, int valor){
    //retorna 0 apenas para dar como falha nos testes
    return 0;
}

int Acao::aplicarEfeito(bool alvo, Efeito efeito){
    //retorna 0 apenas para dar como falha nos testes
    return 0;
}

void Acao::mostrarHabilidade(){
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

Acao::~Acao(){
}