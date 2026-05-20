#include "Inimigo.hpp"

Inimigo::Inimigo(int vida, InventarioHabilidade habilidade, std::string nome, bool tipo)
    : Entidade(vida, nome, habilidade), tipo(tipo){}


int Inimigo::escolherHabilidade(int posicaoHabilidade){
    //retorna 0 apenas para dar como falha nos testes
    return 0;
}

void Inimigo::alterarVida(int valor){
}

bool Inimigo::isMorto(){
    //retorna false apenas para dar como falha nos testes
    return false;
}

bool Inimigo::getTipo(){
    return this->tipo;
}

Inimigo::~Inimigo(){
}