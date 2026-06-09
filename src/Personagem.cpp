#include "Personagem.hpp"

Personagem::Personagem(int vida, InventarioHabilidade inventarioHabilidade, std::string nome, InventarioItem inventarioItem)
    : Entidade(vida, nome, inventarioHabilidade), _inventario(inventarioItem), _vidaMaxima(vida){}

Habilidade Personagem::escolherHabilidade(int posicaoHabilidade){
    Habilidade habilidade = this->_inventarioHabilidade.getHabilidade(posicaoHabilidade);
    habilidade.mostrarDescricao();
    return habilidade;
}

Item Personagem::escolherItem(int posicaoItem){
    Item item = this->_inventario.getItem(posicaoItem);
    item.mostrarDescricao();
    this->_inventario.descartarAcao(posicaoItem);
    return item;
}

void Personagem::alterarVida(int valor){
    this->_vida += valor;
    if(this->_vida > this->_vidaMaxima){
        this->_vida = this->_vidaMaxima;
    }
}

bool Personagem::isMorto(){
    return this->_vida <= 0;
}

InventarioItem Personagem::getInventarioItem(){
    return this->_inventario;
}

Personagem::~Personagem(){}