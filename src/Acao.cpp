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

Acao::~Acao(){
}