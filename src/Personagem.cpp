#include "Personagem.hpp"

Personagem::Personagem(int vida, InventarioHabilidade inventarioHabilidade, std::string nome, InventarioItem inventarioItem)
    : Entidade(vida, nome, inventarioHabilidade), _inventario(inventarioItem){}

int Personagem::escolherHabilidade(int posicaoHabilidade){
    //retorna 0 apenas para dar como falha nos testes
    return 0;
}

void Personagem::escolherItem(int posicaoItem){
}

void Personagem::alterarVida(int valor){
}

bool Personagem::isMorto(){
    //retorna false apenas para dar como falha nos testes
    return false;
}

InventarioItem Personagem::getInventarioItem(){
    return this->_inventario;
}

Personagem::~Personagem(){
}