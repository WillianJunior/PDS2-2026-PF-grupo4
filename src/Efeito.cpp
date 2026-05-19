#include "Efeito.hpp"

Efeito::Efeito(std::string nome, int valor, int duracao)
    : _nome(nome), _valor(valor), _duracao(duracao){}

void Efeito::aplicarEfeito(){
}

void Efeito::atualizarDuracao(){
}

bool Efeito::isEncerrado(){
    //retorna false apenas para dar como falha nos testes
    return false;
}

Efeito::~Efeito(){
}