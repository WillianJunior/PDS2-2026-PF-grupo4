#include "Personagem.hpp"

Personagem::Personagem(int vida, InventarioHabilidade inventarioHabilidade, std::string nome, InventarioItem inventarioItem)
    : Entidade(vida, nome, inventarioHabilidade), _inventario(inventarioItem), _vidaMaxima(vida) {}

int Personagem::escolherHabilidade(int posicaoHabilidade){
    Habilidade habilidade = this->_inventarioHabilidade.getHabilidade(posicaoHabilidade);
    habilidade.mostrarHabilidade();
    return habilidade.getValor();
}

int Personagem::escolherItem(int posicaoItem){
    Item item = this->_inventario.getItem(posicaoItem);
    int valorItem = item.getValor();
    this->_inventario.descartarAcao(posicaoItem);
    return valorItem;
}

void Personagem::alterarVida(int valor){
    this->_vida += valor;
    if(this->_vida > this->_vidaMaxima)
        this->_vida = this->_vidaMaxima;
}

bool Personagem::isMorto(){
    return this->_vida <= 0;
}

InventarioItem Personagem::getInventarioItem(){
    return this->_inventario;
}

Personagem::~Personagem(){
}